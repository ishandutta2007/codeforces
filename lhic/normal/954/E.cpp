#ifndef BZ
#ifndef __clang__
#pragma GCC optimize "-O3"
#endif
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
const int MAXN = 210000;

int n;
ll T;
vector<pair<ll, ll> > up, dw;
ll a[MAXN];
ll t[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(10);
	cin >> n >> T;
	rep(i, 0, n) {
		cin >> a[i];
	}
	rep(i, 0, n) {
		cin >> t[i];
	}
	ll smp = 0, smq = 0;
	rep(i, 0, n) {
		smp += a[i] * t[i];
		smq += a[i];
	}
	ll add = 0;
	rep(i, 0, n) {
		if (t[i] == T)
			add += a[i];
		else if (t[i] > T) {
			up.emplace_back(t[i], a[i]);
		}
		else {
			dw.emplace_back(t[i], a[i]);
		}
	}
	sort(ALL(up));
	sort(ALL(dw));
	reverse(ALL(dw));
	if (smq * T >= smp) {
		smp = T * add;
		smq = add;
		for (auto x: up) {
			smp += x.first * x.second;
			smq += x.second;
		}
		for (auto x: dw) {
			ll np = smp + x.first * x.second;
			ll nq = smq + x.second;
			if (nq * T <= np) {
				smp = np, smq = nq;
				continue;
			}
			cout << smq + (smp - T * smq) / ld(T - x.first) << "\n";
			return 0;
		}
		cout << smq << "\n";
	}
	else {
		smp = T * add;
		smq = add;
		for (auto x: dw) {
			smp += x.first * x.second;
			smq += x.second;
		}
		for (auto x: up) {
			ll np = smp + x.first * x.second;
			ll nq = smq + x.second;
			if (nq * T >= np) {
				smp = np, smq = nq;
				continue;
			}
			cout << smq + (smp - T * smq) / ld(T - x.first) << "\n";
			return 0;
		}
		cout << smq << "\n";
	}
	return 0;
}