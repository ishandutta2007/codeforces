#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ii Norm(ii p)
{
	ll g = gcd(p.first, p.second);
	return ii(p.first / g, p.second / g);
}

ii Mult(ii a, ii b)
{
	a = Norm(a), b = Norm(b);
	ii ma = Norm(ii(a.first, b.second)), mb = Norm(ii(b.first, a.second));
	ii c = ii(ma.first * mb.first, ma.second * mb.second);
	return Norm(c);
}

ii Add(ii a, ii b)
{
	a = Norm(a), b = Norm(b);
	ll lcm = a.second / gcd(a.second, b.second) * b.second;
	ii c = ii(lcm / a.second * a.first + lcm / b.second * b.first, lcm);
	return Norm(c);
}

const int Maxn = 100005;

int n;
int a[Maxn];
ii res = ii(0, 1);

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		ii has = ii(n - i, n);
		ii add = Mult(ii(ll(i) * ll(n - i), 1), ii(2, n));
		has = Add(has, add);
		has = Mult(has, ii(a[i] - (i? a[i - 1]: 0), 1));
		res = Add(res, has);
	}
	printf("%I64d %I64d\n", res);
	return 0;
}