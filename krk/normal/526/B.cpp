#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 10005;

int n;
int a[Maxn];
int f[Maxn];

int getRes(int lvl, int v)
{
	int res = 0;
	if (lvl < n) res += getRes(lvl + 1, 2 * v) + getRes(lvl + 1, 2 * v + 1);
	int fa = a[2 * v] + f[2 * v], fb = a[2 * v + 1] + f[2 * v + 1];
	int mn = min(fa, fb), mx = max(fa, fb);
	res += mx - mn; f[v] = mx;
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i < 1 << n + 1; i++)
		scanf("%d", &a[i]);
	printf("%d\n", getRes(1, 1));
	return 0;
}