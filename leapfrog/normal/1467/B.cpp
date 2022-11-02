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
int T,n,a[300005],res,mx;char p[300005];
inline char ck(int x) {return x>1&&x<n&&((a[x]>a[x-1]&&a[x]>a[x+1])||(a[x]<a[x-1]&&a[x]<a[x+1]));}
inline int upd(int i) {return p[i-1]+p[i]+p[i+1]-ck(i-1)-ck(i)-ck(i+1);}
inline void solve()
{
	read(n),mx=0;for(int i=1;i<=n;i++) read(a[i]);
	res=0,p[n]=0;for(int i=2;i<n;i++) res+=(p[i]=ck(i));
	for(int i=2,w;i<n;i++) w=a[i],a[i]=a[i-1],mx=max(mx,upd(i)),a[i]=a[i+1],mx=max(mx,upd(i)),a[i]=w;
	printf("%d\n",max(0,res-mx));
}
int main() {for(read(T);T--;) solve();return 0;}