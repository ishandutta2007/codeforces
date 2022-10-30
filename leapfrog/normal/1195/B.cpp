//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,K;
int main()
{
	read(n),read(K);
	for(int i=1;i<=n;i++)
	{
		ll cnt=1ll*i*(i+1)/2-K;if(cnt>1000000000) break;
		if(cnt+i==n) return printf("%lld\n",cnt),0;
	}
	return 0;
}