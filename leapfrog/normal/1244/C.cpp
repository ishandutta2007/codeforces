//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
ll n,p;int a,b;
int main()
{
	read(n),read(p),read(a),read(b);
	for(int y=0;y<=a;y++)
	{
		if((p-1ll*b*y)%a) continue;
		ll x=(p-1ll*b*y)/a;if(x+y>n||x<0) return puts("-1"),0;
		return printf("%lld %d %lld\n",x,y,n-x-y),0;
	}
	return puts("-1"),0;
}