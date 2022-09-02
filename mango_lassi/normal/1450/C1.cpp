#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<string> board(n);
	vector<int> cou(3);
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'X') ++cou[(i + j) % 3];
		}
	}
	
	int t = 0;
	if (cou[1] < cou[t]) t = 1;
	if (cou[2] < cou[t]) t = 2;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'X' && (t == (i + j) % 3)) board[i][j] ^= 'X' ^ 'O';
		}
		cout << board[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}