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
int a[MAXN];
int b[MAXN];
ll ad[MAXN];
const int C = 100000;
vector<pair<int, int>> mv;

void dfs1(int v) {
	if (ad[v] > 0) {
		if (a[v + 1] == 9)
			dfs1(v + 1);
		++a[v];
		++a[v + 1];
		mv.emplace_back(v, 1);
		--ad[v];
	}
	else {
		if (a[v + 1] == 0)
			dfs1(v + 1);
		--a[v];
		--a[v + 1];
		mv.emplace_back(v, -1);
		++ad[v];
	}
}

ll df[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		b[i] = c - '0';
	}
	ll ans = 0;
	for (int i = 0; i + 1 < n; ++i) {
		int go = b[i] - (a[i] + df[i]);
		ad[i] = go;
		df[i + 1] = go;
		ans += abs(go);
	}
	if (a[n - 1] + df[n - 1] != b[n - 1]) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 0; i + 1 < n; ++i) {
		while (ad[i] != 0 && mv.size() < C)
			dfs1(i);
	}
	if (mv.size() > C)
		mv.resize(C);
	cout << ans << "\n";
	for (auto p: mv)
		cout << p.first + 1 << " " << p.second << "\n";
	return 0;
}