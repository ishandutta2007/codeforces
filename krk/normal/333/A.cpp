#include <cstdio>
using namespace std;

typedef long long ll;

ll n;

int main()
{
	scanf("%I64d", &n);
	ll pw = 1ll;
	while (n % pw == 0ll) pw *= 3ll;
	printf("%I64d\n", n / pw + 1ll);
	return 0;
}