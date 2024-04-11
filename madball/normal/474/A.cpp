#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const string board = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main() {
	char off;
	cin >> off;
	char inp;
	while (true) {
		inp = ' ';
		cin >> inp;
		int i;
		for (i = 0; i <= board.length(); i++)
			if (i == board.length() ? true : board[i] == inp)
				break;
		if (i == board.length())
			break;

		if (off == 'R')
			i--;
		else
			i++;
		cout << board[i];
	}
	cout << '\n';
	return 0;
}