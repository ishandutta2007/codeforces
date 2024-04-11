#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b, c;

int main()
{
	scanf("%I64d %I64d %I64d", &a, &b, &c);
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	if (2ll * (a + b) <= c) printf("%I64d\n", a + b);
	else {
		ll x = (2ll * a + 2ll * b - c) / 3;
		while (3ll * x >= (2ll * a + 2ll * b - c)) x--;
		printf("%I64d\n", max(x + (c - x) / 2, a + b - (x + 1)));
	}
	return 0;
}