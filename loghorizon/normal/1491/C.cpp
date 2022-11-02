// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 5005;

int n, a[N];

LL cnt[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 0; i <= n; i++) cnt[i] = 0;
		LL ans = 0;
		for (int i = 1; i <= n; i++) {
			cnt[0] += cnt[1];
			for (int j = 1; j < n; j++) cnt[j] = cnt[j + 1];
			cnt[n] = 0;
			int t = a[i] - 1;
			if (cnt[0] < t) ans += t - cnt[0], cnt[0] = t;
			cnt[0] -= t;
			for (int j = 2; j <= min(a[i], n); j++)
				cnt[j]++; 
		}
		printf("%lld\n", ans);
	}
	return 0;
}