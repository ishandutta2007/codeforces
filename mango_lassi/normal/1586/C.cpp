#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int h, w;
	cin >> h >> w;

	vector<string> arr(h);
	for (int y = 0; y < h; ++y) cin >> arr[y];

	vector<int> nxt(w, w);
	for (int x = w - 2; x >= 0; --x) {
		for (int y = 1; y < h; ++y) {
			if (arr[y][x] == 'X' && arr[y-1][x+1] == 'X') nxt[x] = x + 1;
		}
		nxt[x] = min(nxt[x], nxt[x + 1]);
	}

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (nxt[a] <= b) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}