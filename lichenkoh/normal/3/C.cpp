#include <iostream>
#include <assert.h>

using namespace std;

#define NONE '\0'

bool scanwin(char **m, char c) {
	if (c == m[0][0] && m[0][0] == m[1][1] && m[1][1] == m[2][2]) return true;
	if (c == m[2][0] && m[2][0] == m[1][1] && m[1][1] == m[0][2]) return true;
	for (int i = 0; i < 3; i++) {
		if (c == m[i][0] && m[i][0] == m[i][1] && m[i][1] == m[i][2]) return true;
		if (c == m[0][i] && m[0][i] == m[1][i] && m[1][i] == m[2][i]) return true;
	}
	return false;
}

/*
char scanwin(char **m) {
	if (m[0][0] == m[1][1] && m[1][1] == m[2][2]) return m[0][0];
	if (m[2][0] == m[1][1] && m[1][1] == m[0][2]) return m[2][0];
	for (int i = 0; i < 3; i++) {
		if (m[i][0] == m[i][1] && m[i][1] == m[i][2]) return m[i][0];
		if (m[0][i] == m[1][i] && m[1][i] == m[2][i]) return m[0][i];
	}
	return NONE;
}
*/

int count(char **m, char c) {
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (m[i][j] == c) {
				ans++;
			}
		}
	}
	return ans;
}


string calc(char **m) {
	//Check for illegal position first. Must do this before checking draw.
	int countX = count(m,'X');
	int countO = count(m,'0');
	if (countO > countX) return "illegal";
	// cout<< countX << countO << endl;
	if (countX >= countO+2) return "illegal";
	char turn;
	if (countX == countO + 1) turn = '0';
	else if (countX == countO) turn = 'X';
	else return "illegal";
	bool winX = scanwin(m,'X');
	bool winO = scanwin(m,'0');
	if (winX && winO) return "illegal";
	char win = '?';
	if (winX) win = 'X';
	if (winO) win = '0';
	// Illegal if a player won already and still plays
	if (win == turn) return "illegal";
	if (winX) return "the first player won";
	if (winO) return "the second player won";
	if (countX + countO == 9) return "draw";
	if (turn == 'X') return "first";
	if (turn == '0') return "second";
	assert(false);
	return "error";

}

int main() {
	char **m = new char*[3];
	for (int i = 0; i < 3; i++) {
		m[i] = new char[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m[i][j];
		}
	}
	string ans = calc(m);
	cout << ans << endl;
}