/*input
4 5
0 0 0 -1
1 2
2 3
3 4
1 4
2 4
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _print(x);}
void _print() {cout << endl;}
template<typename T, typename... Ts> void _print(const T& value, const Ts&... values) {cout << ' ' << value; _print(values...);}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value; _print(values...);}
// change cout to cerr for debug in crash
// for struct, can write print operator to use print() (even with SegTree)
const int N = 3e5 + 5;

struct dsuX { // union by rank + path compress
	vector<int> par, sz;
	void init(int n) {
		par.assign(n + 5, 0); sz.assign(n + 5, 1);
		iota(par.begin(), par.end(), 0);
	}
	int find(int x) {
		return par[x] = (par[x] == x ? x : find(par[x]));
	}
	void uni(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (sz[x] > sz[y]) swap(x, y);
			sz[y] += sz[x]; sz[x] = 0;
			par[x] = y;
		}
	}
} dsu;

int n, m;
int d[N];
vector<vector<pair<int, int> > > a(N);
bool sel[N];

int dfs(int u, int p, int up) {
	int sum = 0;
	for (auto [v, id] : a[u]) {
		if (v == p) continue;
		sum += dfs(v, u, id);
	}
	if ((a[u].size() - sum) % 2 != d[u]) {
		sel[up] = false;
		return 1;
	}
	return 0;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	dsu.init(n);
	int cnt1 = 0, cntf = 0;
	loop(i, 1, n) {
		cin >> d[i];
		cnt1 += (d[i] == 1); cntf += (d[i] == -1);
	}
	if (cnt1 % 2 == 1 && cntf == 0) {
		cout << -1 << endl;
		return 0;
	}
	loop(i, 1, m) {
		int u, v; cin >> u >> v;
		if (dsu.find(u) != dsu.find(v)) {
			dsu.uni(u, v);
			a[u].push_back({v, i});
			a[v].push_back({u, i});
			sel[i] = true;
		}
	}
	if (cnt1 % 2 == 1) {
		loop(i, 1, n) if (d[i] == -1) {
			d[i] = 1; break;
		}
	}
	loop(i, 1, n) if (d[i] == -1) d[i] = 0;
	dfs(1, 1, -1);
	int ans = 0;
	loop(i, 1, m) ans += sel[i];
	cout << ans << endl;
	loop(i, 1, m) if (sel[i]) cout << i << sp;
	cout << endl;
}