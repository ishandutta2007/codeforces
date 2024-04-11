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


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MAXN = 120000;

int sz[MAXN];
int h[MAXN];

vector<int> eds[MAXN];
int n;

void dfs1(int v) {
	sz[v] = 1;
	for (int u: eds[v]) {
		h[u] = h[v] + 1;
		dfs1(u);
		sz[v] += sz[u];
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		eds[x].push_back(i);
	}
	dfs1(0);
	cout.setf(ios::fixed);
	cout.precision(20);
	for (int i = 0; i < n; ++i) {
		cout << (n - sz[i]) / 2.0 + 1 + h[i] / 2.0 << " ";
	}
	cout << "\n";
	return 0;
}