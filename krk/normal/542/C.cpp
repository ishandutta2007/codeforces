#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 205;

int n;
int f[Maxn];
bool cyc[Maxn];
ll res = 1ll;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

void Find(int x)
{
	int mem = x;
	for (int i = 1; i <= Maxn; i++) {
		x = f[x];
		if (x == mem) { res = res / gcd(res, i) * i; cyc[mem] = true; break; }
	}
}

ll Get(int x)
{
	ll res = 0ll;
	while (!cyc[x]) { x = f[x]; res++; }
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i]);
	for (int i = 1; i <= n; i++)
		Find(i);
	ll mn = 1ll;
	for (int i = 1; i <= n; i++)
		mn = max(mn, Get(i));
	ll tims = mn / res;
	ll cres = tims * res;
	if (cres < mn) cres += res;
	printf("%I64d\n", cres);
	return 0;
}