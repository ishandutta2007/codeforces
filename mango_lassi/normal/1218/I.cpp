#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 2000;
int board[N][N];
bool flip_row[N];
bool flip_col[N];
int bar[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// "the magical bar" just xors the bits
	// -> Can take xor of input and output, must make it all zeroes
	for (int y = 0; y < n; ++y) {
		string str;
		cin >> str;
		for (int x = 0; x < n; ++x) {
			if (str[x] == '1') board[y][x] ^= 1;
		}
	}
	for (int y = 0; y < n; ++y) {
		string str;
		cin >> str;
		for (int x = 0; x < n; ++x) {
			if (str[x] == '1') board[y][x] ^= 1;
		}
	}

	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '1') bar[i] ^= 1;
	}

	// If the bar has zero at x and one at y, and board[y][x] = 1, we must flip column x, and vice versa.
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (board[y][x]) {
				if (! bar[y]) flip_row[y] = true;
				else if (! bar[x]) flip_col[x] = true;
			}
		}
	}
	
	// Now, assuming we have not failed, we may think that the bar has only ones.
	// We must make the last row with a 1 into all zeroes, so let's do that
	int y0 = 0;
	for (y0 = 0; y0 < n; ++y0) {
		if (! bar[y0]) continue;
		for (int x = 0; x < n; ++x) {
			if (bar[x] && board[y0][x]) {
				flip_col[x] = true;
			}
		}
		break;
	}
	for (int y = y0 + 1; y < n; ++y) {
		if (! bar[y]) continue;
		for (int x = 0; x < n; ++x) {
			if (bar[x] && (board[y][x] ^ flip_col[x])) flip_row[y] = true;
		}
	}
	
	bool fail = false;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (flip_row[y]) board[y][x] ^= bar[x];
			if (flip_col[x]) board[y][x] ^= bar[y];
			if (board[y][x] == 1) fail = true;
		}
	}

	if (fail) {
		cout << "-1\n";
	} else {
		int cou = 0;
		for (int i = 0; i < n; ++i) cou += flip_row[i] + flip_col[i];
		cout << cou << '\n';
		for (int x = 0; x < n; ++x) {
			if (flip_col[x]) cout << "col " << x << '\n';
		}
		for (int y = 0; y < n; ++y) {
			if (flip_row[y]) cout << "row " << y << '\n';
		}
	}
}