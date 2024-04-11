#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,w;
int main()
{
	read(n),read(w);long long s=0,mx=0,mn=0;
	for(int i=1,v;i<=n;i++) read(v),s+=v,mx=max(mx,s),mn=min(mn,s);
	printf("%lld\n",max(w-mx+mn+1,0ll));
	return 0;
}