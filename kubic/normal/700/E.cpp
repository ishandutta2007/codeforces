#pragma GCC optimize(2)
#pragma GCC optimize("Ofast") 
#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define INF 1e9
#define ll long long
#define miit map<int,int>::iterator
#define mid (l+r>>1)
#define set(a,v) memset(a,v,sizeof(a)) 
int n,st[N],dfn[N],dep[N],sz[N],ps[N],sf[N],mx[N],dp[N];char a[N];
int min(int x,int y) {return x<y?x:y;}
struct SuffixTree
{
	int n,nw,rm,cntP,a[N];struct Point {int bg,len,link;map<int,int> ch;}pt[N];
	SuffixTree() {n=rm=0;nw=cntP=1;pt[0].len=INF;}
	int New(int bg=0,int len=0,int link=0) {pt[++cntP]=(Point) {bg,len,link};return cntP;} 
	void ext(int v)
	{
		a[++n]=v;++rm;
		for(int lst=1;rm;)
		{
			while(rm>pt[pt[nw].ch[a[n-rm+1]]].len) rm-=pt[nw=pt[nw].ch[a[n-rm+1]]].len;
			int &p=pt[nw].ch[a[n-rm+1]],c=a[pt[p].bg+rm-1],t;
			if(!p || v==c) {pt[lst].link=nw;lst=nw;if(!p) p=New(n,INF,1);else break;}
			else
			{
				t=New(pt[p].bg,rm-1,1);pt[t].ch[c]=p;pt[t].ch[v]=New(n,INF,1);
				pt[p].bg+=rm-1;pt[p].len-=rm-1;p=pt[lst].link=t;lst=t;
			}if(nw==1) --rm;else nw=pt[nw].link;
		}
	}
}SFT;
struct PresidentTree
{
	int cntS,rt[N];struct Seg {int v,ch[2];}sg[N*20];
	PresidentTree() {cntS=0;}
	void upd(int p,int l,int r,int x,int v,int &nwP)
	{
		sg[nwP=++cntS]=sg[p];sg[nwP].v+=v;if(l==r) return;
		if(x<=mid) upd(sg[p].ch[0],l,mid,x,v,sg[nwP].ch[0]);
		else upd(sg[p].ch[1],mid+1,r,x,v,sg[nwP].ch[1]);
	}
	int qSm(int p,int l,int r,int qL,int qR)
	{
		if(!p || qL>qR) return 0;if(l>=qL && r<=qR) return sg[p].v;int res=0;
		if(qL<=mid) res=qSm(sg[p].ch[0],l,mid,qL,qR);
		if(qR>mid) res+=qSm(sg[p].ch[1],mid+1,r,qL,qR);return res;
	}
}PT;
bool chk(int u,int v)
{
	if(v==1) return 1;int t1=PT.qSm(PT.rt[dfn[v]+sz[v]-1],1,n,ps[u],ps[u]+dep[u]-dep[v]),t2;
	t2=PT.qSm(PT.rt[dfn[v]-1],1,n,ps[u],ps[u]+dep[u]-dep[v]);return t1-t2>1;
}
void dfs1(int u,int f)
{
	int v;dfn[u]=++dfn[0];sz[u]=1;dep[u]=dep[f]+min(SFT.pt[u].len,SFT.n-SFT.pt[u].bg+1);
	if(SFT.pt[u].len>SFT.n)
		ps[u]=SFT.n-dep[u]+1,sf[ps[u]]=u,PT.upd(PT.rt[dfn[u]-1],1,n,ps[u],1,PT.rt[dfn[u]]);
	else PT.rt[dfn[u]]=PT.rt[dfn[u]-1];
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it)
		v=it->second,dfs1(v,u),sz[u]+=sz[v],ps[u]=min(ps[u]?ps[u]:INF,ps[v]);
}
void dfs2(int u,int nw)
{
	int v;st[++st[0]]=u;while(nw<=st[0] && chk(u,st[nw])) ++nw;mx[u]=st[nw-1];
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it) v=it->second,dfs2(v,nw);--st[0];
}
int dfs3(int u)
{
	if(u==1) return 0;if(~dp[u]) return dp[u];
	return dp[u]=max(dfs3(SFT.pt[u].link),dfs3(mx[u])+1);
}
int main()
{
	set(dp,-1);scanf("%d %s",&n,a+1);for(int i=1;i<=n;++i) SFT.ext(a[i]-'a');SFT.ext(26);
	dfs1(1,0);dfs2(1,1);for(int i=1;i<SFT.n;++i) SFT.pt[sf[i]].link=sf[i+1];
	printf("%d\n",dfs3(sf[1]));return 0;
}