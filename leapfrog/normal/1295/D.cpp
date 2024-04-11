//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
inline ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
inline ll phi(ll x)
{
	ll r=x;for(ll i=2;i*i<=x;i++) if(x%i==0) {r/=i,r*=(i-1);while(x%i==0) x/=i;}
	return x!=1?r/x*(x-1):r;
}
ll a,b;int T;
int main()
{
	for(read(T);T--;) read(a),read(b),printf("%lld\n",phi(b/gcd(a,b)));
	return 0;
}