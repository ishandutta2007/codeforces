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

int ask(int x) {
	cout << x << "\n";
	cout.flush();
	cin >> x;
	if (x == 0)
		exit(0);
	return x;
}

int m, n;
int p[100];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		int x = ask(m);
		if (x == -1)
			p[i] = 1;
		else
			p[i] = 0;
	}
	ll lb = 1;
	ll rb = m;
	int t = 0;
	while (rb - lb > 1) {
		ll mid = (lb + rb) >> 1;
		int x = ask(mid);
		if (p[t] == 0)
			x = -x;
		t = (t + 1) % n;
		if (x == 1)
			lb = mid + 1;
		else
			rb = mid;
	}
	ask(lb);
	return 0;
}