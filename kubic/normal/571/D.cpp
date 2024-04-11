#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define ll long long
int n,m;ll vl[N],ans[N];bool tg1[N],tg2[N],vs1[N],vs2[N];
int cntP1,cntP2,sz[N],rt1[N],rt2[N],ch1[N][2],ch2[N][2];
set<int> z;struct Node {int F[2];char op;}a[N];
struct Query {int id,x,w;};vector<Query> vc1[N],vc2[N];
void upd(int x,int w) {for(;x<=m;x+=x&-x) vl[x]+=w;}
ll qSm(int x) {ll res=0;for(;x;x-=x&-x) res+=vl[x];return res;}
int qPr(int x)
{
	set<int>::iterator it=z.lower_bound(x);
	if(it==z.begin()) return 0;return *--it;
}
void dfs1(int u)
{
	if(!u || vs1[u]) return;vs1[u]=1;
	for(int i=0,id,x,w;i<vc1[u].size();++i)
	{
		id=vc1[u][i].id;x=vc1[u][i].x;w=vc1[u][i].w;
		if(a[id].op=='A') upd(x,w);if(a[id].op=='Q') ans[id]+=w*qSm(x);
	}dfs1(ch1[u][0]);dfs1(ch1[u][1]);
	for(int i=0,id,x,w;i<vc1[u].size();++i)
	{
		id=vc1[u][i].id;x=vc1[u][i].x;w=vc1[u][i].w;
		if(a[id].op=='A') upd(x,-w);
	}
}
void dfs2(int u)
{
	if(!u || vs2[u]) return;vs2[u]=1;
	for(int i=0,id,pr;i<vc2[u].size();++i)
	{
		id=vc2[u][i].id;if(a[id].op=='Z') z.insert(id);
		if(a[id].op=='Q')
		{pr=qPr(id);if(pr) vc1[a[id].F[0]].pb((Query) {id,pr,-1});}
	}dfs2(ch2[u][0]);dfs2(ch2[u][1]);
	for(int i=0,id;i<vc2[u].size();++i)
	{id=vc2[u][i].id;if(a[id].op=='Z') z.erase(id);}
}
int main()
{
	scanf("%d %d",&n,&m);cntP1=cntP2=n;
	for(int i=1;i<=n;++i) rt1[i]=rt2[i]=i,sz[i]=1;
	for(int i=1,F[2];i<=m;++i)
	{
		char op[2];scanf("%s",op);F[0]=F[1]=0;
		if(op[0]=='U' || op[0]=='M') scanf("%d %d",&F[0],&F[1]);
		else scanf("%d",&F[0]);a[i]=(Node) {{F[0],F[1]},op[0]};
		if(op[0]=='U')
		{
			++cntP1;ch1[cntP1][0]=rt1[F[0]];ch1[cntP1][1]=rt1[F[1]];
			sz[cntP1]=sz[rt1[F[0]]]+sz[rt1[F[1]]];
			tg1[rt1[F[0]]]=tg1[rt1[F[1]]]=1;rt1[F[0]]=cntP1;
		}
		if(op[0]=='M')
		{
			++cntP2;ch2[cntP2][0]=rt2[F[0]];ch2[cntP2][1]=rt2[F[1]];
			tg2[rt2[F[0]]]=tg2[rt2[F[1]]]=1;rt2[F[0]]=cntP2;
		}if(op[0]=='A') vc1[rt1[F[0]]].pb((Query) {i,i,sz[rt1[F[0]]]});
		if(op[0]=='Z') vc2[rt2[F[0]]].pb((Query) {i,0,0});
		if(op[0]=='Q') vc1[F[0]].pb((Query) {i,i,1}),vc2[F[0]].pb((Query) {i,0,0});
	}for(int i=1;i<=n;++i) if(!tg2[rt2[i]]) dfs2(rt2[i]);
	for(int i=1;i<=n;++i) if(!tg1[rt1[i]]) dfs1(rt1[i]); 
	for(int i=1;i<=m;++i) if(a[i].op=='Q') printf("%lld\n",ans[i]);return 0; 
}