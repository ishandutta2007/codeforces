#include <stdio.h>

int n, cnt[20], a[200200];

int main()
{
	scanf ("%d", &n); for (int i = 0; i < n; i++){
		int x; scanf ("%d", &x);
		for (int k = 0; k < 20; k++) if (x & (1 << k)) cnt[k]++;
	}

	for (int k = 0; k < 20; k++) for (int i = 0; i < cnt[k]; i++) a[i] |= (1 << k);

	long long ans = 0;
	for (int i = 0; i < n; i++) ans += 1ll * a[i] * a[i];
	printf ("%lld\n", ans);

	return 0;
}