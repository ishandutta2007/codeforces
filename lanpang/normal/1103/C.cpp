#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , m , k , ch[maxn] , fa[maxn] , dp[maxn] , md;
vector<int> v[maxn] , vv[maxn] , g;

void dfs(int x , int y)
{
	bool tf = false;
	int i;
	ch[x] = true;
	fa[x] = y;
	dp[x] = dp[y]+1;
	if (dp[md] < dp[x]) md = x;
	for (i = 0 ; i < v[x].size() ; i++)
	{
		if (ch[v[x][i]]) 
		{
			if (v[x][i] != y) vv[x].push_back(v[x][i]);
		}
		else 
		{
			tf = true;
			dfs(v[x][i],x);
		}
	}
	if (!tf) g.push_back(x);
}

void pt(int x , int y)
{
	while (1)
	{
		printf("%d ",x);
		if (x == y) break;
		x = fa[x];
	}
	cout << "\n";
}

int main()
{
	int i , j , x , y;
	cin >> n >> m >> k;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	if (dp[md] >= n/k)
	{
		cout << "PATH\n";
		printf("%d\n",dp[md]-dp[1]+1);
		pt(md,1);
	}
	else
	{
		cout << "CYCLES\n";
		for (i = 0 ; i < min(k,(int)g.size()) ; i++)
		{
			x = vv[g[i]][0];
			y = vv[g[i]][1];
			if ((dp[g[i]]-dp[x]+1)%3 != 0) 
			{
				printf("%d\n",dp[g[i]]-dp[x]+1);
				pt(g[i],x);
			}
			else
			{
				if ((dp[g[i]]-dp[y]+1)%3 != 0) 
				{
					printf("%d\n",dp[g[i]]-dp[y]+1);
					pt(g[i],y);
				}
				else
				{
					if (dp[x] > dp[y]) 
					{
						printf("%d\n",dp[x]-dp[y]+2);
						printf("%d ",g[i]);
						pt(x,y);
					}
					else 
					{
						printf("%d\n",dp[y]-dp[x]+2);
						printf("%d ",g[i]);
						pt(y,x);
					}
				}
			}
		}
	}
	return 0;
}