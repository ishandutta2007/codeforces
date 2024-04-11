//{{{
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
const int N=200005;int n,k,p,a[N];ll qz[N],hz[N];
int main()
{
	read(n,k,p);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]|a[i];
	for(int i=n;i>=1;i--) hz[i]=hz[i+1]|a[i];
	ll pw=1;for(int i=1;i<=k;i++) pw*=p;
	ll rs=0;for(int i=1;i<=n;i++) rs=max(rs,qz[i-1]|hz[i+1]|(1ll*a[i]*pw));
	return printf("%lld\n",rs),0;
}