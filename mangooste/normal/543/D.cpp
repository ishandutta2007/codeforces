#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T, T mod, class BIG = long long>
struct modular {
	T val;
	modular() {}
	template<class C> modular(C x) : val((x % mod + mod) % mod) {}
	modular& operator = (modular a) { val = a.val; return *this; }
	modular& operator += (modular a) { val += a.val; if (val >= mod) a -= mod; return *this; }
	modular& operator -= (modular a) { val -= a.val; if (val < 0) val += mod; return *this; }
	modular& operator *= (modular a) { val = BIG(val) * a.val % mod; return *this; }
	modular& operator /= (modular a) { val = BIG(val) * power(a, mod - 2) % mod; return *this; }
	modular operator + (modular a) { BIG res = val + a.val; return res - mod * (res >= mod); }
	modular operator - (modular a) { BIG res = val - a.val; return res + mod * (res < 0); }
	modular operator * (modular a) { return (BIG) val * a.val % mod; }
	modular operator / (modular a) { return (BIG) val * power(a, mod - 2) % mod; }
	friend modular power(modular a, BIG pw) { modular res = 1; while (pw) { if (pw % 2) res *= a; a *= a; pw /= 2; } return res; }
	friend ostream& operator << (ostream &out, modular a) { return out << a.val; }
	friend istream& operator >> (istream &in, modular &a) { BIG x; in >> x; a = modular(x); return in; }
};

using mint = modular<int, 1000000007>;

vector<vector<int>> g;
vector<array<mint, 2>> dp;
vector<array<vector<mint>, 2>> pref, suf;
vector<mint> ans;

void dfs(int v) {
	for (auto u : g[v]) dfs(u);
	for (int i = 0; i < 2; i++) pref[v][i].push_back(1);
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		pref[v][0].push_back(pref[v][0].back() * dp[u][0]);
		pref[v][1].push_back(pref[v][1].back() * (dp[u][0] * 2 + dp[u][1]));
	}
	for (int i = 0; i < 2; i++) suf[v][i].push_back(1);
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][g[v].size() - 1 - i];
		suf[v][0].push_back(suf[v][0].back() * dp[u][0]);
		suf[v][1].push_back(suf[v][1].back() * (dp[u][0] * 2 + dp[u][1]));
	}
	for (int i = 0; i < 2; i++) reverse(suf[v][i].begin(), suf[v][i].end());
	dp[v][0] = pref[v][0].back();
	dp[v][1] = pref[v][1].back() - dp[v][0];
}

void reroot(int v, int pr) {
	ans[v] = dp[v][0] + dp[v][1];
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		array<mint, 2> dp_v = dp[v], dp_u = dp[u];
		dp[v][0] = pref[v][0][i] * suf[v][0][i + 1];
		dp[v][1] = pref[v][1][i] * suf[v][1][i + 1];
		if (pr != -1) {
			dp[v][0] *= dp[pr][0];
			dp[v][1] *= dp[pr][0] * 2 + dp[pr][1];
		}
		dp[v][1] -= dp[v][0];
		dp[u][1] += dp[u][0];
		dp[u][0] *= dp[v][0];
		dp[u][1] *= dp[v][0] * 2 + dp[v][1];
		dp[u][1] -= dp[u][0];
		reroot(u, v);
		dp[v] = dp_v, dp[u] = dp_u;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int par;
		cin >> par;
		par--;
		g[par].push_back(i);
	}
	dp.resize(n, {0, 0});
	pref.resize(n);
	suf.resize(n);
	dfs(0);
	ans.resize(n);
	reroot(0, -1);
	for (auto x : ans) cout << x << ' ';
	cout << '\n';
}