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

vector<int> go[5100];

int n, m;

int ds(int a, int b) {
	if (a <= b)
		return b - a;
	else
		return b - a + n;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		go[a].push_back(ds(a, b));
	}
	for (int i = 0; i < n; ++i)
		sort(ALL(go[i]));
	for (int i = 0; i < n; ++i) {
		int now = 0;
		for (int j = 0; j < n; ++j)
			if (!go[j].empty())
				now = max(now, n * ((int)go[j].size() - 1) + ds(i, j) + go[j][0]);
		cout << now << " ";
	}
	cout << "\n";
	return 0;
}