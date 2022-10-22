#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;
long long a[200005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
		sort(a, a + n, greater<long long>());
		for (int i = 1; i < 1 + k; i++) {
			a[0] += a[i];
		}
		printf("%lld\n", a[0]);
	}
	return 0;
}