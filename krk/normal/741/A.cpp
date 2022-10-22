#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 105;

ll l;
int n;
int c[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int Get(int a)
{
	int cur = a;
	for (int i = 1; i <= n + 5; i++) {
		cur = c[cur];
		if (cur == a) return i;
	}
	return Maxn;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	l = 1;
	for (int i = 1; i <= n; i++) {
		int g = Get(i);
		if (g == Maxn) { printf("-1\n"); return 0; }
		l = lcm(l, g);
	}
	if (l % 2 == 0) l /= 2;
	printf("%I64d\n", l);
	return 0;
}