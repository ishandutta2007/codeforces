#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 505
#define LIM 1000005
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,m,B1,B2,a[N],nxt[N],w[N],bl[N],id[N*2],hd[N*2];
int ds[N*2],cnt[N*2],F[N][3];set<int> z[N*2];set<int>::iterator it;
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
struct Block1
{
	int vl1[N],vl2[M];
	void upd(int x,int vl)
	{
		for(int i=x;i<=min(bl[x]*B1,n);++i) vl1[i]+=vl;
		for(int i=bl[x];i<=bl[n];++i) vl2[i]+=vl;
	}
	int qSm(int x) {return vl1[x]+vl2[bl[x]-1];}
}BL1[M];
struct Block2
{
	int vl1[N],vl2[M];
	void upd(int x,int vl) {vl1[x]+=vl;vl2[bl[x]]+=vl;}
	int qSm(int x)
	{
		int res=0;for(int i=x;i>(bl[x]-1)*B1;--i) res+=vl1[i];
		for(int i=1;i<bl[x];++i) res+=vl2[i];return res;
	}
}BL2[M];
int qId(int x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;}
void dlt(int x)
{
	if(id[a[x]]) BL1[id[a[x]]].upd(x,-1);
	else for(int i=x;i;i=nxt[i])
	{BL2[w[i]].upd(i,-1);if(i>x) BL2[--w[i]].upd(i,1);}
	z[a[x]].erase(x);it=z[a[x]].upper_bound(x);
	if(it==z[a[x]].begin()) hd[a[x]]=nxt[x];else nxt[*--it]=nxt[x];
}
void ins(int x)
{
	z[a[x]].insert(x);it=z[a[x]].upper_bound(x);
	nxt[x]=it==z[a[x]].end()?0:*it;--it;
	if(it==z[a[x]].begin()) hd[a[x]]=x,w[x]=0;
	else nxt[*--it]=x,w[x]=w[*it];
	if(id[a[x]]) BL1[id[a[x]]].upd(x,1);
	else for(int i=x;i;i=nxt[i])
	{if(i>x) BL2[w[i]].upd(i,-1);BL2[++w[i]].upd(i,1);}
}
void upd(int x,int vl) {dlt(x);a[x]=vl;ins(x);}
int qry1(int x)
{
	if(id[a[x]]) return BL1[id[a[x]]].qSm(x);int res=0;
	for(int i=hd[a[x]];i && i<=x;i=nxt[i]) ++res;return res;
}
int qry2(int x)
{
	int t=qry1(x),res=t<=B2?BL2[t].qSm(x):0;
	for(int i=1;i<=id[0];++i) if(BL1[i].qSm(x)>=t) ++res;
	return res;
}
int qry(int x,int y)
{if(x==1) return ds[a[y]];return x&1?qry2(y):qry1(y);}
int main()
{
	n=rd();B1=sqrt(n);for(int i=1;i<=n;++i) bl[i]=(i-1)/B1+1;
	for(int i=1;i<=n;++i) a[i]=rd(),ds[++ds[0]]=a[i];
	m=rd();B2=sqrt(n+m);
	for(int i=1;i<=m;++i)
	{
		F[i][0]=rd();F[i][2]=rd();F[i][1]=rd();
		if(F[i][0]==1) ds[++ds[0]]=F[i][2];
	}sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i) a[i]=qId(a[i]),++cnt[a[i]];
	for(int i=1;i<=m;++i) if(F[i][0]==1)
		F[i][2]=qId(F[i][2]),++cnt[F[i][2]];
	for(int i=1;i<=ds[0];++i) if(cnt[i]>B2) id[i]=++id[0];
	for(int i=1;i<=n;++i) ins(i);
	for(int i=1;i<=m;++i) if(F[i][0]==1) upd(F[i][1],F[i][2]);
		else printf("%d\n",qry(F[i][2],F[i][1]));return 0;
}