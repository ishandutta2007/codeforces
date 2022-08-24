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

const ll MOD = 1e9 + 7;
const int MAXN = 120000;

ll pw2[210];
int n, m;
vector<pair<int, ll> > eds[MAXN];
int was[MAXN];
vector<ll> vv;
vector<ll> gs;
ll sm[MAXN];
ll gg[100];
ll cc[100][3];

void dfs1(int v) {
	was[v] = 1;
	vv.push_back(sm[v]);
	for (pair<int, ll> e: eds[v]) {
		int u = e.first;
		if (was[u] == 2)
			continue;
		if (was[u] == 1) {
			ll x = sm[u] ^ sm[v] ^ e.second;
			if (x != 0)
				gs.push_back(x);
		}
		else {
			sm[u] = sm[v] ^ e.second;
			dfs1(u);
		}
	}
	was[v] = 2;
}

ll solve(int x) {
	vv.clear();
	gs.clear();
	dfs1(x);
	int now = 0;
	for (int i = 0; i < 60; ++i) {
		int fl = 0;
		for (int j = now; j < (int)gs.size(); ++j) {
			if ((gs[j] >> i) & 1) {
				swap(gs[j], gs[now]);
				fl = 1;
				break;
			}
		}
		if (!fl)
			continue;
		for (int j = now + 1; j < (int)gs.size(); ++j) {
			if ((gs[j] >> i) & 1)
				gs[j] ^= gs[now];
		}
		now += 1;
	}
	gs.resize(now);
	for (int i = 0; i < 60; ++i)
		gg[i] = 0;
	for (int i = 0; i < now; ++i)
		for (int j = 0; j < 60; ++j)
			if ((gs[i] >> j) & 1)
				gg[j] = 1;
	for (int i = 0; i < 60; ++i)
		cc[i][0] = 0, cc[i][1] = 0;
	ll ans = 0;
	for (int i = 0; i < (int)vv.size(); ++i) {
		for (int j = 0; j < 60; ++j) {
			if (gg[j]) {
				ans = (ans + pw2[j + now - 1] * i) % MOD;
			}
			else {
				int x = (vv[i] >> j) & 1;
				ans = (ans + pw2[j + now] * cc[j][1 - x]) % MOD;
				cc[j][x] += 1;
			}
		}
	}
	return ans;
}


int main() {
	pw2[0] = 1;
	for (int i = 1; i < 200; ++i)
		pw2[i] = (pw2[i - 1] * 2) % MOD;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		--a;
		--b;
		eds[a].push_back(make_pair(b, c));
		eds[b].push_back(make_pair(a, c));
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!was[i])
			ans = (ans + solve(i)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}