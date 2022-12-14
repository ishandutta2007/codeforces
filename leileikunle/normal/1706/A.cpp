#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;

struct node {
	const static int N = 1e5 + 10;
	char a[N];
	int n, m;
	void solve() {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) a[i] = 'B';
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			int mi = min(x, m + 1 - x), mx = max(x, m + 1 - x);
			if (a[mi] == 'A') a[mx] = 'A';
			else a[mi] = 'A';
		}
		for (int i = 1; i <= m; i++) cout << a[i];
		cout << endl;
	}
} t;
void solve() {
	t.solve();
}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}