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

ll n;
ll s;

void no() {
	cout << "No\n";
	exit(0);
}


ll cc[MAXN];

ll get(ll n, ll k) {
	ll now = n;
	ll ans = 0;
	ll cur = 1;
	for (int i = 1; now; cur *= k, ++i) {
		ll go = min(now, cur);
		ans += i * go;
		now -= go;
	}
	return ans;
}

vector<int> go[MAXN];
int ed[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> s;
	if (s > n * (n + 1) / 2 || s < 2 * n - 1)
		no();
	if (s == n * (n + 1) / 2) {
		cout << "Yes\n";
		for (int i = 1; i < n; ++i)
			cout << i << " ";
		cout << "\n";
		return 0;
	}
	ll k = 2;
	while (get(n, k) > s)
		++k;
	cc[0] = 1;
	ll now = 1;
	ll lf = n - 1;
	s -= n;
	while (lf) {
		while (cc[now] == cc[now - 1] * k)
			++now;
		if (lf * (now + now + lf - 1) / 2 >= s)
			++cc[now], --lf, s -= now;
		else {
			++now;
			++cc[now];
			--lf;
			s -= now;
		}
	}
	assert(s == 0);
	int c = 0;
	for (int i = 0; i <= now; ++i) {
		for (int j = 0; j < cc[i]; ++j)
			go[i].push_back(c++);
	}
	cout << "Yes\n";
	for (int i = 1; i <= now; ++i) {
		int p = 0;
		for (int cnt = 0; cnt < go[i].size(); ++cnt) {
			while (ed[go[i - 1][p]] == k)
				++p;
			++ed[go[i - 1][p]];
			cout << go[i - 1][p] + 1 << " ";
		}
	}
	cout << "\n";
	return 0;
}