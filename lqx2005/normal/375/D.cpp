#include<bits/stdc++.h>
using namespace std;
const int N=100000;
struct node
{
	int id,l,r,k;
}q[N+5];
int n,m,Time,L[N+5],R[N+5];
int c[N+5],s[N+5],r[N+5];
int vis[N+5];
vector<int> g[N+5];
int ans[N+5];
int t[N+5];
int lowbit(int x)
{
	return x&(-x);
}
void Add(int x,int v)
{
	for(int i=x;i<=N;i+=lowbit(i)) t[i]+=v;
	return; 
}
int Sum(int x)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)) sum+=t[i];
	return sum;
}
void dfs(int u,int fa)
{
	Time++;
	s[Time]=u;
	L[u]=Time;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
	R[u]=Time;
	return;
}
bool cmp(node a,node b)
{
	if(r[a.l]!=r[b.l]) return r[a.l]<r[b.l];
	if(r[a.l]%2==0) return a.r<b.r;
	return a.r>b.r;
}
void add(int x)
{
	if(vis[x]!=0) Add(vis[x],-1);
	vis[x]++;
	if(vis[x]!=0) Add(vis[x],1);
	return;
}
void del(int x)
{
	if(vis[x]!=0) Add(vis[x],-1);
	vis[x]--;
	if(vis[x]!=0) Add(vis[x],1);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	int u,v;
	int S=(int)sqrt((double)n)+1;
	for(int i=1;i<=n;i++) r[i]=i/S;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&v,&k);
		q[i].id=i;
		q[i].l=L[v];
		q[i].r=R[v];
		q[i].k=k;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		int lx=q[i].l,rx=q[i].r;
		while(r<rx) r++,add(c[s[r]]);
		while(lx<l) l--,add(c[s[l]]);
		while(lx>l) del(c[s[l]]),l++;
		while(rx<r) del(c[s[r]]),r--;
		ans[q[i].id]=Sum(N)-Sum(q[i].k-1);
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}