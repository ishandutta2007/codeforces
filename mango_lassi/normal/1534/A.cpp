#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int h, w;
	cin >> h >> w;

	vector<bool> red(2, 0), white(2, 0);
	for (int y = 0; y < h; ++y) {
		string str;
		cin >> str;
		for (int x = 0; x < w; ++x) {
			if (str[x] == 'R') red[(x + y) & 1] = 1;
			if (str[x] == 'W') white[(x + y) & 1] = 1;
		}
	}

	if ((red[0] && white[0]) || (red[1] && white[1]) || (red[0] && red[1]) || (white[0] && white[1])) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		if (! red[0] && ! red[1]) {
			if (white[0]) red[1] = 1;
			else red[0] = 1;
		}
		if (! white[0] && ! white[1]) {
			if (red[0]) white[1] = 1;
			else white[0] = 1;
		}

		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (red[(x + y) & 1]) cout << 'R';
				else cout << 'W';
			}
			cout << '\n';
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}