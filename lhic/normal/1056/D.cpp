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
const int MAXN = 120000;

int n;
int p[MAXN];
vector<int> eds[MAXN];

int sz[MAXN];

vector<int> vv;

void dfs1(int v) {
	if (eds[v].size() == 0)
		sz[v] = 1;
	for (int u: eds[v]) {
		dfs1(u);
		sz[v] += sz[u];
	}
	vv.push_back(sz[v]);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> p[i];
		--p[i];
		eds[p[i]].push_back(i);
	}
	dfs1(0);
	sort(vv.begin(), vv.end());
	for (int i = 0; i < n; ++i) {
		cout << vv[i] << " ";
	}
	cout << "\n";
	return 0;
}