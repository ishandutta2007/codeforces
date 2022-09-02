#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<string> board(n);
	vector<int> cou0(3, 0), cou1(3, 0);
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'O') ++cou0[(i + j) % 3];
			if (board[i][j] == 'X') ++cou1[(i + j) % 3];
		}
	}
	
	int t = 0;
	if (cou0[1] + cou1[2] < cou0[t] + cou1[(t + 1) % 3]) t = 1;
	if (cou0[2] + cou1[0] < cou0[t] + cou1[(t + 1) % 3]) t = 2;

	// no O are allowed when x + y == t (mod 3)
	// no X are allowed when x + y == t + 1 (mod 3)

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'O' && (((i + j) % 3) == t)) board[i][j] ^= 'X' ^ 'O';
			if (board[i][j] == 'X' && (((i + j) % 3) == ((t + 1) % 3))) board[i][j] ^= 'X' ^ 'O';
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