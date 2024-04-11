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
vector<int> eds[MAXN];
ll s[MAXN];
ll ans = 0;
int pp[MAXN];

void no() {
	cout << -1 << "\n";
	exit(0);
}

void dfs1(int v) {
	if (s[v] == -1) {
		ll now = s[pp[v]];
		if (eds[v].empty())
			ans += 0;
		else {
			ll mn = 1e9 + 1000;
			for (int u: eds[v])
				mn = min(mn, s[u]);
			if (mn < now)
				no();
			s[v] = s[pp[v]] + (mn - now);
			ans += mn - now;
		}
	}
	else {
		if (v == 0) {
			ans += s[v];
		}
		else {
			ans += s[v] - s[pp[v]];
		}
	}
	for (int u: eds[v])
		dfs1(u);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		eds[p].push_back(i);
		pp[i] = p;
	}
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	dfs1(0);
	cout << ans << "\n";
	return 0;
}