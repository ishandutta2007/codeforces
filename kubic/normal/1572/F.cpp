#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define mid ((l+r)/2)
const int B=450,INF=1e9;
int n,m;struct Seg {int tg,cnt,mx[2];}sg[N*4];
int bl[N];ll s11[N],s12[N],s21[N],s22[N];
void pu(int p)
{
	sg[p].mx[0]=max(sg[p*2].mx[0],sg[p*2+1].mx[0]);
	sg[p].mx[1]=max(sg[p*2].mx[1],sg[p*2+1].mx[1]);sg[p].cnt=0;
	if(sg[p].mx[0]==sg[p*2].mx[0]) sg[p].cnt=sg[p*2].cnt;
	else sg[p].mx[1]=max(sg[p].mx[1],sg[p*2].mx[0]);
	if(sg[p].mx[0]==sg[p*2+1].mx[0]) sg[p].cnt+=sg[p*2+1].cnt;
	else sg[p].mx[1]=max(sg[p].mx[1],sg[p*2+1].mx[0]);
}
void upd2(int x,int vl)
{
	if(x>n) return;s11[x]+=vl;s12[bl[x]]+=vl;
	s21[x]+=1ll*vl*x;s22[bl[x]]+=1ll*vl*x;
}
ll qSm(int x)
{
	if(!x) return 0;ll s1=0,s2=0;
	for(int i=1;i<bl[x];++i) s1+=s12[i],s2+=s22[i];
	for(int i=x;i>(bl[x]-1)*B;--i) s1+=s11[i],s2+=s21[i];return s1*(x+1)-s2;
}
void mdf(int p,int vl,bool fl=0)
{
	if(fl) upd2(vl+1,-sg[p].cnt),upd2(sg[p].mx[0]+1,sg[p].cnt);
	sg[p].mx[0]=vl;sg[p].tg=min(sg[p].tg,vl);
}
void pd(int p)
{
	if(sg[p].tg<INF)
	{
		if(sg[p*2].mx[0]>sg[p].tg) mdf(p*2,sg[p].tg);
		if(sg[p*2+1].mx[0]>sg[p].tg) mdf(p*2+1,sg[p].tg);sg[p].tg=INF;
	}
}
void build(int p,int l,int r)
{
	sg[p].tg=INF;if(l==r) {sg[p]=(Seg) {INF,1,{l,0}};return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(qL>qR || sg[p].mx[0]<=vl) return;
	if(l>=qL && r<=qR && sg[p].mx[1]<vl) {mdf(p,vl,1);return;}
	pd(p);if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
void upd1(int p,int l,int r,int x,int vl)
{
	if(l==r) {upd2(sg[p].mx[0]+1,1);upd2(vl+1,-1);sg[p].mx[0]=vl;return;}
	pd(p);if(x<=mid) upd1(p*2,l,mid,x,vl);else upd1(p*2+1,mid+1,r,x,vl);pu(p);
}
int qry(int p,int l,int r,int x)
{
	if(l==r) return sg[p].mx[0];pd(p);
	if(x<=mid) return qry(p*2,l,mid,x);return qry(p*2+1,mid+1,r,x);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) bl[i]=(i-1)/B+1;upd2(1,1);build(1,1,n);
	for(int i=1,F[3];i<=m;++i)
	{
		scanf("%d %d %d",&F[0],&F[1],&F[2]);
		if(F[0]==1) upd1(1,1,n,F[1],F[2]),upd(1,1,n,1,F[1]-1,F[1]-1);
		if(F[0]==2) printf("%lld\n",qSm(F[2])-qSm(F[1]-1));
	}return 0;
}