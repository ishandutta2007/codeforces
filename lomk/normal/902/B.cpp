/*input
7
1 1 2 3 1 4
3 3 1 1 1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 100005
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}

int n;
vector<vector<int> > a(N);
int c[N];
int ans = 0;
void dfs(int u, int p, bool recolor) {
	ans += recolor;
	for (auto v : a[u]) {
		if (v == p) continue;
		if (c[v] == c[u]) dfs(v, u, 0);
		else dfs(v, u, 1);
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int u; cin >> u;
		a[u].push_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1, 1, 1);
	cout << ans << endl;
}