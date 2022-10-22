#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, q;
ll a[Maxn];
ll sum;

int main()
{
	scanf("%d %d", &n, &q);
	scanf("%I64d", &a[0]);
	for (int i = 1; i < n; i++) {
		scanf("%I64d", &a[i]);
		a[i] += a[i - 1];
	}
	while (q--) {
		ll b; scanf("%I64d", &b);
		sum += b;
		int ind = upper_bound(a, a + n, sum) - a;
		if (ind == n) { sum = 0; printf("%d\n", n); }
		else printf("%d\n", n - ind);
	}
	return 0;
}