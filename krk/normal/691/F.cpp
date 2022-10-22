#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 3000005;

int n;
int a[Maxn];
int has[Maxn];
ll res[Maxn];
int m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); has[a[i]]++;
	}
	for (int i = 1; i < Maxn; i++) if (has[i] > 0)
		for (int j = i; j < Maxn; j += i)
			if (i == j / i) res[j] += ll(has[i]) * (has[i] - 1);
			else res[j] += ll(has[i]) * has[j / i];
	sort(a, a + n);
	int r = n - 1;
	for (int i = 0; i < n; i++) {
		while (r >= 0 && ll(a[i]) * a[r] >= Maxn) r--;
		int tk = min(n - 1 - i, n - 1 - r);
		res[Maxn - 1] += 2ll * tk;
	}
	for (int i = Maxn - 2; i > 0; i--)
		res[i] += res[i + 1];
	scanf("%d", &m);
	while (m--) {
		int q; scanf("%d", &q);
		printf("%I64d\n", res[q]);
	}
	return 0;
}