#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=600010;
int n,Q,p[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int size[MAXN],ans[MAXN];
void dfs(int x,int fa)
{
	int ch=0;
	size[x]=1;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa)
		{
			ch++;
			dfs(to[i],x);
			size[x]+=size[to[i]];
		}
	if(ch==0) ans[x]=x;
	else
	{
		int o=0;
		for(int i=head[x];i;i=next[i])
			if(to[i]!=fa&&size[to[i]]>=size[o]) o=to[i];
		o=ans[o];
		while(size[o]<size[x]-size[o]) o=p[o];
		ans[x]=o;
	}
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=2;i<=n;i++) scanf("%d",&p[i]),adde(i,p[i]);
	dfs(1,-1);
	while(Q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}