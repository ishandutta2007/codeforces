#include<bits/stdc++.h>
using namespace std;
int n,sub[1111],x,y,ct,pa[1111],mn,cur,cnt,A,B,pos,arr[1111];
vector<int> g[1111];
pair<int,int> a[1111];
void dfs(int i,int fa)
{
	sub[i]=1;pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];
	}
}
void dft(int i,int fa,int dep)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		printf("%d %d %d\n",i,to,arr[cur]-dep);
		cur++;
		dft(to,i,arr[cur-1]);
	}
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
	dfs(1,0);mn=1e9;
	for (int i=1;i<=n;i++)
	{
		cur=0;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (to==pa[i]) cur=max(cur,n-sub[i]);
			else cur=max(cur,sub[to]);
		}
		if (cur<mn)
		{
			ct=i;
			mn=cur;
		}
	}
	for (int j=0;j<g[ct].size();j++)
	{
		int to=g[ct][j];
		if (to==pa[ct])
		{
			a[++cnt]=make_pair(n-sub[ct],to);
		}
		else
		{
			a[++cnt]=make_pair(sub[to],to);
		}
	}
	sort(a+1,a+cnt+1);
	reverse(a+1,a+cnt+1);
	for (int i=1;i<=cnt;i++)
	{
		A+=a[i].first;
		B=n-1-A;
		if (A*B+A>=(2*n*n/9)) 
		{
			pos=i;
			break;
		}
	}
	for (int i=1;i<=A;i++) arr[i]=i;
	cur=1;
	for (int i=1;i<=pos;i++)
	{
		printf("%d %d %d\n",ct,a[i].second,arr[cur]);
		cur++;
		dft(a[i].second,ct,arr[cur-1]);
	}
	for (int i=1;i<=B;i++) arr[i]=i*A;
	cur=1;
	for (int i=pos+1;i<=cnt;i++)
	{
		printf("%d %d %d\n",ct,a[i].second,arr[cur]);
		cur++;
		dft(a[i].second,ct,arr[cur-1]);
	}
	return 0;
}