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


int n, a, b;
int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> a >> b;
	int cur = 0;
	int sum = a + b;
	if (a < b)
		swap(a, b);
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == '.') {
			++cur;
		}
		else {
			if (cur % 2 == 0) {
				a -= cur / 2;
				b -= cur / 2;
			}
			else {
				int x = cur / 2;
				b -= x;
				a -= cur - x;
			}
			cur = 0;
		}
		a = max(0, a);
		b = max(0, b);
		if (a < b)
			swap(a, b);
	}
	if (cur % 2 == 0) {
		a -= cur / 2;
		b -= cur / 2;
	}
	else {
		int x = cur / 2;
		b -= x;
		a -= cur - x;
	}
	a = max(0, a);
	b = max(0, b);
	if (a < b)
		swap(a, b);
	cout << sum - a - b << "\n";
	return 0;
}