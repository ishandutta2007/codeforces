#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define MN 401
#define MM 250010

struct xxx{
	int r, c, v, id;
	xxx(){}
	xxx(int A, int B, int C, int D) {r = A; c = B; v = C; id = D;}
};

int f[MN][MN]; long long Ans[MM];
std::vector<xxx> v[MN];
int a[MN];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for(int i = 1; i <= m; i++)
	{
		int l, r, c, V; scanf("%d%d%d%d", &l, &r, &c, &V);
		v[l].push_back(xxx(r, c, V + 1, i));
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++) f[j][1] = a[j] - a[i];
		
		for(int k = 2; k <= n + 1; k++)
		{
			int now = i;
			f[i][k] = 0;
			for(int j = i + 1; j <= n; j++)
			{
				while(std::max(a[j] - a[now + 1], f[now + 1][k - 1]) < std::max(a[j] - a[now], f[now][k - 1])) now++;
				f[j][k] = std::max(a[j] - a[now], f[now][k - 1]);
			}
		}
		
		int S = v[i].size();
		for(int j = 0; j < S; j++)
		{
			xxx e = v[i][j];
			Ans[e.id] = 1ll * f[e.r][e.v] * e.c;
		}
	}
	
	long long ans = 0;
	for(int i = 1; i <= m; i++) ans = std::max(ans, Ans[i]);
	printf("%lld\n", ans);
}