#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
ll a[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	sort(a, a + n);
	ll g = 0;
	for (int i = 0; i + 1 < n; i++)
		g = gcd(g, a[i + 1] - a[i]);
	for (int i = 0; i < m; i++) {
		ll b; scanf("%I64d", &b);
		printf("%I64d%c", gcd(a[0] + b, g), i + 1 < m? ' ': '\n');
	}
    return 0;
}