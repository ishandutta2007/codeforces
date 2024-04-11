#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll n, m, k;

int main()
{
	scanf("%d", &q);
	while (q--) {
		scanf("%I64d %I64d %I64d", &n, &m, &k);
		if (k < n || k < m) printf("-1\n");
		else {
			ll a = n % 2 == k % 2? k: k - 1;
			ll b = m % 2 == k % 2? k: k - 1;
			if (a == k - 1 && b == k - 1) printf("%I64d\n", k - 2ll);
			else printf("%I64d\n", min(a, b));
		}
	}
    return 0;
}