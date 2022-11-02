//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const ll I=1e18;int n,m,h[200005];ll d[200005];struct node{ll sm2,sm1,mx;}t[800005];
inline node operator+(node a,node b)
{
	node r;r.mx=max(max(a.mx,b.mx),a.sm1+b.sm2);
	return r.sm2=max(a.sm2,b.sm2),r.sm1=max(a.sm1,b.sm1),r;
}
inline void build(int x,int l,int r)
{
	if(l==r) return t[x].sm2=h[l]+d[l],t[x].sm1=h[l]-d[l],t[x].mx=-I,void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x]=t[x<<1]+t[x<<1|1];
}
inline node query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return(node){-I,-I,-I};else if(dl<=l&&r<=dr) return t[x];
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(d[i+1]),d[i+n+1]=d[i+1];
	for(int i=1;i<=n;i++) read(h[i]),h[i]=h[i+n]=h[i]<<1;
	for(int i=1;i<=n+n;i++) d[i]=d[i-1]+d[i];
	for(build(1,1,n+n);m--;)
	{
		int x,y;read(x),read(y),swap(x,y);
		if(x<y) x++,y--;else x++,y+=n-1;
		printf("%lld\n",query(1,1,n+n,x,y).mx);
	}
	return 0;
}