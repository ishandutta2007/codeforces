//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;int n,a[N],mx;vector<int>v[N];
struct seg{ll sm;int mx,ln,fg;}T[N<<2];ll cf[N];
inline void pushup(int x) {T[x].mx=max(T[x<<1].mx,T[x<<1|1].mx),T[x].sm=T[x<<1].sm+T[x<<1|1].sm;}
inline void allc(int x,int c) {T[x].sm=1ll*c*T[x].ln,T[x].fg=T[x].mx=c;}
inline void pushdw(int x) {if(T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=0;}
inline void build(int x,int l,int r)
{
	T[x].ln=r-l+1;if(l==r) return T[x].sm=T[x].mx=l,void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void modiff(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modiff(x<<1,l,(l+r)>>1,dl,dr,dc),modiff(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(l==r) return T[x].sm=T[x].mx=max(T[x].mx,dc),void();
	pushdw(x);if(T[x<<1].mx>dc) return modif(x<<1,l,(l+r)>>1,dl,dr,dc),pushup(x);
	modiff(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline void debug(int x,int l,int r)
{
	//printf("[ %d %d ] : %lld ( %d %d\n",l,r,T[x].sm,T[x].ln,T[x].mx);
	if(l==r) return printf("%d%c",T[x].mx,l==n?'\n':' '),void();
	pushdw(x),debug(x<<1,l,(l+r)>>1),debug(x<<1|1,((l+r)>>1)+1,r);
}
inline void work(int x)
{
	if((int)v[x].size()<=1) return;
	int fs=v[x][0],sc=v[x][1],sz=v[x].size(),ls=v[x][sz-1],lss=v[x][sz-2];
	modif(1,1,n,sc+1,n,n+1),modif(1,1,n,fs+1,sc,ls),modif(1,1,n,1,fs,lss);
	//debug(1,1,n);
}
int main()
{
	read(n),build(1,1,n);for(int i=1;i<=n;i++) read(a[i]),mx=max(mx,a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j*j<=a[i];j++)
		if(a[i]%j==0) {v[j].push_back(i);if(j*j!=a[i]) v[a[i]/j].push_back(i);}
	cf[mx+1]=T[1].sm;for(int i=mx;i>=1;i--) work(i),cf[i]=T[1].sm;
	for(int i=1;i<=mx;i++) cf[i]-=cf[i+1];
	ll rs=0;for(int i=1;i<=mx;i++) rs+=1ll*cf[i]*i;
	return printf("%lld\n",rs),0;
}