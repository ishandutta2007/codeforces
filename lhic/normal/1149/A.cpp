#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

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

int n;
int c1, c2;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x == 1)
			++c1;
		else
			++c2;
	}
	if (c1 == 0) {
		for (int i = 0; i < c2; ++i)
			cout << 2 << " ";
		cout << "\n";
	}
	else if (c2 == 0) {
		for (int i = 0; i < c1; ++i)
			cout << 1 << " ";
		cout << "\n";
	}
	else {
		cout << 2 << " ";
		--c2;
		cout << 1 << " ";
		--c1;
		for (int i = 0; i < c2; ++i)
			cout << 2 << " ";
		for (int i = 0; i < c1; ++i)
			cout << 1 << " ";
		cout << "\n";
	}
	return 0;
}