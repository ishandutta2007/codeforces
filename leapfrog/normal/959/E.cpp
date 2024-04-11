#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename... A>inline void read(T &t,A &...a) {read(t),read(a...);}
inline long long getit(long long x)
{
	long long r=0,i=0;for(;x>1;i++,x>>=1) r+=(((x+1)>>1)<<i);
	return r+(1ll<<i);
}
int main()
{
	// for(long long i=1;i<=20;i++) printf("%lld\n",getit(i));
	long long i;read(i),printf("%lld\n",i==1?0:getit(i-1));
	return 0;
}