#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 10000005
#define mid ((l+r)/2)
#define pb push_back
//#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define gc getchar
const int INF=1e9;char buf[LIM],*P1=buf,*P2=buf;
int T,n,m,c,cntD,ansL,ansR,a[N],b[N],o[N],ds[N],st[N],fa[N],L[N],R[N];
vector<int> vc[N];struct Seg {int vl,tg;}sg[N*4];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void pu(int p) {sg[p].vl=max(sg[p*2].vl,sg[p*2+1].vl);}
void mdf(int p,int vl) {sg[p].vl+=vl;sg[p].tg+=vl;}
void pd(int p) {mdf(p*2,sg[p].tg);mdf(p*2+1,sg[p].tg);sg[p].tg=0;}
void build(int p,int l,int r)
{sg[p].vl=sg[p].tg=0;if(l==r) return;build(p*2,l,mid);build(p*2+1,mid+1,r);}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
int qry(int p,int l,int r)
{
	if(sg[p].vl<1) return 0;if(l==r) return l;pd(p);
	if(sg[p*2].vl>0) return qry(p*2,l,mid);return qry(p*2+1,mid+1,r);
}
void slv()
{
	n=rd();m=rd();c=cntD=st[0]=0;
	for(int i=1;i<=n;++i) a[i]=rd();for(int i=1;i<=n;++i) b[a[i]]=rd();
	for(int i=1;i<=n;++i) if(b[i]) ds[++cntD]=b[i];else ++c;
	for(int i=1;i<c;++i) o[i]=rd(),ds[++cntD]=o[i];ds[++cntD]=1;ds[++cntD]=INF;
	sort(ds+1,ds+cntD+1);cntD=unique(ds+1,ds+cntD+1)-ds-1;
	for(int i=1;i<=cntD;++i) vc[i].clear();build(1,1,cntD);
	for(int i=1;i<=n;++i) if(b[i]) b[i]=lower_bound(ds+1,ds+cntD+1,b[i])-ds;
	for(int i=1,t;i<c;++i) t=lower_bound(ds+1,ds+cntD+1,o[i])-ds,vc[t].pb(-t);
	for(int i=1,t;i<=n;++i)
	{
		t=0;while(st[0] && a[i]>st[st[0]]) t=st[st[0]--];
		fa[t]=a[i];fa[a[i]]=st[st[0]];st[++st[0]]=a[i];
	}ansL=1;ansR=cntD;for(int i=0;i<=n;++i) L[i]=1,R[i]=cntD;
	for(int i=n;i;--i) {R[i]=R[fa[i]];if(b[i]) R[i]=min(R[i],b[i]);}
	for(int i=1;i<=n;++i) {if(b[i]) L[i]=max(L[i],b[i]);L[fa[i]]=max(L[fa[i]],L[i]);}
	for(int i=1;i<=n;++i) if(L[i]>R[i]) ansR=0;else if(!b[i]) vc[L[i]].pb(R[i]);
	for(int i=cntD,t;i;--i)
	{
		for(auto j:vc[i]) upd(1,1,cntD,(j>0?j:-j),cntD,(j>0?1:-1));
		if(sg[1].vl>1) ansR=0;t=qry(1,1,cntD);if(t) ansL=max(ansL,i),ansR=min(ansR,t); 
	}
	for(int i=1,vl;i<=m;++i)
	{vl=rd();if(vl>=ds[ansL] && vl<=ds[ansR]) printf("YES\n");else printf("NO\n");}
}
int main() {T=rd();while(T--) slv();return 0;}