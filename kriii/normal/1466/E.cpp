#include <stdio.h>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;
int n, cnt[60]; long long a[500500], p[60] = { 1, };

int main()
{
	for (int b = 1; b < 60; b++) p[b] = p[b - 1] * 2 % mod;

	int t; scanf ("%d", &t); while (t--){
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%lld", &a[i]);

		for (int b = 0; b < 60; b++) cnt[b] = 0;
		for (int i = 0; i < n; i++) for (int b = 0; b < 60; b++) if (a[i] & (1ll << b)) cnt[b]++;

		long long ans = 0;
		for (int j = 0; j < n; j++){
			long long is = 0;
			for (int b = 0; b < 60; b++) if (a[j] & (1ll << b)) is = (is + cnt[b] * p[b]) % mod;
			long long ks = a[j] % mod * n % mod;
			for (int b = 0; b < 60; b++) if (~a[j] & (1ll << b)) ks = (ks + cnt[b] * p[b]) % mod;
			ans = (ans + is * ks) % mod;
		}
		printf ("%lld\n", ans);
	}

	return 0;
}