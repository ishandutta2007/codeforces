#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, x[200001], c[200011];
long long t, a[200011], b[200001], m[200011];

int main() {
	scanf("%d%lld", &n, &t);
	for (int i = 1; i <= n; i++) 
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	for (int i = 1; i < n; i++)
		if (x[i] > x[i + 1]) {
			printf("No\n");
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (x[i] < i) {
			printf("No\n");
			return 0;
		}
	a[n + 1] = 1e18 * 2;
	memset(m, 127, sizeof(m));
	for (int i = 1; i <= n; i++)
		++c[i], --c[x[i]],
		m[x[i]] = min(m[x[i]], a[x[i] + 1] + t - 1);
	for (int i = 1; i <= n; i++)
		c[i] += c[i - 1];
	long long cur = 1e18 * 3;
	for (int i = n; i; --i) {
		cur = min(cur, m[i]);
		if (cur < a[i] + t) {
			printf("No\n");
			return 0;
		}
		if (c[i] && cur < a[i + 1] + t) {
			printf("No\n");
			return 0;
		}
		b[i] = cur--;
	}
	printf("Yes\n");
	for (int i = 1; i <= n; i++)
		printf("%lld ", b[i]);
	printf("\n");
}