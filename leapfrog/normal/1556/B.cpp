#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,a[100005],b[1000005];
#define int long long
inline int chk(int x)
{
	int bt=0,rs=0;for(int i=1;i<=n;i++) if(a[i]==x) b[++bt]=i;
	for(int i=1;i<=(n+1)/2;i++) rs+=abs(i*2-1-b[i]);
	return rs;
}
inline void solve()
{
	read(n);int tt=0;
	for(int i=1;i<=n;i++) read(a[i]),tt+=(a[i]&=1);
	if(n&1) {if(tt==n/2) printf("%lld\n",chk(0));else if(tt==n/2+1) printf("%lld\n",chk(1));else puts("-1");}
	else {if(tt==n/2) printf("%lld\n",min(chk(0),chk(1)));else puts("-1");}
}
signed main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}