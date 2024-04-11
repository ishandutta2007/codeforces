#include <cstdio>
using namespace std;

const int Maxm = 1005;

int n, m, k;
int a[Maxm];
int res;

bool Friend(int ind)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res += bool(a[ind] & 1 << i) != bool(a[m] & 1 << i);
	return res <= k;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= m; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		res += Friend(i);
	printf("%d\n", res);
	return 0;
}