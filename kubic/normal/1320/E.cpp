#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define pb push_back
const int INF=1e9;
int n,m,dfsT,a[N],b[N],h[N],z[N],st[N],vs[N];vector<int> e[N];
struct Point {int fa,dep,sz,hv,tp,dfn1,dfn2;}pt[N];
int f(int x,int w) {return w?(w-1)/h[x]+1:0;}
struct Node
{
	int x,w;Node(int _x=0,int _w=0) {x=_x;w=_w;}
	Node operator + (int t) const {return Node(x,w+t);}
	bool operator < (Node t) const
	{int t1=f(x,w),t2=f(t.x,t.w);return t1==t2?x<t.x:t1<t2;}
	bool operator == (Node t) const {return x==t.x && w==t.w;}
}dp1[N],dp2[N],dp3[N];
bool cmp(int x,int y)
{return (x>0?pt[x].dfn1:pt[-x].dfn2)<(y>0?pt[y].dfn1:pt[-y].dfn2);}
void dfs1(int u,int f)
{
	pt[u].fa=f;pt[u].dep=pt[f].dep+1;pt[u].sz=1;
	for(auto v:e[u]) if(v!=f)
	{dfs1(v,u);pt[u].sz+=pt[v].sz;if(pt[v].sz>pt[pt[u].hv].sz) pt[u].hv=v;}
}
void dfs2(int u,int f)
{
	pt[u].tp=f;pt[u].dfn1=++dfsT;if(pt[u].hv) dfs2(pt[u].hv,f);
	for(auto v:e[u]) if(v!=pt[u].fa && v!=pt[u].hv) dfs2(v,v);pt[u].dfn2=++dfsT;
}
int LCA(int u,int v)
{
	while(pt[u].tp!=pt[v].tp)
	{if(pt[pt[u].tp].dep<pt[pt[v].tp].dep) swap(u,v);u=pt[pt[u].tp].fa;}
	if(pt[u].dep<pt[v].dep) swap(u,v);return v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs1(1,0);dfs2(1,1);scanf("%d",&m);
	for(int i=1,f,d;i<=m;++i)
	{
		Node t;scanf("%d %d",&a[0],&b[0]);z[0]=0;h[0]=1;++vs[0];
		for(int j=1;j<=a[0];++j) scanf("%d %d",&a[j],&h[j]),z[++z[0]]=a[j];
		for(int j=1;j<=b[0];++j) scanf("%d",&b[j]),z[++z[0]]=b[j];
		sort(z+1,z+z[0]+1,cmp);z[0]=unique(z+1,z+z[0]+1)-z-1;
		for(int j=1;j<=z[0];++j) vs[z[j]]=vs[0];
		for(int j=1,t;j<z[0];++j)
		{t=LCA(z[j],z[j+1]);if(vs[t]!=vs[0]) vs[t]=vs[0],z[++z[0]]=t;}
		for(int j=1;j<=z[0];++j) dp1[z[j]]=dp2[z[j]]=dp3[z[j]]=Node(0,INF);
		for(int j=1;j<=a[0];++j) dp1[a[j]]=Node(j,0);
		for(int j=1;j<=z[0] && z[j]>0;++j) z[++z[0]]=-z[j];sort(z+1,z+z[0]+1,cmp);
		for(int j=1;j<=z[0];++j) if(z[j]>0) st[++st[0]]=z[j];else
		{
			--st[0];f=st[st[0]];d=pt[-z[j]].dep-pt[f].dep;t=dp1[-z[j]]+d;
			if(t<dp1[f]) dp2[f]=dp1[f],dp1[f]=t;else if(t<dp2[f]) dp2[f]=t;
		}
		for(int j=1;j<=z[0];++j) if(z[j]>0)
		{
			f=st[st[0]];st[++st[0]]=z[j];d=pt[z[j]].dep-pt[f].dep;t=dp1[z[j]]+d;
			if(f) dp3[z[j]]=min(dp3[f],(dp1[f]==t?dp2[f]:dp1[f]))+d;
		}else --st[0];
		for(int j=1;j<=b[0];++j) printf("%d ",min(dp1[b[j]],dp3[b[j]]).x);
		putchar('\n');
	}return 0;
}