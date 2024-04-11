#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,m;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int dfn[MAXN],dfs_clock;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int DFS(int x,int father)
{
	int a=0,b=0;
	dfn[x]=++dfs_clock;
	for(int i=head[x];i;i=next[i])
	{
		if((i^father)==1) continue;
		if(!dfn[to[i]])
		{
			int c=DFS(to[i],i);
			if(c!=0) printf("%d %d %d\n",x,to[i],c);
			else
			{
				if(!a) a=to[i];
				else b=to[i];
				if(b) printf("%d %d %d\n",a,x,b),a=b=0;
			}
		}
		else if(dfn[to[i]]<dfn[x])
		{
			if(!a) a=to[i];
			else b=to[i];
			if(b) printf("%d %d %d\n",a,x,b),a=b=0;
		}
	}
	if(a) return a;
	else return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(m&1) {puts("No solution");return 0;}
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y);
	DFS(1,0);
	return 0;
}