#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,x,y,cnt,res;
pair<int,int> ans[1111111];
vector<int> g[111111];
void dfs(int i,int fa,int e,int t)//t<=e+1
{
	if (fa && (int)g[i].size()==1) 
	{
		ans[++cnt]=make_pair(i,e);
		if (t-1!=e) ans[++cnt]=make_pair(i,t-1);
		if (fa) ans[++cnt]=make_pair(fa,t);
		return;
	}
	int lst=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		lst++;
	}
	int pos=0;
	ans[++cnt]=make_pair(i,e);
	while(e<res && lst)
	{
		lst--;
		while(pos<g[i].size() && g[i][pos]==fa) pos++;
		dfs(g[i][pos],i,e+1,e+1);
		e++;pos++;
	}
	if (!lst)
	{
		if (fa)
		{
			if (e!=t-1) ans[++cnt]=make_pair(i,t-1);
			ans[++cnt]=make_pair(fa,t);
		}
		return;
	}
	ans[++cnt]=make_pair(i,t-1-lst);
	e=t-1-lst;
	while(lst)
	{
		e++;lst--;
		while(pos<g[i].size() && g[i][pos]==fa) pos++;
		dfs(g[i][pos],i,e,e);
		pos++;
	}
	if (fa) ans[++cnt]=make_pair(fa,t);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
	{
		res=max(res,(int)g[i].size());
	}
	if (n==1)
	{
		printf("1\n");
		printf("1 0\n");
		return 0;
	}
	dfs(1,0,0,0);
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return Accepted;
}