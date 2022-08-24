#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

typedef complex<ld> cmplx;
const int MAXN = 210000;

int n;
ll x;
ll a[MAXN];

ll ans[MAXN];

cmplx ac[1 << 19];
cmplx bc[1 << 19];

ll sm[MAXN];

ll cnt[MAXN];

int rev(int x, int k) {
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans = ans * 2 + (x & 1);
		x >>= 1;
	}
	return ans;
}

const ld PI = acos(-1.0);

void fft(cmplx *a, int k, int inv) {
	int n = (1 << k);
	for (int i = 0; i < n; ++i) {
		int x = rev(i, k);
		if (x > i)
			swap(a[x], a[i]);
	}
	for (int bl = 1; bl < n; bl *= 2) {
		ld ang = PI / bl;
		if (inv)
			ang = -ang;
		cmplx wadd(cos(ang), sin(ang));
		for (int i = 0; i < n; i += 2 * bl) {
			cmplx w = 1;
			for (int j = i; j < i + bl; ++j, w = w * wadd) {
				cmplx u = a[j];
				cmplx v = w * a[j + bl];
				a[j] = u + v;
				a[j + bl] = u - v;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; ++i)
			a[i] = a[i] / ld(n);
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] < x)
			a[i] = 1;
		else
			a[i] = 0;
	}
	sm[0] = 0;
	for (int i = 0; i < n; ++i)
		sm[i + 1] = sm[i] + a[i];
	for (int i = 0; i <= n; ++i)
		++cnt[sm[i]];
	for (int i = 0; i <= n; ++i)
		ac[i] = cnt[i];
	for (int j = 0; j <= n; ++j)
		bc[j] = cnt[n - j];
	int k = 0;
	while ((1 << k) <= 2 * n + 5)
		++k;
	fft(ac, k, 0);
	fft(bc, k, 0);
	for (int i = 0; i < (1 << k); ++i)
		ac[i] = ac[i] * bc[i];
	fft(ac, k, 1);
	for (int i = n + 1; i <= 2 * n; ++i) {
		ans[i - n] = llround(ac[i].real());
	}
	for (int i = 0; i <= n; ++i) {
		if (cnt[i])
			ans[0] += ll(cnt[i]) * ll(cnt[i] - 1) / 2;
	}
	for (int i = 0; i <= n; ++i)
		cout << ans[i] << " ";
	return 0;
}