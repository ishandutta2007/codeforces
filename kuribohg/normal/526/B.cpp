#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,N,a[MAXN],f[MAXN];
int head[MAXN],to[MAXN],next[MAXN],w[MAXN],cnt=1;
int ans,c[MAXN],tot,con;
inline void adde(int f,int t,int ww)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
void DFS(int x,int fa)
{
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa)
			DFS(to[i],x);
	tot=0,con=0;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa) c[++tot]=f[to[i]]+w[i];
	for(int i=1;i<=tot;i++) con=max(con,c[i]);
	for(int i=1;i<=tot;i++) ans+=con-c[i];
	f[x]=con;
}
int main()
{
	scanf("%d",&n);
	N=(1<<(n+1))-1;
	for(int i=2;i<=N;i++) scanf("%d",&a[i]),adde(i,i>>1,a[i]);
	DFS(1,-1);
	printf("%d\n",ans);
	return 0;
}