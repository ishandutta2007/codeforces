#include <cstdio>
using namespace std;

const int Maxn = 4;

int a[Maxn];
int res;

bool Arit(int &res)
{
	int d = a[1] - a[0];
	for (int i = 2; i < Maxn; i++)
		if (a[i] - a[i - 1] != d) return false;
	res = a[Maxn - 1] + d;
	return true;
}

bool Geom(int &res)
{
	int v = a[1], u = a[0];
	for (int i = 1; i + 1 < Maxn; i++)
		if (a[i] * v % u || a[i] * v / u != a[i + 1]) return false;
	if (a[Maxn - 1] * v % u) return false;
	res = a[Maxn - 1] * v / u;
	return true;
}

int main()
{
	for (int i = 0; i < Maxn; i++) scanf("%d", &a[i]);
	if (Arit(res)) printf("%d\n", res);
	else if (Geom(res)) printf("%d\n", res);
	else printf("42\n");
	return 0;
}