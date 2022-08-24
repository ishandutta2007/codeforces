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


int n;
int a[220000];
int s[220000];
int g[220000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", s + i, g + i);
		a[i] = s[i] + g[i];
	}
	for (int i = 0; i < n - 1; ++i)
		a[i + 1] = min(a[i + 1], a[i] + 1);
	for (int i = n - 1; i > 0; --i)
		a[i - 1] = min(a[i - 1], a[i] + 1);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < s[i]) {
			printf("-1\n");
			return 0;
		}
		ans += a[i] - s[i];
	}
	printf("%lld\n", ans);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}