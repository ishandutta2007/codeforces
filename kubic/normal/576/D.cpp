#include <bits/stdc++.h>
using namespace std;
#define N 155
int n,m,ans=2e9,q[N],dst[N],e1[N][N];bool vs[N];
struct Edge {int u,v,w;}e[N]; 
struct Matrix
{
	bitset<N> a[N];
	Matrix(bool fl=0)
	{
		for(int i=1;i<=n;++i) a[i]=0;
		if(fl) for(int i=1;i<=n;++i) a[i][i]=1;
	}
	Matrix operator * (Matrix t)
	{
		Matrix tmp,res;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j) tmp.a[i][j]=a[j][i];
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
			res.a[i][j]=(tmp.a[j]&t.a[i]).any();return res;
	}
}X;
struct Vector
{
	bitset<N> a;
	Vector() {a=0;}
	Vector operator * (Matrix t)
	{
		Vector res;
		for(int i=1;i<=n;++i) res.a[i]=(a&t.a[i]).any();return res;
	}
}nw;
bool cmp(Edge x,Edge y) {return x.w<y.w;}
void qPow(Matrix x,int y) {for(;y;y/=2,x=x*x) if(y&1) nw=nw*x;}
void bfs(int lim)
{
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(int i=1;i<=n;++i)
			if(~e1[u][i] && e1[u][i]<=lim && !vs[i])
				vs[i]=1,q[++q[1]]=i,dst[i]=dst[u]+1;
	} 
}
int main()
{
	scanf("%d %d",&n,&m);nw.a[1]=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) e1[i][j]=-1;
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d %d %d",&u,&v,&w),e[i]=(Edge) {u,v,w},e1[u][v]=w;
	sort(e+1,e+m+1,cmp);
	for(int i=1,lst=0;i<=m;++i)
	{
		if(e[i].w>lst) qPow(X,e[i].w-lst),lst=e[i].w;
		X.a[e[i].v][e[i].u]=1;q[0]=2;q[1]=1;
		for(int j=1;j<=n;++j)
		{dst[j]=0;if(nw.a[j]) vs[j]=1,q[++q[1]]=j;else vs[j]=0;}
		bfs(e[i].w);if(vs[n]) ans=min(ans,lst+dst[n]);
	}if(ans>=2e9) puts("Impossible");else printf("%d\n",ans);return 0;
}