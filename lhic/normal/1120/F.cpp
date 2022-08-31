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
ll c, d;

ll t[MAXN];
int tp[MAXN];

int nx[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> c >> d;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		char c;
		cin >> c;
		if (c == 'W')
			tp[i] = 0;
		else
			tp[i] = 1;
	}
	cin >> t[n];
	tp[n] = 2;
	for (int i = n - 1; i >= 0; --i) {
		if (tp[i] != tp[i + 1])
			nx[i] = i + 1;
		else
			nx[i] = nx[i + 1];
	}
	ll ans = d * n;
	ll cur = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (tp[i + 1] == tp[i])
			cur += min(d, (t[nx[i + 1]] - t[i + 1]) * c);
		ans = min(ans, i * d + cur + (t[n] - t[i]) * c);
	}
	cout << ans << "\n";
	return 0;
}