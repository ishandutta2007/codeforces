#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define LIM 1000005
#define mid ((l+r)/2)
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int INF=1e9;char *P1,*P2,buf[LIM];
int T,n,ans,a[N],st[N],pr[N];struct Seg {int vl,tg;}sg[N*4];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void mdf(int p,int vl) {sg[p].vl+=vl;sg[p].tg+=vl;}
void pu(int p) {sg[p].vl=min(sg[p*2].vl,sg[p*2+1].vl);}
void pd(int p)
{if(sg[p].tg) mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;}
void build(int p,int l,int r)
{
	sg[p].tg=0;if(l==r) {sg[p].vl=l-1;return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
void slv()
{
	n=rd();st[0]=0;for(int i=1;i<=n;++i) pr[i]=0;
	for(int i=1;i<=n;++i) {a[i]=rd();if(!a[i]) st[++st[0]]=i;}
	if(!st[0]) {puts("0");return;}ans=st[0]/2;build(1,1,st[0]);
	for(int i=2;i<=st[0];++i)
	{
		if(i>1) for(int j=st[i-1]+1;j<st[i];++j)
			upd(1,1,st[0],pr[a[j]]+1,i-1,1),pr[a[j]]=i-1;
		ans=min(ans,sg[1].vl+st[0]-i);
	}printf("%d\n",ans);
}
int main() {T=rd();while(T--) slv();return 0;}