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

int sz[MAXN];
int p[MAXN];

int get(int x) {
	if (p[x] == x)
		return x;
	return p[x] = get(p[x]);
}


vector<tuple<int, int, int>> ed;

int n, m, k;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		--x;
		sz[x] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a, --b;
		ed.emplace_back(w, a, b);
	}
	for (int i = 0; i < n; ++i)
		p[i] = i;
	sort(ed.begin(), ed.end());
	for (int i = 0; i < ed.size(); ++i) {
		int a, b, w;
		tie(w, a, b) = ed[i];
		a = get(a);
		b = get(b);
		if (a == b)
			continue;
		p[a] = b;
		sz[b] += sz[a];
		if (sz[b] == k) {
			for (int i = 0; i < k; ++i)
				cout << w << " ";
			cout << "\n";
			return 0;
		}
	}
	return 0;
}