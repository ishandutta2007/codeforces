#include <bits/stdc++.h>
using namespace std;

int tc;
int n, k;
vector<int> a;
long long mod = 998244353;
long long* inv = new long long[200005] - 1;

long long nCr(int x, int y) {
	if (x - y < y) y = x - y;
	long long ans = 1;
	for (int i = 2; i <= y; i++) {
		ans *= inv[i];
		ans = ans % mod;
	}
	for (int i = x - y + 1; i <= x; i++) {
		ans *= i;
		ans = ans % mod;
	}
	return ans;
}

int main() {
	inv[1] = 1;
	for (int i = 2; i < 200005; i++) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		a.clear(); a.resize(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		if (n == 1) {
			printf("1\n");
			continue;
		} 
		
		long long fsum = 0, bsum = 0;
		int i1 = 0, i2 = n-1;
		int fz = 0, bz = 0;
		long long ans = 1;
		while (i1 <= i2) {
			while (a[i1] == 0 && i1 <= i2) {
				fz++;
				i1++;
			}
			while (a[i2] == 0 && i2 >= i1) {
				bz++;
				i2--;
			}
			if (fsum == bsum) {
				if (i1 > i2) { // middle region
					fz--; bz--;
					break;
				} else {
					int x = bz + 1;
					int y = fz + 1;
					if (fsum == 0) x--, y--;
					if (x < y) swap(x, y);
					ans *= nCr(x + y, y);
					ans = ans % mod;
				}
			}
			if (fsum < bsum) {
				fz = 0;
				fsum += a[i1];
				i1++;
			} else {
				bz = 0;
				bsum += a[i2];
				i2--;
			}
		}
		if (fsum == bsum) {
			//printf("%d %d\n", fz, bz);
			for (int i = 0; i <= fz + bz; i++) {
				ans *= 2;
				ans = ans % mod;
			}
		}
		printf("%lld\n", ans % mod);		
	}
	return 0;
}