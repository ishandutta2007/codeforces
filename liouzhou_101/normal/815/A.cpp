#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 110;

int n, m;
int g[MAXN][MAXN];

int a[MAXN], b[MAXN];

int ans;
int ta[MAXN], tb[MAXN];

bool check(int s)
{
	a[1] = s;
	for (int j = 1; j <= m; ++ j)
	{
		b[j] = g[1][j] - a[1];
		if (b[j] < 0) return false;
	}
	for (int i = 2; i <= n; ++ i)
	{
		a[i] = g[i][1] - b[1];
		if (a[i] < 0) return false;
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			if (a[i]+b[j] != g[i][j])
				return false;
	int sum = 0;
	for (int i = 1; i <= n; ++ i)
		sum += a[i];
	for (int j = 1; j <= m; ++ j)
		sum += b[j];
	if (sum < ans)
	{
		ans = sum;
		for (int i = 1; i <= n; ++ i)
			ta[i] = a[i];
		for (int j = 1; j <= m; ++ j)
			tb[j] = b[j];
	}
	return true;
}

int main()
{
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			scanf("%d", &g[i][j]);
	ans = 1000000000;
	for (int i = 0; i <= g[1][1]; ++ i)
	{
		check(i);
	}
	if (ans == 1000000000)
		puts("-1");
	else
	{
		printf("%d\n", ans);
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= ta[i]; ++ j)
				printf("row %d\n", i);
		for (int i = 1; i <= m; ++ i)
			for (int j = 1; j <= tb[i]; ++ j)
				printf("col %d\n", i);
	}
	
	return 0;
}