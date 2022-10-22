#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
int n,m,c,a[N],st[15];bool vs[5];
struct Seg {int n,tg,vl[5],cnt[5];}sg[N*4];
Seg merge(Seg tL,Seg tR)
{
	for(int i=0;i<tL.n;++i)
	{
		vs[i]=0;
		for(int j=0;j<tR.n;++j) if(tL.vl[i]==tR.vl[j])
		{vs[i]=1;tR.cnt[j]+=tL.cnt[i];break;}
	}
	for(int i=0,mn;i<tL.n;++i) if(!vs[i])
	{
		if(tR.n<c) tR.vl[tR.n]=tL.vl[i],tR.cnt[tR.n++]=tL.cnt[i];
		else
		{
			st[0]=0;mn=tL.cnt[i];for(int j=0;j<c;++j) mn=min(mn,tR.cnt[j]);
			for(int j=0;j<c;++j) {tR.cnt[j]-=mn;if(tR.cnt[j]) st[++st[0]]=j;}
			tL.cnt[i]-=mn;if(tL.cnt[i]) st[++st[0]]=c;tR.n=st[0];
			for(int j=1;j<=st[0];++j)
				if(st[j]==c) tR.vl[j-1]=tL.vl[i],tR.cnt[j-1]=tL.cnt[i];
				else tR.vl[j-1]=tR.vl[st[j]],tR.cnt[j-1]=tR.cnt[st[j]];
		}
	}return tR;
}
void mdf(int p,int l,int r,int vl) {sg[p]=(Seg) {1,vl,{vl},{r-l+1}};}
void pu(int p) {int tg=sg[p].tg;sg[p]=merge(sg[p*2],sg[p*2+1]);sg[p].tg=tg;}
void pd(int p,int l,int r)
{if(sg[p].tg) mdf(p*2,l,mid,sg[p].tg),mdf(p*2+1,mid+1,r,sg[p].tg),sg[p].tg=0;}
void build(int p,int l,int r)
{
	if(l==r) {sg[p]=(Seg) {1,0,{a[l]},{1}};return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(l>=qL && r<=qR) {mdf(p,l,r,vl);return;}pd(p,l,r);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p); 
}
Seg qSg(int p,int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR) return sg[p];pd(p,l,r);Seg tL,tR;
	if(qL<=mid) tL=qSg(p*2,l,mid,qL,qR);if(qR>mid) tR=qSg(p*2+1,mid+1,r,qL,qR);
	if(qL<=mid && qR>mid) return merge(tL,tR);if(qL<=mid) return tL;return tR;
}
int main()
{
	scanf("%d %d %d",&n,&m,&c);c=100/c;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);build(1,1,n);
	for(int i=1,F[4];i<=m;++i)
	{
		scanf("%d %d %d",&F[0],&F[1],&F[2]);
		if(F[0]==1) scanf("%d",&F[3]),upd(1,1,n,F[1],F[2],F[3]);
		if(F[0]==2)
		{
			Seg res=qSg(1,1,n,F[1],F[2]);printf("%d ",res.n);
			for(int j=0;j<res.n;++j) printf("%d ",res.vl[j]);puts("");
		}
	}return 0;
}