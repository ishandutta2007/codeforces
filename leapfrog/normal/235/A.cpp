//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n;ll mx=0;
inline ll lcm(ll a,ll b) {return a/__gcd(a,b)*b;}
int main()
{
	read(n);int m=max(1,n-100);
	for(int i=m;i<=n;i++) for(int j=m;j<=n;j++) for(int k=m;k<=n;k++) mx=max(mx,lcm(i,lcm(j,k)));
	return printf("%lld\n",mx),0;
}