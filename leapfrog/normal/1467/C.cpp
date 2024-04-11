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
int T,n1,n2,n3,m1,m2,m3;ll s1,s2,s3;
inline void solve()
{
	read(n1),read(n2),read(n3),m1=m2=m3=1e9;
	for(int i=1,x;i<=n1;i++) read(x),s1+=x,m1=min(m1,x);
	for(int i=1,x;i<=n2;i++) read(x),s2+=x,m2=min(m2,x);
	for(int i=1,x;i<=n3;i++) read(x),s3+=x,m3=min(m3,x);
	printf("%lld\n",s1+s2+s3-(min(min(m1+m2,min(m2+m3,m1+m3))*1ll,min(s1,min(s2,s3)))<<1));
}
int main() {for(T=1;T--;) solve();return 0;}