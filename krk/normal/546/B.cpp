#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 3005;

int n;
int a[Maxn];
int lst;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	lst = 0;
	for (int i = 0; i < n; i++)
		if (lst >= a[i]) { res += lst + 1 - a[i]; lst++; }
		else lst = a[i];
	printf("%d\n", res);
	return 0;
}