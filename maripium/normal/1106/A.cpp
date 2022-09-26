#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; 
	cin >> n;
	vector<string> board(n);
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}
	int cnt = 0;
	for (int i = 1; i + 1 < n; ++i) {
		for (int j = 1; j + 1 < n; ++j) {
			if (board[i][j] == '.') continue;
			if (board[i - 1][j - 1] == '.') continue;
			if (board[i - 1][j + 1] == '.') continue;
			if (board[i + 1][j - 1] == '.') continue;
			if (board[i + 1][j + 1] == '.') continue;
			++cnt;
		}
	}
	cout << cnt << '\n';
}