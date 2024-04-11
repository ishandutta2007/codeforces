#include <cstdio>
using namespace std;

int n;
int res;

int main()
{
	scanf("%d", &n);
	int cur = 0;
	while (n--) {
		int a; scanf("%d", &a);
		cur += a;
		if (cur < 0) { res++; cur = 0; }
	}
	printf("%d\n", res);
	return 0;
}