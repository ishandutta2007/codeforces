//Coded by Kamiyama_Shiki on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=105;int n,X,a[N],b[N];
inline void solve()
{
	read(n,X);for(int i=1;i<=n;i++) read(a[i],b[i]);
	int mx=0;for(int i=1;i<=n;i++) mx=max(mx,a[i]);
	int mw=-1;for(int i=1;i<=n;i++) mw=max(mw,a[i]-b[i]);
	if(X<=mx) return puts("1"),void();else if(mw<=0) return puts("-1"),void();
	int tot=(X-mx+mw-1)/mw+1;printf("%d\n",tot);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}