#include <cstdio>
using namespace std;

typedef long long ll;

int n;

int main()
{
	scanf("%d", &n);
	if (n == 3) printf("1\n");
	else printf("%I64d\n", ll(n) * n - 4ll * n + 4);
	return 0;
}