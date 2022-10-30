//Coded by STUPID_JUSTlN {{{
//Gened on 2021.10.24 18:05:02
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
const int N=100005;int n,a[N];char dp[N],tmp[N];ll sm[N];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),sm[i]=sm[i-1]+a[i],dp[i]=1,tmp[i]=0;
	for(int k=2;;k++)
	{
		ll mx=0;
		for(int i=n-k+1;i>=k;i--)
		{
			if(dp[i+k-1]) mx=max(mx,sm[i+k-1]-sm[i]);
			if(sm[i]-sm[i-k]<mx) tmp[i]=1;else tmp[i]=0;
		}
		char fg=0;for(int i=1;i<=n;i++) if(tmp[i]) fg=1;
		if(!fg) return printf("%d\n",k-1),void();
		for(int i=1;i<=n;i++) dp[i]=tmp[i],tmp[i]=0;
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}