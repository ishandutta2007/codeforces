#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct xxx{int p,s,c;}a[101000];
int h[101000],nxt[201000],K=0,to[201000],w;
int q[101000],d[5010],hh=0,tt=0;
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;} 
bool cmp(xxx a,xxx b){return a.c<b.c;} 
bool check(int x,int tot,long long m)
{
	int sum=0;long long cost=0;
	for(int i=1;i<=w;i++)
	{
		if(d[a[i].p]<=x)
		{
			if(sum+a[i].s>tot)
			{
				cost+=1ll*(tot-sum)*a[i].c;
				if(cost>m)return 0;
				else return 1;
			}
			sum+=a[i].s;cost+=1ll*a[i].s*a[i].c;
			if(cost>m)return 0;
		}
	}
	if(sum<tot||cost>m)return 0;
	return 1;
}
void bfs(int S)
{
	memset(d,127,sizeof(d));int INF=d[0];
	hh=tt=0;q[tt++]=S;d[S]=0;
	while(hh<tt)
	{
		int u=q[hh++];
		for(int i=h[u];i;i=nxt[i])
		{
			if(d[to[i]]==INF)
			{
				d[to[i]]=d[u]+1;
				q[tt++]=to[i];
			}
		}
	}
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;scanf("%d%d",&u,&v);ins(u,v);ins(v,u);
	}
	scanf("%d",&w);
	for(int i=1;i<=w;i++)scanf("%d%d%d",&a[i].p,&a[i].s,&a[i].c);
	sort(a+1,a+w+1,cmp);
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int p,s,c;scanf("%d%d%d",&p,&s,&c);
		bfs(p);
		int l=0,r=n+1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(check(mid,s,c))r=mid;
			else l=mid+1;
		}
		if(r!=n+1)printf("%d\n",r);
		else puts("-1");
	}
	return 0;
}