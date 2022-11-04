#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , n , m , top , cnt , tim;
int dfn[maxn] , low[maxn] , scc[maxn] , size[maxn] , vis[maxn] , st[maxn];
vector<int> a[maxn];

void tarjan(int x)
{
	dfn[x] = low[x] = ++tim;
	vis[x] = 1;
	st[++top] = x;
	for (int i = 0 ; i < a[x].size() ; i++)
	{
		int y = a[x][i];
		if (!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x],low[y]);
		}
		else 
		{
			if (vis[y]) low[x] = min(low[x],dfn[y]);
		}
	}
	if (dfn[x] == low[x])
	{
		int y;
		cnt++;
		do{
			y = st[top--];
			vis[y] = 0;
			scc[y] = cnt;
			size[cnt]++;
		}while (x != y);
	}
}

int main()
{
	int i , x , y;
	cin >> T;
	while (T--)
	{
		scanf("%d%d",&n,&m);
		top = cnt = tim = 0;
		for (i = 1 ; i <= n ; i++)
		{
			a[i].clear();
			dfn[i] = low[i] = scc[i] = size[i] = vis[i] = st[i] = 0;
		}
		for (i = 1 ; i <= m ; i++)
		{
			scanf("%d%d",&x,&y);
			if (x == y) continue;
			a[x].push_back(y);
		}
		for (i = 1 ; i <= n ; i++)
			if (!dfn[i]) tarjan(i);
		if (cnt == 1)
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n%d %d\n",size[1],n-size[1]);
		for (i = 1 ; i <= n ; i++)
			if (scc[i] == 1) printf("%d ",i);
		printf("\n");
		for (i = 1 ; i <= n ; i++)
			if (scc[i] != 1) printf("%d ",i);
		printf("\n");
	}
	return 0;
}