#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
ll k;
ll x[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %I64d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%I64d", &x[i]);
		sort(x, x + n);
		ll g = 0;
		for (int i = 0; i + 1 < n; i++)
			g = gcd(g, x[i + 1] - x[i]);
		if (abs(k - x[0]) % g == 0)
			printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}