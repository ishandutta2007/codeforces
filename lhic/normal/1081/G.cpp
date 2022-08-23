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



ll MOD;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

map<int, int> mm;

void run(int n, int k) {
	if (n <= 0)
		return;
	if (n == 1) {
		++mm[1];
		return;
	}
	if (k <= 1) {
		++mm[n];
		return;
	}
	int n2 = n / 2;
	run(n2, k - 1);
	run(n - n2, k - 1);
}

ll n, k;

ll get(int a, int b) {
	if (a > b)
		swap(a, b);
	ll ans = 0;
	for (int i = 0; i <= (a - 1) + (b - 1); ++i) {
		ll cnt = 0;
		if (i < a)
			cnt = i + 1;
		else if (i < b)
			cnt = a;
		else
			cnt = i + 1 - (i + 1 - a) - (i + 1 - b);
		ans = (ans + cnt * pw(i + 2, MOD - 2)) % MOD;
	}
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k >> MOD;
	run(n, k);
	vector<pair<int, ll>> vv;
	for (auto x: mm)
		vv.push_back(x);
	ll ans = n * (n - 1) * pw(4, MOD - 2);
	ll sum = 0;
	for (int i = 0; i < vv.size(); ++i) {
		ll go = get(vv[i].first, vv[i].first);
		sum = (sum + go * vv[i].second % MOD * (vv[i].second - 1) % MOD * pw(2, MOD - 2)) % MOD;
		for (int j = i + 1; j < vv.size(); ++j)
			sum = (sum + get(vv[i].first, vv[j].first) * vv[i].second % MOD * vv[j].second) % MOD;
	}
	ans = (ans - sum + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}