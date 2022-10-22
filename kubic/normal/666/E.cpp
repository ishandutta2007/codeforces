#pragma GCC optimize(2)
#pragma GCC optimize("Ofast") 
#include <bits/stdc++.h>
using namespace std;
#define N 2000005
#define M 50005
#define INF 1e9
#define mid (l+r>>1)
#define miit map<int,int>::iterator
int n,m,c,rt[N],ps[N],dep[N],fa[N][25],ans[N][2];char a[N];struct Query {int id,l,r;};vector<Query> q[N];
int min(int x,int y) {return x<y?x:y;}
int max(int x,int y) {return x>y?x:y;}
struct SuffixTree
{
	int n,nw,rm,cntP,a[N];struct Point {int bg,len,link,bl;map<int,int> ch;}pt[N];
	SuffixTree() {n=rm=0;nw=cntP=1;pt[0].len=INF;}
	int New(int bg=0,int len=0,int link=0,int bl=0) {pt[++cntP]=(Point) {bg,len,link,bl};return cntP;} 
	void ext(int v,int bl)
	{
		a[++n]=v;++rm;
		for(int lst=1;rm;)
		{
			while(rm>pt[pt[nw].ch[a[n-rm+1]]].len) rm-=pt[nw=pt[nw].ch[a[n-rm+1]]].len;
			int &p=pt[nw].ch[a[n-rm+1]],c=a[pt[p].bg+rm-1],t;
			if(!p || v==c) {pt[lst].link=nw;lst=nw;if(!p) p=New(n,INF,1,bl);else break;}
			else
			{
				t=New(pt[p].bg,rm-1,1,bl);pt[t].ch[c]=p;pt[t].ch[v]=New(n,INF,1,bl);
				pt[p].bg+=rm-1;pt[p].len-=rm-1;p=pt[lst].link=t;lst=t;
			}if(nw==1) --rm;else nw=pt[nw].link;
		}
	}
}SFT;
struct SegmentTree
{
	int cntS,bin[M];struct Seg {int v,ps,ch[2];}sg[M*20];
	SegmentTree() {cntS=bin[0]=0;}
	int New() {int p=bin[0]?bin[bin[0]--]:++cntS;sg[p]=(Seg) {0,0,{0,0}};return p;}
	void pu(int p)
	{
		int t,ch[2]={sg[p].ch[0],sg[p].ch[1]};t=sg[ch[0]].v<sg[ch[1]].v?ch[1]:ch[0];
		sg[p].v=sg[t].v;sg[p].ps=sg[t].ps;
	}
	void upd(int &p,int l,int r,int x)
	{
		if(!p) p=New();if(l==r) {++sg[p].v;sg[p].ps=l;return;}
		if(x<=mid) upd(sg[p].ch[0],l,mid,x);else upd(sg[p].ch[1],mid+1,r,x);pu(p);
	}
	int merge(int pL,int pR,int l,int r)
	{
		if(!pL || !pR) return pL|pR;if(l==r) {sg[pL].v+=sg[pR].v;return pL;}
		sg[pL].ch[0]=merge(sg[pL].ch[0],sg[pR].ch[0],l,mid);
		sg[pL].ch[1]=merge(sg[pL].ch[1],sg[pR].ch[1],mid+1,r);bin[++bin[0]]=pR;pu(pL);return pL;
	}
	Seg qMx(int p,int l,int r,int qL,int qR)
	{
		if(!p) return (Seg) {0,qL};if(l>=qL && r<=qR) return sg[p];Seg tL,tR;
		if(qL<=mid) tL=qMx(sg[p].ch[0],l,mid,qL,qR);if(qR>mid) tR=qMx(sg[p].ch[1],mid+1,r,qL,qR);
		if(qL<=mid && qR>mid) return (Seg) {max(tL.v,tR.v),tL.v<tR.v?tR.ps:tL.ps};
		else if(qL<=mid) return tL;else if(qR>mid) return tR;return (Seg) {0,qL};
	}
}SGT;
void dfs1(int u,int f)
{
	fa[u][0]=f;for(int i=1;i<=20;++i) fa[u][i]=fa[fa[u][i-1]][i-1];
	dep[u]=dep[f]+min(SFT.pt[u].len,SFT.n-SFT.pt[u].bg+1);if(SFT.pt[u].len>SFT.n) ps[SFT.n-dep[u]+1]=u;
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it) dfs1(it->second,u);
}
void dfs2(int u)
{
	if(SFT.pt[u].len>SFT.n && SFT.pt[u].bl<=m) SGT.upd(rt[u],1,m,SFT.pt[u].bl);int v;
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it)
		v=it->second,dfs2(v),rt[u]=SGT.merge(rt[u],rt[v],1,m);
	for(int i=0,id;i<q[u].size();++i)
	{
		SegmentTree::Seg t=SGT.qMx(rt[u],1,m,q[u][i].l,q[u][i].r);
		id=q[u][i].id;ans[id][0]=t.ps;ans[id][1]=t.v;
	}
}
int main()
{
	scanf("%s %d",a+1,&m);n=strlen(a+1);for(int i=1;i<=n;++i) SFT.ext(a[i]-'a',m+1);SFT.ext(26,m+1);
	for(int i=1,len;i<=m;++i)
	{
		scanf("%s",a+1);len=strlen(a+1);
		for(int j=1;j<=len;++j) SFT.ext(a[j]-'a',i);SFT.ext(i+26,i);
	}dfs1(1,0);scanf("%d",&c);
	for(int i=1,l,r,qL,qR,u;i<=c;++i)
	{
		scanf("%d %d %d %d",&qL,&qR,&l,&r);u=ps[l];
		for(int j=20;j>=0;--j) if(dep[fa[u][j]]>r-l) u=fa[u][j];q[u].push_back((Query) {i,qL,qR});
	}dfs2(1);for(int i=1;i<=c;++i) printf("%d %d\n",ans[i][0],ans[i][1]);return 0;
}