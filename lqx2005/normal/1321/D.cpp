#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
const int inf=10000000;
struct node
{
	int va,id;
	node(int Va=0,int Id=0):va(Va),id(Id){	}
	bool operator <(const node &a)const
	{
		return va>a.va;
	}
};
struct edge
{
	int to,nxt;
}e[maxn+5];
int h[maxn+5],cnt;
int n,m,k;
int d[maxn+5],use[maxn+5];
vector<int> g[maxn+5];
int p[maxn+5];
void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
	return;
}
void dij(int s,int n)
{
	for(int i=1;i<=n;i++) use[i]=0,d[i]=inf;
	priority_queue<node> q;
	q.push(node(0,s));
	d[s]=0;
	while(!q.empty())
	{
		int u=q.top().id;
		q.pop();
		if(use[u]) continue;
		use[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(d[v]>d[u]+1)
			{
				d[v]=d[u]+1;
				q.push(node(d[v],v));
			}
		}
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(v,u);
		g[u].push_back(v);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++) scanf("%d",&p[i]);
	dij(p[k],n);
	int mx=0,mn=0;
	for(int u=1;u<=k-1;u++)
	{
		int ca=0,cb=0;
		for(int i=0;i<(int)g[p[u]].size();i++)
		{
			int v=g[p[u]][i];
			if(d[p[u]]!=d[v]+1) continue;
			if(v==p[u+1]) cb++;
			ca++;
		}
		if(ca==1)
		{
			if(cb==0) mx++,mn++; 
		}
		else
		{
			if(cb==1) mx++;
			else mx++,mn++;
		}
	}
	printf("%d %d\n",mn,mx);
	return 0;
}