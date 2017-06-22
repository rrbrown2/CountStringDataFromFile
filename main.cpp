
/*
Counts the number of spaces, punctuation marks, digits, lines of text, and sentences in a file.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ifstream file_reader; // Object to read file
ofstream outputfile;
string lines;

//File stats
int char_count = 0, punctuation_count = 0, word_count = 0, num_count = 0; // initialize variables to contain counts of types
int sentences = 0, spaces = 0, number_of_lines = 0;
char current_char;
bool prev_was_num = false;

int main() {
    file_reader.open("read.txt"); // open the read file
    outputfile.open("write.txt"); // open the write file
    if(file_reader.is_open()) {

        while (getline(file_reader, lines)) // Looping on every line in the file
        {
            number_of_lines++;
            word_count++;


            for (int j = 0; j < lines.length(); j++) { // Looping through characters of current line
                current_char = lines.at(j); // Getting current character
                if (('A' <= current_char && current_char <= 'Z') || ('a' <= current_char && current_char <= 'z')) {
                    // Checking if char is a letter using ascii values
                    char_count++; // Incrementing characters count
                    prev_was_num = false;
                }
                else if ('0' <= current_char && current_char <= '9') {
                    //Checking if char is a number using ascii values
                    while(current_char != ' '){
                        j++;
                        current_char = lines.at(j);
                    }
                    num_count++; // Incrementing numbers count
                    spaces++;
                    prev_was_num = true;
                }
                else if (current_char == ' '){
                    spaces++; // Incrementing punctuation count if not letter or number
                    if(!prev_was_num){
                        word_count++; // incrementing count of words
                    }
                }
                else {
                    punctuation_count++;
                    if(current_char == '.' || current_char == '!' || current_char == '?'){
                        sentences++;
                    }
                    prev_was_num = false;
                }
            }

        }
        file_reader.close(); // close file


    }

// Printing stats of file
    outputfile << "Output:\n\n";
    outputfile << "Sentence\t\t  Spaces\tPunctuation\t   numbers\twords\tline count\n";
    outputfile << setw(1) << sentences;
    outputfile << setw(29)<< spaces;
    outputfile << setw(15)<< punctuation_count;
    outputfile << setw(17)<< num_count;
    outputfile << setw(13)<< word_count;
    outputfile << setw(11)<< number_of_lines;
    outputfile.close(); // closes outputfile
    return 0;

}
