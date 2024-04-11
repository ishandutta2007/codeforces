//Coded by Katou_Umi on 2021.10.31 {{{
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
const int N=200005;
int n,A,B;char a[N];
inline void solve()
{
	read(n,A,B),scanf("%s",a+1);for(int i=1;i<=n;i++) a[i]^=48;
	char fg=0;for(int i=1;i<=n;i++) fg|=a[i];
	if(!fg) return printf("%lld\n",1ll*n*A+1ll*(n+1)*B),void();
	ll rs=1ll*(n+2)*A+1ll*(n+1)*B;
	int fs=1;while(!a[fs+1]) fs++;
	int ls=n;while(!a[ls-1]) ls--;
	rs+=1ll*(ls-fs)*B;
	for(int l=fs+1,r=l;l<ls;l=++r) if(!a[l])
	{
		while(r<n&&!a[r+1]) r++;
		ll dw=1ll*(r-l)*B-2*A;rs-=max(dw,0ll);
	}printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}