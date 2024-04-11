/*input
10 16
6 1
1 10
6 5
5 7
5 2
4 1
1 3
5 8
1 8
1 7
4 5
9 1
10 5
9 5
3 5
1 2
1 5 4 5
*/
/*input

*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
#define ll long long
#define debug(x...) {cout << "[" << #x << "] = "; println(x);}
const int N = 200005;
void println() {cout << endl;}
template<typename T, typename... Ts>
void println(const T& value, const Ts&... values) {
	cout << value << ' '; println(values...);
}
struct dsu {
	vector<int> par, sz;
	void init(int n) {
		par.assign(n + 5, 0); sz.assign(n + 5, 1);
		loop(i, 0, par.size() - 1) par[i] = i;
	}
	int find(int x) {
		return par[x] == x ? x : find(par[x]);
	}
	void uni(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (sz[x] > sz[y]) swap(x, y);
			sz[y] += sz[x]; sz[x] = 0;
			par[x] = y;
		}
	}
} small;

#define data data__
struct data {
	int u, v;
	data(int _u , int _v): u(_u), v(_v) {};
};

vector<data> edge;
vector<data> ans;
int n, m;
int S, T, limS = 0, limT = 0;
pair<int, int> con[N];
bool SaT;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		edge.push_back(data(x, y));
	}
	cin >> S >> T >> limS >> limT;
	small.init(n);
	for (int i = 0; i < m; i++) {
		int u = edge[i].u; int v = edge[i].v;
		if (u != S && u != T && v != S && v != T)
			if (small.find(u) != small.find(v)) {
				small.uni(u, v);
				ans.push_back(edge[i]);
			}
		if ((u == S && v == T) || (u == T && v == S)) {
			SaT = true; continue;
		}
	}
	for (int i = 0; i < m; i++) {
		int u = edge[i].u; int v = edge[i].v;
		if ((u == S && v == T) || (u == T && v == S))
			continue;
		if (u == S || v == S) {
			if (v == S) swap(u, v);
			if (!con[small.find(v)].fi || con[small.find(v)].fi == S)
				con[small.find(v)] = mp(S, i);
			else
				con[small.find(v)] = mp(-1, -1);
		}
		if (u == T || v == T) {
			if (v == T) swap(u, v);
			if (!con[small.find(v)].fi || con[small.find(v)].fi == T)
				con[small.find(v)] = mp(T, i);
			else
				con[small.find(v)] = mp(-1, -1);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (con[i].fi == S) {
			limS--; ans.push_back(edge[con[i].se]);
			small.uni(edge[con[i].se].u, edge[con[i].se].v);
		}
		else if (con[i].fi == T) {
			limT--; ans.push_back(edge[con[i].se]);
			small.uni(edge[con[i].se].u, edge[con[i].se].v);
		}
	}
	for (int i = 0; i < m; i++) {
		int u = edge[i].u; int v = edge[i].v;
		if ((u == S && v == T) || (u == T && v == S)) continue;
		if (small.find(u) != small.find(v)) {
			if (u == S || v == S) {
				if (limS == 0) continue;
				limS--;
			}
			if (u == T || v == T) {
				if (limT == 0) continue;
				limT--;
			}
			small.uni(u, v);
			ans.push_back(edge[i]);
		}
	}
	if (small.find(S) != small.find(T) && limS > 0 && limT > 0) {
		small.uni(S, T);
		ans.push_back(data(S, T));
	}
	if (limS < 0 || limT < 0) return cout << "No", 0;
	for (int i = 1; i <= n - 1; i++) if (small.find(i) != small.find(i + 1)) return cout << "No", 0;
	cout << "Yes" << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i].u << sp << ans[i].v << endl;
}