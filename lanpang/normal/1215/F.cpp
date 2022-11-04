#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 4e6+10;
const LL mod = 1e9+7;

int n , m , top , cnt , ti;
int dfn[maxn] , low[maxn] , scc[maxn] , size[maxn] , vis[maxn] , st[maxn];
vector<int> a[maxn];

void tarjan(int x)
{
	dfn[x] = low[x] = ++ti;
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

int nn , p1 , mm , p2 , gg;
struct mmp{
	int l , r;
}f[maxn];
vector<int> ans;

int id(int x , int y)
{
	return x+y*n;
}

int main()
{
	int i , j , k , x , y;
	cin >> p1 >> nn >> mm >> p2;
	for (i = 1 ; i <= p1 ; i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y+nn);
		a[y].push_back(x+nn);
	}
	for (i = 1 ; i <= nn ; i++)
	{
		scanf("%d%d",&f[i].l,&f[i].r);
		a[i+nn].push_back(nn*2+mm+f[i].l);
		a[i+nn].push_back(nn*2+f[i].r+1);
		a[nn*2+f[i].l].push_back(i);
		a[nn*2+mm+f[i].r+1].push_back(i);
	}
	for (i = 1 ; i <= p2 ; i++)
	{
		scanf("%d%d",&x,&y);
		a[x+nn].push_back(y);
		a[y+nn].push_back(x);
	}
	for (i = 2 ; i <= mm ; i++)
	{
		a[nn*2+mm+i].push_back(nn*2+mm+i-1);
		a[nn*2+i-1].push_back(nn*2+i);
	}
	n = nn*2+mm*2;
	for (i = 1 ; i <= n ; i++)
		if (!dfn[i]) tarjan(i);
	for (i = 1 ; i <= nn ; i++)
		if (scc[i] == scc[i+nn])
		{
			cout << "-1\n";
			return 0;
		}
	for (i = 1 ; i <= nn ; i++)
		if (scc[i+nn] < scc[i])
		{
			ans.push_back(i);
			gg = max(gg,f[i].l);
		}
	cout << ans.size() << " " << gg << "\n";
	for (auto i: ans)
		printf("%d ",i);
	cout << "\n";
	return 0;
}