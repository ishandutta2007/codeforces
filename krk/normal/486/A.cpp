#include <cstdio>
using namespace std;

typedef long long ll;

ll n;
ll res;

int main()
{
	scanf("%I64d", &n);
	res = (n + 1) / 2;
	if (n % 2) res = -res;
	printf("%I64d\n", res);
	return 0;
}