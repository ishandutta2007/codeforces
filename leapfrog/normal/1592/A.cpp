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
const int N=2000005;
int n,m,K,a[N],b[N];char s[N],ch[N],t[N];
inline void solve()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);int rs=K/(a[n]+a[n-1])*2;K%=(a[n]+a[n-1]);
	if(K==0) printf("%d\n",rs);else if(K<=a[n]) printf("%d\n",rs+1);else printf("%d\n",rs+2);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}