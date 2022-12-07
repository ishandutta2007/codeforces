#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,m,fa[MAXN],a[MAXN],tar[MAXN],seq[MAXN],tot;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa)
			DFS(to[i],x);
	if(tar[x]) seq[++tot]=x;
	if(a[x]!=x&&a[x]!=fa&&a[x]!=a[fa]) {puts("-1");exit(0);}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),fa[y]=x;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),tar[a[i]]=1;
	for(int i=1;i<=n;i++) if(!fa[i]) DFS(i,-1);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d\n",seq[i]);
	return 0;
}