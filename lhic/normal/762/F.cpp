#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 1020;
const ll MOD = 1e9 + 7;
vector<ll> dp[MAXN][13];
ll dpl[MAXN][1 << 12];
ll dpr[MAXN][1 << 12];
vector<int> eds[MAXN];
vector<int> edn[MAXN];
vector<int> ed2[14];
vector<int> ed21[14];
int n, m;
int was[MAXN];

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		--b;
		ans = (ans * a) % MOD;
	}
	return ans;
}

void add(ll &a, ll b) {
	a = (a + b) % MOD;
}

void calc(int k) {
	for (int i = 0; i < n; ++i) {
		dp[i][k].resize(eds[i].size() + 1);
		if (eds[i].size() < ed2[k].size())
			continue;
		int cnt = ed2[k].size();
		memset(dpl[0], 0, sizeof(dpl[0][0]) * (1 << cnt));
		dpl[0][0] = 1;
		for (int j = 0; j < eds[i].size(); ++j) {
			memcpy(dpl[j + 1], dpl[j], sizeof(dpl[0][0]) * (1 << cnt));
			for (int k1 = 0; k1 < (1 << cnt); ++k1) {
				for (int l = 0; l < cnt; ++l) {
					if ((k1 >> l) & 1)
						continue;
					add(dpl[j + 1][k1 ^ (1 << l)], dpl[j][k1] * dp[eds[i][j]][ed2[k][l]][edn[i][j]]);
				}
			}
		}
		memset(dpr[eds[i].size()], 0, sizeof(dpr[0][0]) * (1 << cnt));
		dpr[eds[i].size()][0] = 1;
		for (int j = (int)eds[i].size() - 1; j >= 0; --j) {
			memcpy(dpr[j], dpr[j + 1], sizeof(dpr[0][0]) * (1 << cnt));
			for (int k1 = 0; k1 < (1 << cnt); ++k1) {
				for (int l = 0; l < cnt; ++l) {
					if ((k1 >> l) & 1)
						continue;
					add(dpr[j][k1 ^ (1 << l)], dpr[j + 1][k1] * dp[eds[i][j]][ed2[k][l]][edn[i][j]]);
				}
			}
		}
		dp[i][k][eds[i].size()] = dpl[eds[i].size()][(1 << cnt) - 1];
		for (int j = 0; j < (int)eds[i].size(); ++j) {
			for (int l = 0; l < (1 << cnt); ++l)
				add(dp[i][k][j], dpl[j][l] * dpr[j + 1][((1 << cnt) - 1) ^ l]);
		}
	}
}

void dfs1(int v) {
	was[v] = 1;
	for (int u: ed21[v]) {
		if (was[u])
			continue;
		ed2[v].push_back(u);
		dfs1(u);
	}
	calc(v);
}

vector<int> vv;
bool cmp(int a, int b) {
	return ed21[a].size() > ed21[b].size();
}

int ed[14][14];
int en[14];
int sv[14];
vector<int> go[14];

ll run(int xx) {
	if (xx == vv.size())
		return 1;
	int x = vv[xx];
	ll ans = 0;
	for (int i = 0; i < m; ++i)
		if (!en[i] && ed21[i].size() == ed21[x].size()) {
			en[i] = 1;
			sv[xx] = i;
			int fl = 0;
			for (int j: go[xx]) {
				if (!ed[sv[j]][i]) {
					fl = 1;
					break;
				}
			}
			if (!fl)
				ans += run(xx + 1);
			en[i] = 0;
		}
	return ans;
}

ll calcAut() {
	for (int i = 0; i < m; ++i)
		vv.push_back(i);
	sort(vv.begin(), vv.end(), cmp);
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j)
			if (ed[vv[i]][vv[j]])
				go[j].push_back(i);
	return run(0);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edn[a].push_back(eds[b].size());
		edn[b].push_back(eds[a].size());
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	scanf("%d", &m);
	for (int i = 0; i < m - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		ed21[a].push_back(b);
		ed21[b].push_back(a);
		ed[a][b] = ed[b][a] = 1;
	}
	ll aut = calcAut();
	aut = pw(aut, MOD - 2);
	dfs1(0);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + dp[i][0][eds[i].size()]) % MOD;
	}
	ans = (ans * aut) % MOD;
	cout << ans << "\n";
	return 0;
}