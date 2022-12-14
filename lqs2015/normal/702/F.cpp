#include<bits/stdc++.h>
using namespace std;
int n,m,ls[222222],rs[222222],sz[222222],rd[222222],rt,l,r,rt1,rt2,rt3;
int val[222222],num[222222],lazyv[222222],lazyn[222222],ans[222222];
pair<int,int> a[222222],b[222222];
int Get(int x)
{
	return ((rand()<<13)+rand())%x+1;
}
void pushup(int node)
{
	sz[node]=sz[ls[node]]+sz[rs[node]]+1;
}
void push(int x,int vl,int nm)
{
	val[x]+=vl;num[x]+=nm;
	lazyv[x]+=vl;lazyn[x]+=nm;
}
void pushdown(int x)
{
	if (lazyv[x] || lazyn[x])
	{
		if (ls[x]) push(ls[x],lazyv[x],lazyn[x]);
		if (rs[x]) push(rs[x],lazyv[x],lazyn[x]);
		lazyv[x]=lazyn[x]=0;
	}
}
int merge(int x,int y)
{
	if (!x || !y) return x^y;
	pushdown(x);pushdown(y);
	if (rd[x]<=rd[y])
	{
		rs[x]=merge(rs[x],y);
		pushup(x);
		return x;
	}
	else
	{
		ls[y]=merge(x,ls[y]); 
		pushup(y);
		return y;
	}
}
void split(int x,int &rt1,int &rt2,int y)
{
	if (!x) 
	{
		rt1=rt2=0;
		return;
	}
	pushdown(x);
	if (val[x]>=y)
	{
		rt2=x;
		split(ls[x],rt1,ls[rt2],y);
		pushup(x);
	}
	else
	{
		rt1=x;
		split(rs[x],rs[rt1],rt2,y);
		pushup(x);
	}
}
void check(int x,int y)
{
	if (!x) return;
	pushdown(x);
	int rtt,ll=ls[x],rr=rs[x];
	ls[x]=rs[x]=0;
	val[x]-=y;num[x]++;
	split(rt1,rt1,rtt,val[x]);
	rt1=merge(rt1,x);rt1=merge(rt1,rtt);
	check(ll,y);
	check(rr,y);
}
void getans(int x)
{
	if (!x) return;
	pushdown(x);
	ans[x]=num[x];
	getans(ls[x]);getans(rs[x]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].second,&a[i].first);
		a[i].second=-a[i].second;
	}
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i].first);
		b[i].second=i;
	}
	sort(b+1,b+m+1);
	for (int i=1;i<=m;i++) 
	{
		rd[i]=i;sz[i]=1;
		val[b[i].second]=b[i].first;
	}
	random_shuffle(rd+1,rd+m+1);
	rt=b[1].second;
	for (int i=2;i<=m;i++)
	{
		rt=merge(rt,b[i].second);
	}
	for (int i=1;i<=n;i++)
	{
		a[i].second=-a[i].second;
		split(rt,rt1,rt2,a[i].second);
		split(rt2,rt2,rt3,(a[i].second<<1));
		push(rt3,-a[i].second,1);
		check(rt2,a[i].second);
		rt=merge(rt1,rt3);
	}
	getans(rt);
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}