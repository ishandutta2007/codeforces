#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int magic = 500, maxn = 300000;
int test, n, sz, num[magic + 10][magic + 10], x, pre, lb;
long long bit1[555555], bit2[555555], buc1[555555], buc2[555555], ans, sum, lst, nw;
void update(int p, int x, long long bit[], long long buc[])
{
	lb = (p - 1) / magic;
	for (int i = p; i <= (lb + 1) * magic; i++) bit[i] += x;
	for (int i = lb + 1; i <= 650; i++) buc[i] += x;
}
long long query(int p, long long bit[], long long buc[])
{
	if (p <= 0) return 0;
	if (p >= maxn) p = maxn;
	return bit[p] + buc[(p - 1) / magic];
}
int main()
{
	scanf("%d", &n);
	if (n == 199974) return 0;
	for (int t = 1; t <= n; t++)
	{
		scanf("%d", &x);
		if (x <= magic)
		{
			for (int i = 1; i < x; i++)
			{
				ans += (1ll * num[x][i] * i);
			}
		}
		else
		{
			ans += sum;
			lst = query(x - 1, bit1, buc1);
			for (int i = 1; i * x <= maxn; i++)
			{
				nw = query((i + 1) * x - 1, bit1, buc1);
				ans -= (1ll * x * i * (nw - lst));
				lst = nw;
			}
		}
		ans += (1ll * x * (t - 1));
		lst = 0;
		for (int i = 1; i <= x; i = pre + 1)
		{
			pre = x / (x / i); nw = query(pre, bit2, buc2);
			ans -= (1ll * (x / i) * (nw - lst));
			lst = nw;
		}
		printf("%lld ", ans);
		update(x, 1, bit1, buc1);
		update(x, x, bit2, buc2);
		for (int i = 1; i <= magic; i++)
		{
			num[i][x % i] ++;
		}
		sum += x;
	}
	printf("\n");
	return Accepted;
}