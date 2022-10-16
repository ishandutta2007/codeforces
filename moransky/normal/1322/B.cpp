#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 4e5 + 5;

int n, a[N], b[N], ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int k = 0; k < 29; k++) {
		int S = 1 << (k + 1);
		for (int i = 1; i <= n; i++) b[i] = a[i] % S;
		sort(b + 1, b + 1 + n);
		LL s = 0;
		int L = 1 << k, R = (1 << (k + 1)) - 1;
		for (int i = 1, j = n, k = n; i <= n; i++) {
			while (j && b[j] + b[i] >= L) j--;
			while (k && b[k] + b[i] > R) k--;
			if (k > j) s += k - j; 
			if (L <= 2 * b[i] && 2 * b[i] <= R) s--;
		}
		L = (1 << k) + (1 << (k + 1)), R = (1 << (k + 2)) - 1;
		for (int i = 1, j = n, k = n; i <= n; i++) {
			while (j && b[j] + b[i] >= L) j--;
			while (k && b[k] + b[i] > R) k--;
			if (k > j) s += k - j; 
			if (L <= 2 * b[i] && 2 * b[i] <= R) s--;
		}
		s >>= 1;
		if (s & 1) ans |= 1 << k;
	}
	printf("%d\n", ans);
	return 0;
}