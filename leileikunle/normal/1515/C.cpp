#include <bits/stdc++.h>

#define int long long
using namespace std;
#define endl '\n'
using pii = pair<int, int>;
const int N = 1e6 + 10;

int n, a[N], k;
void solve() {

	cout << "YES\n";
	int n, m, x;
	cin >> n >> m >> x;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= m; i++) q.push({0, i});

	map<int, int> mp;
	for (int i = 1; i <= n; i++) {

		auto [x, y] = q.top();
		q.pop();
		mp[i] = y;
		q.push({x + a[i], y});
	}
	for (int i = 1; i <= n; i++) cout << mp[i] << " ";
	cout << endl;
}



signed main() {

	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}