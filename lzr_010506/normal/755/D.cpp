#include <bits/stdc++.h>
using namespace std;

int n, k;
int c[1000010];
long long Ans = 1;

void Add(int x, int k)
{
	while(x <= n)
	{
		c[x] += k;
		x += x & (-x);
	}
}
int Query(int x)
{
	int ans = 0;
	while(x)
	{
		ans += c[x];
		x -= x & (-x);
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &k);
	if(n < 2 * k) k = n - k;
	int now = 1;
	for(int i = 1; i <= n; i ++)
	{
		int Next = now + k;
		if(Next > n)
		{
			Next -= n;
			Ans += Query(Next - 1) + Query(n) - Query(now);
		}
		else Ans += Query(Next - 1) - Query(now);
		Ans ++;
		Add(now, 1);
		Add(Next, 1);
		now = Next;
		printf("%I64d ", Ans);
	}
	return 0;
}