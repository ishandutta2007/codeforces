#include <iostream>
#include <string>
#include <cctype>

std::string word;
int low, high;

int main() {
	std::cin >> word;
	for(int i = 0; i < word.length(); i++) {
		if(word[i] >= 'a' && word[i] <= 'z')
			low++;
		else
			high++;
	}
	if(low >= high)
		for(int i = 0; i < word.length(); i++)
			word[i] = tolower(word[i]);
	else
		for(int i = 0; i < word.length(); i++)
			word[i] = toupper(word[i]);
	std::cout << word;
}