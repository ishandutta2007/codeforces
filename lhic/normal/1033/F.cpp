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
int gl;
int pw3[100];
ll cnt[531441];
ll cnt3[531441];
int w;
int n, m;
int a[51000];

void run0(int x, int cur) {
	if (x == w) {
		++cnt3[cur];
		return;
	}
	run0(x + 1, cur + 2 * pw3[x]);
	run0(x + 1, cur + ((gl >> x) & 1) * pw3[x]);
}

string s;
ll ans = 0;

void run1(int x, int cur, int cur3) {
	if (x == w) {
		ans += cnt[cur] * cnt3[cur3];
		return;
	}
	switch (s[x]) {
		case 'A':
			run1(x + 1, cur + (1 << x), cur3);
			run1(x + 1, cur, cur3 + 2 * pw3[x]);
			break;
		case 'O':
			run1(x + 1, cur, cur3);
			break;
		case 'X':
			run1(x + 1, cur, cur3);
			run1(x + 1, cur + (1 << x), cur3 + pw3[x]);
			break;
		case 'a':
			run1(x + 1, cur + (1 << x), cur3 + pw3[x]);
			break;
		case 'o':
			run1(x + 1, cur, cur3 + pw3[x]);
			run1(x + 1, cur + (1 << x), cur3 + 2 * pw3[x]);
			break;
		case 'x':
			run1(x + 1, cur, cur3 + pw3[x]);
			run1(x + 1, cur + (1 << x), cur3);
			break;
	}
}



int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> w >> n >> m;
	pw3[0] = 1;
	for (int i = 1; i <= w; ++i)
		pw3[i] = pw3[i - 1] * 3;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		gl = a[i];
		++cnt[a[i]];
		run0(0, 0);
	}
	for (int i = 0; i < m; ++i) {
		cin >> s;
		reverse(ALL(s));
		ans = 0;
		run1(0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}