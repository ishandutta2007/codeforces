//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;int p[305],ls[305],id[305],pc;char v[305];
int n,Q,a[400005];struct node{int sm,ln,fp;ll fv,vl;}T[1600005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline ll zyx(int x) {ll rs=0;for(;x^1;x/=ls[x]) rs|=1ll<<id[ls[x]];return rs;}
inline int jyx(ll x) {int rs=1;for(int i=0;i<pc;i++) if((x>>i)&1) rs=1ll*rs*(p[i+1]-1)%P*ksm(p[i+1])%P;return rs;}
inline node operator+(node a,node b) {return(node){(int)(1ll*a.sm*b.sm%P),a.ln+b.ln,1,0,a.vl|b.vl};}
inline void allp(int x,int c,ll z) {T[x].sm=1ll*T[x].sm*ksm(c,T[x].ln)%P,T[x].fp=1ll*T[x].fp*c%P,T[x].vl|=z,T[x].fv|=z;}
inline void pushdw(int x) {if(T[x].fv) allp(x<<1,T[x].fp,T[x].fv),allp(x<<1|1,T[x].fp,T[x].fv),T[x].fp=1,T[x].fv=0;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x]=(node){a[l],1,1,0,zyx(a[l])},void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]+T[x<<1|1];
}
inline void modif(int x,int l,int r,int dl,int dr,int dc,ll dz)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allp(x,dc,dz);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc,dz),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc,dz),T[x]=T[x<<1]+T[x<<1|1];
}
inline node query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return(node){1,0,0,0,0};else if(dl<=l&&r<=dr) return T[x];
	return pushdw(x),query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
signed main()
{
	read(n),read(Q),v[1]=1;for(int i=2;i<=300;i++)
	{
		if(!v[i]) p[++pc]=i,id[i]=pc-1,ls[i]=i;
		for(int j=1;j<=pc&&i*p[j]<=300;j++) {v[i*p[j]]=1,ls[i*p[j]]=p[j];if(i%p[j]==0) break;}
	}
	for(int i=1;i<=n;i++) read(a[i]);
	for(build(1,1,n);Q--;)
	{
		int l,r,x;char ch[10];scanf("%s",ch),read(l),read(r);
		if(*ch=='M') read(x),modif(1,1,n,l,r,x,zyx(x));
		else {node v=query(1,1,n,l,r);printf("%lld\n",1ll*v.sm*jyx(v.vl)%P);}
	}
	return 0;
}