#include<iostream>
#include<cstdio>
using namespace std;
int h[101000],nxt[201000],K=0,to[201000];
int siz[201000];int e=0;
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;}
void dfs1(int x,int f)
{
	siz[x]=1;
	for(int i=h[x];i;i=nxt[i])if(to[i]!=f)dfs1(to[i],x),siz[x]+=siz[to[i]];
	if(siz[x]%2==0&&x!=1)e++;
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		ins(u,v);ins(v,u);
	}
	if(n&1)return 0*puts("-1");
	dfs1(1,0);cout<<e;
	return 0;
}