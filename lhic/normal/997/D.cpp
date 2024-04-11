#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
const int MAXN = 4100;

ll fc[MAXN];
ll bfc[MAXN];

ll cnk(int n, int k) {
	if (k > n)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int n;
vector<tuple<int, int, int> > gg;
int sz[MAXN];
int go[MAXN][MAXN];
vector<int> eds[MAXN];

vector<ll> ans[MAXN * 2];
vector<ll> vvv[MAXN];

void dfs1(int v, int p = -1) {
	sz[v] = 1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs1(u, v);
		sz[v] += sz[u];
		gg.emplace_back(sz[u], u, v);
		gg.emplace_back(n - sz[u], v, u);
	}
}


vector<ll> solve(int n, int k) {
	::n = n;
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	gg.clear();
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	sort(gg.begin(), gg.end());
	for (int i = 0; i < n; ++i) {
		vvv[i].clear();
		vvv[i].resize(k + 1);
	}
	for (int i = 0; i < gg.size(); ++i) {
		ans[i].clear();
		int tmp, a, b;
		tie(tmp, a, b) = gg[i];
		go[a][b] = i;
	}
	for (int i = 0; i < gg.size(); ++i) {
		int tmp, a, b;
		tie(tmp, a, b) = gg[i];
		vector<ll> vv = vvv[a];
		if (go[a][b] > go[b][a]) {
			for (int j = 0; j + 2 <= k; ++j)
				vv[j + 2] = (vv[j + 2] - ans[go[b][a]][j] + MOD) % MOD;
		}
		ans[i].resize(k + 1);
		ans[i][0] = 1;
		for (int i1 = 0; i1 < k; ++i1) {
			for (int j = 1; i1 + j <= k; ++j) {
				ans[i][i1 + j] = (ans[i][i1 + j] + ans[i][i1] * vv[j]) % MOD;
			}
		}
		for (int j = 0; j + 2 <= k; ++j)
			vvv[b][j + 2] = (vvv[b][j + 2] + ans[i][j]) % MOD;
	}
	vector<ll> gans(k + 1);
	for (int a = 0; a < n; ++a) {
		vector<ll> tans;
		vector<ll> vv(k + 1);
		for (int u: eds[a]) {
			for (int j = 0; j + 2 <= k; ++j)
				vv[j + 2] = (vv[j + 2] + ans[go[u][a]][j]) % MOD;
		}
		tans.resize(k + 1);
		tans[0] = 1;
		for (int i1 = 0; i1 < k; ++i1) {
			for (int j = 1; i1 + j <= k; ++j) {
				tans[i1 + j] = (tans[i1 + j] + tans[i1] * vv[j]) % MOD;
			}
		}
		for (int i = 0; i <= k; ++i)
			gans[i] = (gans[i] + tans[i]) % MOD;
	}
	return gans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n1, n2, k;
	cin >> n1 >> n2 >> k;
	fc[0] = 1;
	for (int i = 1; i <= k; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	bfc[k] = pw(fc[k], MOD - 2);
	for (int i = k - 1; i >= 0; --i)
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;
	vector<ll> v1 = solve(n1, k);
	vector<ll> v2 = solve(n2, k);
	ll ans = 0;
	for (int i = 0; i <= k; ++i) {
		ans = (ans + cnk(k, i) * v1[i] % MOD * v2[k - i]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}