//{{{
#include<bits/stdc++.h>
#define int long long
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int Ca,n;
inline void solve()
{
	ll vl=(1ll*n*n+1)>>1,res=0;int x,y;read(x),read(y);
	if(n&1)
	{
		if((x+y)&1)
		{
			if(x&1) res=(n/2+1)*(x/2)+(n/2)*(x/2);else res=(n/2+1)*(x/2)+(n/2)*(x/2-1);
			res+=vl+y/2;
		}
		else
		{
			if(x&1) res=(n/2+1)*(x/2)+(n/2)*(x/2);else res=(n/2+1)*(x/2)+(n/2)*(x/2-1);
			if(y&1) res+=y/2+1;else res+=y/2;
		}
	}
	else
	{
		if((x+y)&1) res=vl+(n/2)*(x-1)+y/2+!(x&1);
		else res=(n/2)*(x-1)+y/2+(x&1);
	}
	printf("%lld\n",res);
}
signed main() {for(read(n),read(Ca);Ca--;) solve();return 0;}