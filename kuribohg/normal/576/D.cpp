#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=155;
const int INF=2000000000;
struct Edge
{
	int x,y,d;
	friend bool operator<(const Edge &p,const Edge &q)
	{
		return p.d<q.d;
	}
}E[MAXN];
int n,m,pre,Ans=INF;
int head[MAXN],to[MAXN*2+5],next[MAXN*2+5],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
int dis[MAXN],q[MAXN],l,r;
void BFS(int S)
{
	q[l=r=1]=S,dis[S]=0;
	while(l<=r)
	{
		int x=q[l++];
		for(int i=head[x];i;i=next[i])
			if(dis[to[i]]==INF) dis[to[i]]=dis[x]+1,q[++r]=to[i];
	}
}
struct Matrix
{
	int r,c;
	bitset<MAXN> a[MAXN];
	Matrix(){r=c=0;for(int i=1;i<=150;i++) a[i].reset();}
	Matrix(int n)
	{
		r=c=n;
		for(int i=1;i<=n;i++)
			a[i].reset(),a[i][i]=1;
	}
}ans,A;
Matrix mul(const Matrix &p,const Matrix &q)
{
	Matrix res;
	res.r=p.r,res.c=q.c;
	for(int i=1;i<=p.r;i++)
		for(int j=1;j<=p.c;j++)
			if(p.a[i][j]) res.a[i]|=q.a[j];
	return res;
}
Matrix qpow(const Matrix &x,int n)
{
	Matrix p=x;
	Matrix con(::n);
	while(n)
	{
		if(n&1) con=mul(con,p);
		p=mul(p,p);
		n>>=1;
	}
	return con;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].d);
	sort(E+1,E+m+1);
	if(E[1].d!=0) {puts("Impossible");return 0;}
	A.r=A.c=n;
	ans.r=1,ans.c=n;
	ans.a[1][1]=1;
	int L=1;
	while(L<=m)
	{
		int R=L;
		while(R+1<=m&&E[R+1].d==E[L].d) R++;
		ans=mul(ans,qpow(A,E[L].d-pre));
		for(int i=L;i<=R;i++)
		{
			A.a[E[i].x][E[i].y]=1;
			adde(E[i].y,E[i].x);
		}
		for(int j=1;j<=n;j++) dis[j]=INF;
		BFS(n);
		pre=E[L].d;
		for(int j=1;j<=n;j++) if(ans.a[1][j]&&dis[j]!=INF) Ans=min(Ans,pre+dis[j]);
		L=R+1;
	}
	for(int i=1;i<=n;i++) dis[i]=INF;
	BFS(n);
	for(int i=1;i<=n;i++)
		if(ans.a[1][i]&&dis[i]!=INF) Ans=min(Ans,pre+dis[i]);
	if(Ans==INF) puts("Impossible");
	else printf("%d\n",Ans);
	return 0;
}