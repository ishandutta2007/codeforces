#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define mid ((l+r)/2)
#define pb push_back
int n,ans,a[N],ps[N],L[N],R[N],z[N],dp[N];char a1[N];
vector<int> e[N];struct Point {int len,link,ch[26];};
struct SuffixAutomaton
{
	int nw,cntP;Point pt[N];SuffixAutomaton() {nw=cntP=1;}
	void ext(int vl)
	{
		int p=nw,p1,t;nw=++cntP;pt[nw].len=pt[p].len+1;ps[pt[nw].len]=nw;
		while(p && !pt[p].ch[vl]) pt[p].ch[vl]=nw,p=pt[p].link;
		if(!p) {pt[nw].link=1;return;}p1=pt[p].ch[vl];
		if(pt[p1].len==pt[p].len+1) {pt[nw].link=p1;return;}
		pt[t=++cntP]=pt[p1];pt[t].len=pt[p].len+1;pt[nw].link=pt[p1].link=t;
		while(p && pt[p].ch[vl]==p1) pt[p].ch[vl]=t,p=pt[p].link;
	}
}SAM;
struct SegmentTree
{
	int sg[N*4];void pu(int p) {sg[p]=max(sg[p*2],sg[p*2+1]);}
	void upd(int p,int l,int r,int x,int vl)
	{
		if(l==r) {sg[p]=max(sg[p],vl);return;}
		if(x<=mid) upd(p*2,l,mid,x,vl);else upd(p*2+1,mid+1,r,x,vl);pu(p);
	}
	int qMx(int p,int l,int r,int qL,int qR)
	{
		if(l>=qL && r<=qR) return sg[p];int res=0;
		if(qL<=mid) res=qMx(p*2,l,mid,qL,qR);
		if(qR>mid) res=max(res,qMx(p*2+1,mid+1,r,qL,qR));return res;
	}
}SGT;
void dfs(int u) {L[u]=++L[0];for(auto v:e[u]) dfs(v);R[u]=L[0];}
int main()
{
	scanf("%d %s",&n,a1+1);reverse(a1+1,a1+n+1);
	for(int i=1;i<=n;++i) SAM.ext(a[i]=a1[i]-'a');
	for(int i=2;i<=SAM.cntP;++i) e[SAM.pt[i].link].pb(i);dfs(1);
	for(int i=1,t=0,len=0,p=1,p1=1,p2=1;i<=n;++i)
	{
		++len;++t;p=SAM.pt[p].ch[a[i]];
		if(i>1) p1=SAM.pt[p1].ch[a[i]],p2=SAM.pt[p2].ch[a[i-1]];
		while(1)
		{
			if(SGT.qMx(1,1,SAM.cntP,L[p1],R[p1])>=t-1) break;
			if(SGT.qMx(1,1,SAM.cntP,L[p2],R[p2])>=t-1) break;--len;--t;
			if(len<=SAM.pt[SAM.pt[p].link].len) p=SAM.pt[p].link;
			if(len-1<=SAM.pt[SAM.pt[p1].link].len) p1=SAM.pt[p1].link;
			if(len-1<=SAM.pt[SAM.pt[p2].link].len) p2=SAM.pt[p2].link;
			SGT.upd(1,1,SAM.cntP,L[z[i-t]],dp[i-t]);
		}z[i]=p;dp[i]=t;ans=max(ans,t);
	}printf("%d\n",ans);return 0;
}