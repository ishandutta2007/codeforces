#include <cstdio>
using namespace std;

typedef long long ll;

ll k, a, b;
ll res;

ll F(ll x)
{
	return x / k + 1;
}

int main()
{
	scanf("%I64d %I64d %I64d", &k, &a, &b);
	if (b < 0) res = F(-a) - F(-b - 1);
	else if (0 < a) res = F(b) - F(a - 1);
    else res = F(-a) + F(b) - 1;
    printf("%I64d\n", res);
	return 0;
}