#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;

int n;
ii has[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &has[i].second, &has[i].first);
	sort(has, has + n);
	int tim = 0;
	for (int i = 0; i < n; i++)
		if (tim < has[i].second) { res++; tim = has[i].first; }
	printf("%d\n", res);
	return 0;
}