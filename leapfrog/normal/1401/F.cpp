//
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int K,Q,n,rt,a[300005],rev[25],t[1200005];
inline void pushup(int x) {t[x]=t[x<<1]+t[x<<1|1];}
inline void build(int x,int l,int r)
{
	if(l==r) return(void)(t[x]=a[l]);
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline int query(int x,int l,int r,int dl,int dr,int dep)
{
	if(dl>r||l>dr) return 0;else if(dl<=l&&r<=dr) return t[x];
	return query(x<<1|rev[dep],l,(l+r)>>1,dl,dr,dep+1)+query(x<<1|!rev[dep],((l+r)>>1)+1,r,dl,dr,dep+1);
}
inline void motif(int x,int l,int r,int dw,int dc,int dep)
{
	if(l==r) return(void)(t[x]=dc);
	if(dw<=((l+r)>>1)) motif(x<<1|rev[dep],l,(l+r)>>1,dw,dc,dep+1),pushup(x);
	else motif(x<<1|!rev[dep],((l+r)>>1)+1,r,dw,dc,dep+1),pushup(x);
}
signed main()
{
	read(K),read(Q),n=1<<K;
	for(int i=1;i<=n;i++) read(a[i]);
	build(1,1,n);
	for(int fg,x,y;Q--;)
	{
		read(fg),read(x);
		if(fg==1) read(y),motif(1,1,n,x,y,1);
		if(fg==2) for(int i=K+1;i>=K-x+1;i--) rev[i]^=1;
		if(fg==3) rev[K-x]^=1;
		if(fg==4) read(y),printf("%lld\n",query(1,1,n,x,y,1));
		//for(int i=1;i<=n;i++) printf("%lld%c",query(1,1,n,i,i,1),i==n?'\n':' ');
	}
	return 0;
}