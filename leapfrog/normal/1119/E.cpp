//
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
int n;long long rs=0,lst=0;
int main()
{
	read(n);for(int Q=n;Q--;)
	{
		long long w;read(w);
		if((w>>1)<lst) rs+=(w>>1),lst-=(w>>1),w&=1;
		else w-=(lst<<1),rs+=lst,lst=0;
		rs+=w/3,lst+=w%3;
	}
	return printf("%lld\n",rs),0;
}