//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
long long n,k;
int main()
{
	read(n),read(k);long long od=(n>>1)+(n&1);
	if(k>od) printf("%lld\n",(k-od)<<1);else printf("%lld\n",(k<<1)-1);
	return 0;
}