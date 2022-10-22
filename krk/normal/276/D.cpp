#include <cstdio>
using namespace std;

typedef long long ll;

ll a, b;
ll res;

int main()
{
	scanf("%I64d %I64d", &a, &b);
	for (ll i = 62; i >= 0; i--)
		if (a <= (1ll << i) - 1ll && 1ll << i <= b) {
			res |= (1ll << i) - 1ll;
			res |= 1ll << i;
			break;
		} else if (1ll << i <= a) {
			a -= 1ll << i; b -= 1ll << i;
		}
	printf("%I64d\n", res);
	return 0;
}