#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll t, a, b;
ll ok;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%I64d %I64d %I64d", &t, &a, &b);
	if (a > b) swap(a, b);
	ll g = gcd(a, b);
	ll lcm = t + 1;
	if (a / g <= t / b) lcm = a / g * b;
	ll lst = t / lcm;
	ok += lst * a;
	if (lst) ok--;
	ll cur = lst * lcm;
	if (cur == 0) cur = 1;
	ok += min(lst * lcm + a, t + 1) - cur;
	g = gcd(ok, t);
	ok /= g; t /= g;
	printf("%I64d/%I64d\n", ok, t);
	return 0;
}