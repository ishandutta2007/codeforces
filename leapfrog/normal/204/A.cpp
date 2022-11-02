//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
inline long long qwq(long long x)
{
	long long res=x/10+9,gw=x%10;if(x<10) return x;
	while(x/10) x/=10;return res-(gw<x);
}
int main() {long long l,r;read(l),read(r),printf("%lld\n",qwq(r)-qwq(l-1));}