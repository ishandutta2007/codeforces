#include<bits/stdc++.h>
#define f fflush(stdout)
typedef long long ll;
using namespace std;
const int Log = 55;
const int N = 30;
int n, q;
ll a[N][N];
ll p2[Log + 5];
void put(int x, int y)
{
	printf("%d %d\n", x, y);
	f;
	return;
}
int main()
{
	p2[0] = 1;
	for(int i = 1; i <= Log; i++) p2[i] = p2[i - 1] * 2;
	scanf("%d", &n);
	memset(a, -1, sizeof(a));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == 1 && j == 1) a[i][j] = 0;
			else if(i == n && j == n) a[i][j] = 0;
			else
			{
				if(i % 2 == 1)  a[i][j] = 0;
				else a[i][j] = p2[i + j - 3];
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			printf("%lld ", a[i][j]);
		}
		printf("\n");
	}
	f;
	scanf("%d", &q);
	ll k;
	for(int amo = 1; amo <= q; amo++)
	{
		scanf("%lld", &k);
		put(1, 1);
		int nx = 1, ny = 1;
		for(int i = 1; i <= 2 * n - 3 ; i++)
		{
			if(k & p2[i - 1])
			{
				if(a[nx + 1][ny] == p2[i - 1]) nx++;
				else ny++;
			}
			else
			{
				if(a[nx + 1][ny] == 0) nx++;
				else ny++;
			}
			put(nx, ny);
		}
		put(n, n);
	}
	return 0;
}