#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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

int n, m;
vector<int> eds[MAXN];
ll c[MAXN];
ll gl;
int was[MAXN];

void dfs1(int v) {
	was[v] = 1;
	gl = min(gl, c[v]);
	for (int u: eds[v])
		if (!was[u])
			dfs1(u);
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		gl = (ll)1e9 + 100;
		dfs1(i);
		ans += gl;
	}
	cout << ans << "\n";
	return 0;
}