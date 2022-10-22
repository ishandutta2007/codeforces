#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define INF 1e9
#define ll long long
#define mid (l+r>>1)
#define miit map<int,int>::iterator
int n,m;ll ans[N];bool tg[N];char a[N];
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
	int cntS,bin[N],rt[N];struct Seg {int v,ch[2];}sg[N*20];
	SegmentTree() {cntS=bin[0]=0;}
	int New(int v=0) {int p=bin[0]?bin[bin[0]--]:++cntS;sg[p]=(Seg) {v,{0,0}};return p;}
	void pu(int p) {sg[p].v=sg[sg[p].ch[0]].v+sg[sg[p].ch[1]].v;}
	void upd(int &p,int l,int r,int x)
	{
		if(!p) p=New();if(l==r) {sg[p].v=1;return;}
		if(x<=mid) upd(sg[p].ch[0],l,mid,x);else upd(sg[p].ch[1],mid+1,r,x);pu(p);
	}
	int merge(int pL,int pR,int l,int r)
	{
		if(!pL || !pR) return pL|pR;if(l==r) {sg[pL].v|=sg[pR].v;return pL;}
		sg[pL].ch[0]=merge(sg[pL].ch[0],sg[pR].ch[0],l,mid);
		sg[pL].ch[1]=merge(sg[pL].ch[1],sg[pR].ch[1],mid+1,r);
		pu(pL);bin[++bin[0]]=pR;return pL;
	}
}SGT;
void dfs1(int u)
{
	int v;if(SFT.pt[u].len>SFT.n) SGT.upd(SGT.rt[u],1,SFT.n,SFT.pt[u].bl);
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it)
		v=it->second,dfs1(v),SGT.rt[u]=SGT.merge(SGT.rt[u],SGT.rt[v],1,SFT.n);
	if(SGT.sg[SGT.rt[u]].v>=m) tg[u]=1;
}
void dfs2(int u,int nw)
{
	if(tg[u]) nw+=min(SFT.pt[u].len,SFT.n-SFT.pt[u].bg+1);
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it) dfs2(it->second,nw);
	if(SFT.pt[u].len>SFT.n) ans[SFT.pt[u].bl]+=nw;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,len;i<=n;++i)
	{
		scanf("%s",a+1);len=strlen(a+1);
		if(m==1) {printf("%I64d ",1ll*len*(len+1)>>1);continue;}
		for(int j=1;j<=len;++j) SFT.ext(a[j]-'a',i);SFT.ext(i+25,i);
	}if(m==1) return 0;dfs1(1);dfs2(1,0);for(int i=1;i<=n;++i) printf("%I64d ",ans[i]);return 0;
}