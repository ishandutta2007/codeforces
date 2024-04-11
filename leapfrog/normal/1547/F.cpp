//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,a[400005],g,T[1600005];
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x]=a[l],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=gcd(T[x<<1],T[x<<1|1]);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x];
	return gcd(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
inline void solve()
{
	read(n),g=0;for(int i=1;i<=n;i++) read(a[i]),g=gcd(a[i],g);
	int mx=0,lim=0;for(int i=1;i<=n;i++) a[i]/=g,a[i+n]=a[i],lim=max(lim,a[i]);
	char ff=0;for(int i=1;i<=n;i++) if(a[i]!=a[1]) ff=1;
	if(!ff) return puts("0"),void();else build(1,1,n+n);
	int l=1;for(int r=1;r<=n+n;r++)
	{
		while(query(1,1,n+n,l,r)==1&&l<=r) l++;
		mx=max(mx,r-l+1);
	}
	printf("%d\n",mx);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}