#include <cstdio>
using namespace std;

const int Maxn = 300005;

int n, t;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 1; i < n; i++)
		scanf("%d", &a[i]);
	int v = 1;
	while (v != t && v != n)
		v += a[v];
	printf("%s\n", v == t? "YES": "NO");
	return 0;
}