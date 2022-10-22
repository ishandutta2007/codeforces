#include <cstdio>
using namespace std;

typedef long long ll;

ll h;
ll n;
ll res;

int main()
{
	scanf("%I64d %I64d", &h, &n);
	for (ll i = h - 1; i >= 0; i--)
		if (n <= (1ll << i)) { res++; n = (1ll << i) - n + 1; }
		else { res += 1ll << i + 1ll; n -= 1ll << i; }
	printf("%I64d\n", res);
	return 0;
}