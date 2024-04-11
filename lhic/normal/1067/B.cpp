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

int n, k;
int h[MAXN];
vector<int> eds[MAXN];
int pp[MAXN];

void dfs1(int v, int p) {
	for (int u: eds[v]) {
		if (u == p)
			continue;
		h[u] = h[v] + 1;
		pp[u] = v;
		dfs1(u, v);
	}
}

void no() {
	cout << "No\n";
	exit(0);
}

void dfs2(int v, int p) {
	int cc = 0;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		++cc;
		h[u] = h[v] + 1;
		dfs2(u, v);
	}
	if (cc == 0) {
		if (h[v] != k)
			no();
	}
	else if (cc < 3) {
		no();
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0, -1);
	int mx = -1;
	for (int i = 0; i < n; ++i)
		if (mx == -1 || h[i] > h[mx])
			mx = i;
	if (h[mx] < k)
		no();
	for (int i = 0; i < k; ++i)
		mx = pp[mx];
	h[mx] = 0;
	dfs2(mx, -1);
	cout << "Yes\n";
	return 0;
}