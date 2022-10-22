#include <cstdio>
using namespace std;

typedef long long ll;

ll n;
int res;

int main()
{
	scanf("%I64d", &n);
	for (ll h = 1; 3ll * h * (h + 1) / 2 - h <= n; h++)
		if ((n + h) % 3 == 0) res++;
	printf("%d\n", res);
	return 0;
}