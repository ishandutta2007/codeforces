#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int C = 17;
bool states[1<<C]; // True if state doesn't work
bool reach[1<<C]; // True if state is reachable
int works[C][C];
vector<bool> tmp[C+1];
int count[C];

void check(int i, int p, int must, int mask) {
	int cs = 1<<(p-i);

	// cerr << "check(" << i << ' ' << p << ' ' << must << ' ' << mask << "): ";
	// for (int j = 0; j < cs; ++j) cerr << tmp[i][j] ? "1" : "0"; cerr << '\n';

	if (i == p) {
		if (tmp[i][0]) {
			// cerr << "must " << must << " eliminates " << mask << '\n';
			states[mask] = true;
		}
	} else {
		// Assign to 1
		for (int j = 0; j < cs; ++j) {
			if (tmp[i][j] && (! (j & 1))) {
				tmp[i+1][j>>1] = true;
			}
		}
		check(i+1, p, must, mask | (1<<i));

		// Assign to 0
		if (! (must & (1<<i))) {
			for (int j = 0; j < cs; ++j) {
				if (tmp[i][j]) {
					tmp[i+1][j>>1] = true;
				}
			}
			check(i+1, p, must, mask);
		}
	}
	for (int j = 0; j < cs; ++j) tmp[i][j] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	string orig_str;
	cin >> orig_str;

	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		seq[i] = (int)(orig_str[i] - 'a');
		++count[seq[i]];
	}

	for (int y = 0; y < p; ++y) {
		for (int x = 0; x < p; ++x) {
			cin >> works[y][x];
		}
	}

	for (int i = 0; i <= p; ++i) tmp[i].resize(1<<(p-i), false);

	for (int a = 0; a < p; ++a) {
		for (int b = 0; b < p; ++b) {
			if (works[a][b]) continue;

			vector<int> needs;
			int mask = 0;
			int pre = -1;
			for (int i = 0; i < n; ++i) {
				if (seq[i] == a) {
					if (pre == b) tmp[0][mask] = true;
					pre = a;
					mask = 0;
				} else if (seq[i] == b) {
					if (pre == a) tmp[0][mask] = true;
					pre = b;
					mask = 0;
				} else {
					mask |= (1<<seq[i]);
				}
			}
			int must = (1<<a) | (1<<b);
			check(0, p, must, 0);
		}
	}

	int res = n;

	reach[(1<<p)-1] = true;
	for (int mask = (1<<p)-1; mask >= 0; --mask) {
		if (states[mask] || (!reach[mask])) continue;

		int offer = 0;
		for (int j = 0; j < p; ++j) {
			if (mask & (1<<j)) {
				offer += count[j];
				int t = mask ^ (1<<j);
				if (! states[t]) reach[t] = true;
			}
		}
		res = min(res, offer);
	}
	cout << res << '\n';
	
}