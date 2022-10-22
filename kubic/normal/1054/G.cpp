#include <bits/stdc++.h>
using namespace std;
#define N 2005
int T,n,m,cntE,gl,fa[N];bool vs[N*N];char a[N];
bitset<N> z[N];struct Edge {int u,v,w;}e[N*N];
bool cmp(Edge x,Edge y) {return x.w>y.w;}
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
bool merge(int u,int v)
{u=findRt(u);v=findRt(v);if(u==v) return 0;fa[u]=v;return 1;}
void slv()
{
	scanf("%d %d",&n,&m);cntE=gl=0;
	for(int i=1;i<=n;++i) z[i]=0,fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		scanf("%s",a+1);--gl;
		for(int j=1;j<=n;++j) if(a[j]=='1') ++gl,z[j][i]=1;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<i;++j)
		e[++cntE]=(Edge) {i,j,(z[i]&z[j]).count()};
	sort(e+1,e+cntE+1,cmp);
	for(int i=1;i<=cntE;++i)
	{vs[i]=merge(e[i].u,e[i].v);if(vs[i]) gl-=e[i].w;}
	if(gl) {puts("NO");return;}puts("YES");
	for(int i=1;i<=cntE;++i) if(vs[i])
		printf("%d %d\n",e[i].u,e[i].v);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}