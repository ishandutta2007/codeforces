#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define pb push_back
int n,m,gr,tp,vs1[N],vs2[N],z[N],st1[N],st2[N],a[N],ps[N];
bool tg[N];struct Edge {int v,w;};vector<Edge> e1[N],e2[N];
struct Node {int op,x,y;}ans[N];
bool cmp(Edge x,Edge y) {return x.w<y.w;}
bool dfs(int u1,int u2)
{
	if(vs1[u1]==gr || vs2[u2]==gr) return z[u1]==u2;
	vs1[u1]=vs2[u2]=gr;z[u1]=u2;
	if(e1[u1].size()!=e2[u2].size()) return 0;
	for(int i=0;i<e1[u1].size();++i)
		if(e1[u1][i].w!=e2[u2][i].w) return 0;
	for(int i=0;i<e1[u1].size();++i)
		if(!dfs(e1[u1][i].v,e2[u2][i].v)) return 0;return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,w;i<=n;++i) for(int j=1;j<=m;++j)
	{
		scanf("%d",&w);if(!w) continue;
		e1[i].pb((Edge) {n+j,w});e1[n+j].pb((Edge) {i,w});
	}
	for(int i=1,w;i<=n;++i) for(int j=1;j<=m;++j)
	{
		scanf("%d",&w);if(!w) continue;
		e2[i].pb((Edge) {n+j,w});e2[n+j].pb((Edge) {i,w});
	}
	for(int i=1;i<=n+m;++i)
	{
		sort(e1[i].begin(),e1[i].end(),cmp);
		sort(e2[i].begin(),e2[i].end(),cmp);
	}++gr;tg[gr]=1;
	for(int i=1;i<=n;++i)
	{
		if(e1[i].empty()) st1[++st1[0]]=i,vs1[i]=gr;
		if(e2[i].empty()) st2[++st2[0]]=i,vs2[i]=gr;
	}if(st1[0]!=st2[0]) {printf("-1\n");return 0;}
	for(int i=1;i<=st1[0];++i) z[st1[i]]=st2[i];st1[0]=st2[0]=0;
	for(int i=1;i<=m;++i)
	{
		if(e1[n+i].empty()) st1[++st1[0]]=n+i,vs1[n+i]=gr;
		if(e2[n+i].empty()) st2[++st2[0]]=n+i,vs2[n+i]=gr;
	}if(st1[0]!=st2[0]) {printf("-1\n");return 0;}
	for(int i=1;i<=st1[0];++i) z[st1[i]]=st2[i];
	if(n<=m)
	{
		for(int i=1;i<=n;++i) if(!tg[vs1[i]])
			for(int j=1;j<=n;++j) if(!tg[vs2[j]])
			{++gr;tg[gr]=dfs(i,j);if(tg[gr]) break;}
	}
	else
	{
		for(int i=1;i<=m;++i) if(!tg[vs1[n+i]])
			for(int j=1;j<=m;++j) if(!tg[vs2[n+j]])
			{++gr;tg[gr]=dfs(n+i,n+j);if(tg[gr]) break;}
	}
	for(int i=1;i<=n+m;++i)
	{
		if(!tg[vs1[i]] || !tg[vs2[i]])
		{printf("-1\n");return 0;}a[i]=ps[i]=i;
	}
	for(int i=1,t;i<=n;++i)
	{
		t=ps[i];if(t!=z[i]) ans[++tp]=(Node) {1,t,z[i]};
		swap(ps[i],ps[a[z[i]]]);swap(a[t],a[z[i]]);
	}
	for(int i=1,t;i<=m;++i)
	{
		t=ps[n+i];if(t!=z[n+i]) ans[++tp]=(Node) {2,t-n,z[n+i]-n};
		swap(ps[n+i],ps[a[z[n+i]]]);swap(a[t],a[z[n+i]]);
	}printf("%d\n",tp);
	for(int i=1;i<=tp;++i)
		printf("%d %d %d\n",ans[i].op,ans[i].x,ans[i].y);return 0;
}