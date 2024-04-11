#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int mn1, mx1;
int mn2, mx2;
int mn3, mx3;

int main()
{
	scanf("%d", &n);
	scanf("%d %d", &mn1, &mx1);
	scanf("%d %d", &mn2, &mx2);
	scanf("%d %d", &mn3, &mx3);
	n -= mn1 + mn2 + mn3;
	int tk = min(mx1 - mn1, n); n -= tk;
	printf("%d ", tk + mn1);
	tk = min(mx2 - mn2, n); n -= tk;
	printf("%d %d\n", tk + mn2, n + mn3);
	return 0;
}