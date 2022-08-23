#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 210000;

int n;
ll c[MAXN];

vector<int> eds[MAXN];

ll dp[MAXN][2];

void dfs1(int v, int p) {
	ll sm = 0;
	ll d = 0;
	int fl = 0;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		fl = 1;
		dfs1(u, v);
		sm += dp[u][1];
		d = min(d, dp[u][0] - dp[u][1]);
	}
	if (fl) {
		dp[v][1] = min(sm, sm + d + c[v]);
		dp[v][0] = sm + d;
	}
	else {
		dp[v][1] = c[v];
		dp[v][0] = 0;
	}
}

int dg[MAXN][2];
vector<int> vv;

void dfs2(int v, int p) {
	ll sm = 0;
	ll d = 0;
	int fl = 0;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		fl = 1;
		sm += dp[u][1];
		d = min(d, dp[u][0] - dp[u][1]);
	}
	if (fl) {
		//dp[v][1] = min(sm, sm + d + c[v]);
		//dp[v][0] = sm + d;
		if (dg[v][1] && dp[v][1] == sm) {
			for (int u: eds[v])
				if (u != p)
					dg[u][1] = 1;
		}
		if (dg[v][1] && dp[v][1] == sm + d + c[v]) {
			vv.push_back(v);
			int cnt = 0;
			for (int u: eds[v])
				if (u != p && dp[u][0] - dp[u][1] == d)
					dg[u][0] = 1, ++cnt;
			for (int u: eds[v])
				if (u != p && (cnt > 1 || dp[u][0] - dp[u][1] != d))
					dg[u][1] = 1;
		}
		if (dg[v][0]) {
			int cnt = 0;
			for (int u: eds[v])
				if (u != p && dp[u][0] - dp[u][1] == d)
					dg[u][0] = 1, ++cnt;
			for (int u: eds[v])
				if (u != p && (cnt > 1 || dp[u][0] - dp[u][1] != d))
					dg[u][1] = 1;
		}
	}
	else {
		if (dg[v][1])
			vv.push_back(v);
	}
	for (int u: eds[v])
		if (u != p)
			dfs2(u, v);
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0, -1);
	dg[0][1] = 1;
	dfs2(0, -1);
	sort(ALL(vv));
	cout << dp[0][1] << " " << vv.size() << "\n";
	for (int i: vv)
		cout << i + 1 << " ";
	cout << "\n";
	return 0;
}