#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct Edge{int f,t,w;}E[4000010];
int n,a[2010][2010],tot,fa[2010],d[2010],e;
int head[10010],to[10010],w[10010],next[10010],cnt;
inline void adde(int f,int t,int ww)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
bool cmp(const Edge &i,const Edge &j){return i.w<j.w;}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void DFS(int x,int fa)
{
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa) d[to[i]]=d[x]+w[i],DFS(to[i],x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			E[++tot].f=i,E[tot].t=j,E[tot].w=a[i][j];
	sort(E+1,E+tot+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=tot;i++)
		if(E[i].w>0&&find(E[i].f)!=find(E[i].t))
			e++,adde(E[i].f,E[i].t,E[i].w),fa[find(E[i].f)]=find(E[i].t);
	if(e!=n-1) {puts("NO");return 0;}
	for(int i=1;i<=n;i++)
	{
		d[i]=0;
		DFS(i,0);
		for(int j=1;j<=n;j++) if(d[j]!=a[i][j]) {puts("NO");return 0;}
	}
	puts("YES");
	return 0;
}