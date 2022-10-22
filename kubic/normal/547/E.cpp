#include <bits/stdc++.h>
using namespace std;
#define N 800005
#define INF 1e9
#define miit map<int,int>::iterator
int n,m,bg[N],len[N],ps[N],v[N],ans[N];char a[N];
struct Query {int id,l,r;};vector<Query> q[N]; 
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
	int find(int bg,int len)
	{
		int p=1,t;
		while(1)
		{
			t=pt[p].ch[a[bg]];
			if(len<=pt[t].len) return t;bg+=pt[t].len;len-=pt[t].len;p=t;
		}return -1;
	}
}SFT;
void upd(int x) {for(;x<=n;x+=x&-x) ++v[x];}
int qSm(int x) {int res=0;for(;x;x-=x&-x) res+=v[x];return res;}
void dfs(int u)
{
	for(int i=0;i<q[u].size();++i) ans[q[u][i].id]-=qSm(q[u][i].r)-qSm(q[u][i].l-1);
	if(SFT.pt[u].len>SFT.n) upd(SFT.pt[u].bl);
	for(miit it=SFT.pt[u].ch.begin();it!=SFT.pt[u].ch.end();++it) dfs(it->second);
	for(int i=0;i<q[u].size();++i) ans[q[u][i].id]+=qSm(q[u][i].r)-qSm(q[u][i].l-1);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",a+1);len[i]=strlen(a+1);bg[i]=SFT.n+1; 
		for(int j=1;j<=len[i];++j) SFT.ext(a[j]-'a',i);SFT.ext(i+25,i); 
	}for(int i=1;i<=n;++i) ps[i]=SFT.find(bg[i],len[i]);
	for(int i=1,x,l,r;i<=m;++i) scanf("%d %d %d",&l,&r,&x),q[ps[x]].push_back((Query) {i,l,r});
	dfs(1);for(int i=1;i<=m;++i) printf("%d\n",ans[i]);return 0;
}