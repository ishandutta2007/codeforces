#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n > 0) printf("%d\n", n);
	else {
		n = -n;
		printf("%d\n", -(n / 100 * 10 + min(n % 10, n % 100 / 10)));
	}
	return 0;
}