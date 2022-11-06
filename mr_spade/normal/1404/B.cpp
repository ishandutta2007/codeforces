#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a,b,da,db,flag,dep,depb,dfk;
int d0,d1,d2;
vector<int> e[N];
int dfs(int x,int father,int d)
{
	int res=d,cur;
	dep=max(dep,d);
	if(x==b)
		flag=1,depb=d;
	for(int y:e[x])
		if(y!=father)
		{
			cur=dfs(y,x,d+1);
			dfk=max(dfk,res+cur-2*d);
			res=max(res,cur);
		}
	return res;
}
inline void solve()
{
	int x,y;
	register int i;
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);d0=d1=0;
	for(i=1;i<=n;i++)
		e[i].clear();
	for(i=1;i<=n-1;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	if(db<=2*da)
		return puts("Alice"),void();
	for(int y:e[a])
	{
		flag=0;dep=0;dfk=0;
		dfs(y,a,1);
		if(flag)
		{
			if(depb<=da)
				return puts("Alice"),void();
			d0=dep;d2=dfk;
		}
		else
			d1=max(d1,dep);
	}
	if(d0+d1>=2*da+1||d2>=2*da+1)
		puts("Bob");
	else
		puts("Alice");
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}