#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int lft[Maxn];

bool Check(int m)
{
	for (int i = 0; i < m; i++)
		lft[i] = Maxn;
	for (int i = n - 1; i >= 0; i--) {
		int b = 0;
		for (int j = 1; j < m; j++)
			if (lft[j] > lft[b]) b = j;
		if (lft[b] == 0) return false;
		lft[b] = min(lft[b] - 1, a[i]);
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 1; i <= n; i++)
		if (Check(i)) { printf("%d\n", i); break; }
	return 0;
}