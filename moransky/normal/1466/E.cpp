#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 5e5 + 5, P = 1e9 + 7;

int n, b[N];

LL a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", a + i), b[i] = 0;
		int ans = 0;


		for (int i = 59; ~i; i--) {
			int cnt = 0;
			for (int j = 1; j <= n; j++)
				if (a[j] >> i & 1) cnt++;
			for (int j = 1; j <= n; j++)
				if (a[j] >> i & 1) {
					b[j] = (b[j] + (1ll << i) % P * n) % P;
				} else {
					b[j] = (b[j] + (1ll << i) % P * cnt) % P;
				}
		}

		for (int i = 59; ~i; i--) {
			int cnt = 0;
			for (int j = 1; j <= n; j++)
				if (a[j] >> i & 1) cnt++;
			for (int j = 1; j <= n; j++)
				if (a[j] >> i & 1) {
					ans = (ans + (1ll << i) % P * cnt % P * b[j]) % P;
				} 
		}
		printf("%d\n", ans);
	}	
	return 0;
}