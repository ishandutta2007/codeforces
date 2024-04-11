/*input
2
4 3
10 160 70 50
70 111 111 0
1 2
2 3
3 4
2 1
143 420
214 349
2 1
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
#define debug(x...) {cout << "[" << #x << "] = "; println(x);}
const int N = 3005;
void println() {cout << endl;}
template<typename T, typename... Ts>
void println(const T& value, const Ts&... values) {
	cout << value << ' '; println(values...);
}

#define rank rank__

int n, m;
int val[N], rank[N];
vector<vector<unsigned> > a;

void pdfs(unsigned u, unsigned p) {
	rank[u] = 1;
	loop(i, 0, (int)a[u].size() - 1) {
		auto v = a[u][i];
		if (v == p) {
			a[u].erase(a[u].begin() + i);
			i--;
			continue;
		}
		pdfs(v, u);
		rank[u] += rank[v];
	}
}

pair<unsigned, long long> operator+(pair<unsigned, long long> &X, pair<unsigned, long long> &Y) {
	return {X.fi + Y.fi, X.se + Y.se};
}

pair<unsigned, long long> dp[N][N]; // dp[u][number of cc] = max(win,leftover)
void dfs(unsigned u) {
	auto &f = dp[u];
	f[0] = mp(0, 0);
	unsigned sz = 0;
	for (auto v : a[u]) {
		dfs(v);
		auto &g = dp[v];
		pair<unsigned, long long> fg[sz + rank[v] + 1]; fill(fg, fg + sz + rank[v] + 1, mp(0, -1e18));
		if (sz == 0) {
			loop(i, 0, rank[v]) f[i] = g[i];
		}
		else {
			loop(i, 0, sz) {
				loop(j, 0, rank[v]) {
					fg[i + j] = max(fg[i + j], f[i] + g[j]);
				}
			}
			loop(i, 0, sz + rank[v]) f[i] = fg[i];
		}
		sz += rank[v];
	}
	loop(i, 0, sz) f[i].se += val[u];
	if (u != 1) {
		rloop(i, sz, 0) {
			f[i + 1] = max(f[i + 1], mp(f[i].fi + (f[i].se > 0), 0LL));
		}
	}
	else {
		rloop(i, sz, 0) {
			f[i + 1] = mp(f[i].fi + (f[i].se > 0), 0LL);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	unsigned T; cin >> T;
	while (T--) {
		cin >> n >> m;
		a.assign(n + 5, vector<unsigned>());
		loop(i, 1, n) cin >> val[i];
		loop(i, 1, n) {
			unsigned t; cin >> t;
			val[i] = t - val[i];
		}
		loop(i, 1, n - 1) {
			unsigned u, v; cin >> u >> v;
			a[u].push_back(v); a[v].push_back(u);
		}
		pdfs(1, 1);
		loop(i, 0, n) loop(j, 0, n) dp[i][j] = mp(0, -1e18);
		dfs(1);
		cout << dp[1][m].fi << endl;
	}

}