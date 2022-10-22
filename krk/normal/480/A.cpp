#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;

int n;
ii p[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p + n);
	int lst = -1000000000;
	for (int i = 0; i < n; i++)
		if (lst <= p[i].second) lst = p[i].second;
		else lst = p[i].first;
	printf("%d\n", lst);
	return 0;
}