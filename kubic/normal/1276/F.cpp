#pragma GCC optimize(2)
#pragma GCC optimize("Ofast") 
#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define INF 1e9
#define ll long long
#define miit map<int,int>::iterator
#define siit set<int>::iterator 
#define set(a,v) memset(a,v,sizeof(a))
int n,lg[N],rt[N];char a[N];ll ans,vl[N];set<int> z[N];
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
struct SuffixArray
{
	int n,lim,a[N],SA[N],rk[N],tp[N],bc[N],mn[N][25];
	SuffixArray() {n=lim=0;}
	void rSort()
	{
		for(int i=0;i<=lim;++i) bc[i]=0;for(int i=1;i<=n;++i) ++bc[rk[tp[i]]];
		for(int i=1;i<=lim;++i) bc[i]+=bc[i-1];for(int i=n;i>=1;--i) SA[bc[rk[tp[i]]]--]=tp[i];
	}
	void build()
	{
		for(int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;for(int i=1;i<=n;++i) rk[i]=a[i],tp[i]=i;rSort();
		for(int l=1,cnt;l<=n;l<<=1)
		{
			cnt=0;for(int i=1;i<=l;++i) tp[++cnt]=n-i+1;
			for(int i=1;i<=n;++i) if(SA[i]>l) tp[++cnt]=SA[i]-l;rSort();swap(rk,tp);cnt=rk[SA[1]]=1;
			for(int i=2;i<=n;++i)
				rk[SA[i]]=(tp[SA[i]]==tp[SA[i-1]] && tp[SA[i]+l]==tp[SA[i-1]+l])?cnt:++cnt;
			if(n==cnt) break;lim=cnt;
		}
		for(int i=1,j,t=0;i<=n;++i) if(rk[i]>1)
		{
			if(t) --t;j=SA[rk[i]-1];
			while(i+t<=n && j+t<=n && a[i+t]==a[j+t]) ++t;mn[rk[i]][0]=t;
		}
		for(int i=1;i<=lg[n];++i) for(int j=1;j+(1<<i)-1<=n;++j)
			mn[j][i]=min(mn[j][i-1],mn[j+(1<<i-1)][i-1]);
	}
	int qMn(int l,int r) {if(!l || !r) return 0;int t=lg[r-l];return min(mn[l+1][t],mn[r-(1<<t)+1][t]);}
}SA;
int qPr(int x,int v) {siit it=z[x].lower_bound(v);return it==z[x].begin()?0:*--it;}
int qSf(int x,int v) {siit it=z[x].lower_bound(v);return it==z[x].end()?0:*it;}
void merge(int x,int y)
{
	int t,pr,sf;
	for(siit it=z[y].begin();it!=z[y].end();++it)
		t=*it,pr=qPr(x,t),sf=qSf(x,t),vl[x]+=SA.qMn(pr,t)+SA.qMn(t,sf)-SA.qMn(pr,sf),z[x].insert(t);
	z[y].clear();
}
void dfs(int u,int dep)
{
	int t=min(SFT.pt[u].len,SFT.n-SFT.pt[u].bg),v,hv=0;dep+=t;
	if(SFT.pt[u].len>SFT.n) {if(dep<n-1) z[u].insert(SA.rk[dep+2]);rt[u]=u;return;}
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it)
	{v=it->second;dfs(v,dep);if(!hv || z[rt[v]].size()>z[rt[hv]].size()) hv=v;}rt[u]=rt[hv];
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it)
	{v=it->second;if(v!=hv) merge(rt[u],rt[v]);}ans-=vl[rt[u]]*t;
}
int main()
{
	scanf("%s",a+1);n=SA.n=strlen(a+1);SA.lim=100;ans=(1ll*n*(n-1)>>1)+2;
	for(int i=1;i<=n;++i) ans+=1ll*(i-1)*(n-i),SFT.ext(a[i]-'a'),SA.a[n-i+1]=a[i]-'a'+1;
	for(int i=1;i<=SFT.cntP;++i) ans+=min(SFT.pt[i].len,SFT.n-SFT.pt[i].bg+1);SFT.ext(26);SA.build();
	for(int i=1,lst=0;i<=n;++i) if(SA.SA[i]>1) ans-=SA.qMn(lst,i),lst=i;
	dfs(1,0);for(int i=1;i<=SFT.cntP;++i) SFT.pt[i]=(SuffixTree::Point) {0,0,0},SFT.pt[i].ch.clear();
	SFT=SuffixTree();for(int i=2;i<=n;++i) SFT.ext(a[i]-'a');
	for(int i=1;i<=SFT.cntP;++i) ans+=min(SFT.pt[i].len,SFT.n-SFT.pt[i].bg+1);printf("%lld\n",ans);
	return 0;
}