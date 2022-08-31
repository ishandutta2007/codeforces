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

const int MAXN = 210000;
int n;
vector<ll> vx, vy;
ll w[MAXN];
ll h[MAXN];
ll c[MAXN];

map<ll, ll> mw;
map<ll, ll> mh;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	ll now = 0;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> h[i] >> c[i];
		vx.push_back(w[i]);
		vy.push_back(h[i]);
		now = gcd(now, c[i]);
	}
	sort(vx.begin(), vx.end());
	vx.resize(unique(ALL(vx)) - vx.begin());
	sort(vy.begin(), vy.end());
	vy.resize(unique(ALL(vy)) - vy.begin());
	if (n != ll(vx.size()) * ll(vy.size())) {
		cout << 0 << "\n";
		return 0;
	}
	ll ans = 0;
	for (ll i = 1; i * i <= now; ++i) {
		if (now % i == 0) {
			++ans;
			if (i * i != now)
				++ans;
		}
	}
	ll gc = 0;
	for (int i = 0; i < n; ++i)
		if (w[i] == w[0])
			gc = gcd(gc, c[i]);
	for (int i = 0; i < n; ++i)
		if (w[i] == w[0]) {
			mh[h[i]] = c[i] / gc;
		}
	gc = 0;
	for (int i = 0; i < n; ++i)
		if (h[i] == h[0])
			gc = gcd(gc, c[i]);
	for (int i = 0; i < n; ++i)
		if (h[i] == h[0]) {
			mw[w[i]] = c[i] / gc;
		}
	for (int i = 0; i < n; ++i) {
		if (mh[h[i]] * mw[w[i]] != c[i] / now) {
			cout << 0 << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
	return 0;
}