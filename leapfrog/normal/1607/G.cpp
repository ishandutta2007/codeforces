//Coded by Kamiyama_Shiki on 2021.11.03 {{{
//
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
const int N=200005;int n,m,a[N],b[N],l[N],r[N],rs[N];ll tt;
inline void solve()
{
	read(n,m),tt=0;for(int i=1;i<=n;i++) read(a[i],b[i]);
	for(int i=1;i<=n;i++) tt+=a[i]-b[i]+m,l[i]=max(0,m-b[i]),r[i]=min(a[i],m);
	for(int i=1;i<=n;i++) rs[i]=l[i],tt-=2*l[i];
	for(int i=1,v;i<=n;i++) if(tt>0) v=min(1ll*r[i]-l[i],tt>>1),tt-=v*2,rs[i]+=v;
	printf("%lld\n",abs(tt));for(int i=1;i<=n;i++) printf("%d %d\n",rs[i],m-rs[i]);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}