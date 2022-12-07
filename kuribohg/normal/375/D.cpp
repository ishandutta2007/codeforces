#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=300010;
struct Node
{
	int l,r,k,K,id;
	friend bool operator<(const Node &p,const Node &q)
	{
		return (p.K==q.K)?(p.r<q.r):(p.K<q.K);
	}
}Q[MAXN];
int n,K,QAQ,a[MAXN],A[MAXN],f[MAXN],c[MAXN],ans[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int L[MAXN],R[MAXN],dfs_clock;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
	L[x]=++dfs_clock,A[L[x]]=a[x];
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa) DFS(to[i],x);
	R[x]=dfs_clock;
}
int main()
{
	scanf("%d%d",&n,&QAQ);
	K=(int)(sqrt(n)+0.5);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
	DFS(1,-1);
	for(int i=1,x;i<=QAQ;i++) scanf("%d%d",&x,&Q[i].k),Q[i].l=L[x],Q[i].r=R[x],Q[i].K=Q[i].l/K,Q[i].id=i;
	sort(Q+1,Q+QAQ+1);
	for(int i=Q[1].l;i<=Q[1].r;i++) c[++f[A[i]]]++;
	ans[Q[1].id]=c[Q[1].k];
	for(int i=2;i<=QAQ;i++)
	{
		for(int j=Q[i-1].r+1;j<=Q[i].r;j++) c[++f[A[j]]]++;
		for(int j=Q[i].r+1;j<=Q[i-1].r;j++) c[f[A[j]]--]--;
		for(int j=Q[i-1].l;j<Q[i].l;j++) c[f[A[j]]--]--;
		for(int j=Q[i].l;j<Q[i-1].l;j++) c[++f[A[j]]]++;
		ans[Q[i].id]=c[Q[i].k];
	}
	for(int i=1;i<=QAQ;i++) printf("%d\n",ans[i]);
	return 0;
}