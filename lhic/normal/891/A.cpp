#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
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

const int MAXN = 2100;
int a[MAXN];
int n;
const int INF = 1e6;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int cc1 = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] == 1) {
			++cc1;
		}
	if (cc1) {
		cout << n - cc1 << "\n";
		return 0;
	}
	int ans = INF;
	for (int i = 0; i < n; ++i) {
		int cur = a[i];
		for (int j = i - 1; j >= 0; --j) {
			cur = gcd(cur, a[j]);
			if (cur == 1) {
				ans = min(ans, n + i - j - 1);
				break;
			}
		}
		cur = a[i];
		for (int j = i + 1; j < n; ++j) {
			cur = gcd(cur, a[j]);
			if (cur == 1) {
				ans = min(ans, n + j - i - 1);
				break;
			}
		}
	}
	if (ans == INF)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
	return 0;
}