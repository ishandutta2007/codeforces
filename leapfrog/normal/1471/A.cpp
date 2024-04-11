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
int T,n,a[100005],x;ll r,s;
int main()
{
	for(read(T);T--;)
	{
		read(n),read(x),r=0,s=0;
		for(int i=1,v;i<=n;i++) read(v),r+=v,s+=v/x+!!(v%x);
		printf("%lld %lld\n",r/x+!!(r%x),s);
	}
	return 0;
}