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

ll gcd(ll a, ll b) {
	while (b) {
		ll q = a % b;
		a = b;
		b = q;
	}
	return a;
}

const int MAXN = 1000;

int n;

vector<ll> vv;
ll fl[MAXN];

map<ll, int> mm;

void add(ll x, int c) {
	mm[x] += c;
}
const ll MOD = 998244353;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		ll l = 1;
		ll r = 40000;
		while (r - l > 1) {
			ll mid = (l + r) >> 1;
			if (mid * mid * mid * mid <= x)
				l = mid;
			else
				r = mid;
		}
		if (l * l * l * l == x) {
			add(l, 4);
			continue;
		}
		l = 1;
		r = 1300000;
		while (r - l > 1) {
			ll mid = (l + r) >> 1;
			if (mid * mid * mid <= x)
				l = mid;
			else
				r = mid;
		}
		if (l * l * l == x) {
			add(l, 3);
			continue;
		}
		l = 1;
		r = 1500000000;
		while (r - l > 1) {
			ll mid = (l + r) >> 1;
			if (mid * mid <= x)
				l = mid;
			else
				r = mid;
		}
		if (l * l == x) {
			add(l, 2);
			continue;
		}
		vv.push_back(x);
	}
	for (int i = 0; i < vv.size(); ++i)
		for (int j = i + 1; j < vv.size(); ++j) {
			if (vv[i] != vv[j]) {
				ll x = gcd(vv[i], vv[j]);
				if (x != 1) {
					fl[i] = x;
					fl[j] = x;
				}
			}
		}
	vector<ll> vv2;
	for (int i = 0; i < vv.size(); ++i) {
		if (fl[i] != 0) {
			add(fl[i], 1);
			add(vv[i] / fl[i], 1);
		}
		else {
			int fll = 0;
			for (auto x: mm) {
				if (vv[i] % x.first == 0) {
					++mm[x.first];
					++mm[vv[i] / x.first];
					fll = 1;
					break;
				}
			}
			if (!fll) {
				vv2.push_back(vv[i]);
			}
		}
	}
	sort(ALL(vv2));
	ll cur = 1;
	for (auto x: mm) {
		cur = (cur * (x.second + 1)) % MOD;
	}
	int cnt = 0;
	for (int i = 0; i < vv2.size(); ++i) {
		++cnt;
		if (i + 1 == vv2.size() || vv2[i] != vv2[i + 1]) {
			cur = (cur * (cnt + 1)) % MOD;
			cur = (cur * (cnt + 1)) % MOD;
			cnt = 0;
		}
	}
	cout << cur << "\n";
	cout.flush();
	return 0;
}