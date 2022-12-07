#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=400010;
const int INF=1000000000;
int n,a[MAXN];
int head[MAXN],to[MAXN],next[MAXN],w[MAXN],cnt=1;
inline void adde(int f,int t,int ww)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
bool used[MAXN];
int size[MAXN],G[MAXN],K,root;
void getroot(int x,int fa)
{
	size[x]=1,G[x]=0;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa&&!used[to[i]])
		{
			getroot(to[i],x);
			size[x]+=size[to[i]];
			G[x]=max(G[x],size[to[i]]);
		}
	G[x]=max(G[x],K-size[x]);
	if(G[x]<G[root]) root=x;
}
int sub;
double ans=1e50,con;
void dfs(int x,int fa,int d)
{
	con+=d*sqrt(d)*a[x];
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa) dfs(to[i],x,d+w[i]);
}
double GetAns(int x)
{
	con=0;
	dfs(x,-1,0);
	return con;
}
double delta[MAXN];
void DFS(int x,int fa,int d,int id)
{
	delta[id]+=sqrt(d)*a[x];
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa) DFS(to[i],x,d+w[i],id);
}
void work(int x)
{
	root=0;
	getroot(x,-1);
	int rt=root;
	used[rt]=true;
	double A=GetAns(rt);
	if(A<ans) ans=A,sub=rt;
	for(int i=head[rt];i;i=next[i])
		if(!used[to[i]]) delta[to[i]]=0,DFS(to[i],rt,w[i],to[i]);
	int nex=0;
	for(int i=head[rt];i;i=next[i])
		if(!used[to[i]]&&delta[to[i]]>delta[nex]) nex=to[i];
	if(nex)
	{
		getroot(nex,-1);
		K=size[nex];
		work(nex);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),adde(x,y,z);
	K=n,G[0]=INF;
	work(1);
	printf("%d %.010lf\n",sub,ans);
	return 0;
}