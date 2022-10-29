#include <bits/stdc++.h>
using namespace std;

int tc, n;
long long k;
vector<long long> a;

long long gcd(long long x, long long y) {
	if (x < y) swap(x, y);
	if (x == 0) return y;
	if (y == 0) return x;
	return gcd(y, x%y);
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %lld", &n, &k);
		a.clear(); a.resize(n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a.begin(), a.end());
		long long g = abs(a[1] - a[0]);
		for (int i = 1; i < n-1; i++) {
			g = gcd(g, a[i+1] - a[i]);
		}
		if (((k % g) + g) % g == ((a[0] % g) + g) % g) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}