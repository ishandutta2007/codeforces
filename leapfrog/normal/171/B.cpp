//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n;
int main()
{
	read(n);if(n==1) return puts("1"),0;
	ll rs=1;for(int i=2;i<=n;i++) rs+=2ll*(i-1)*6;
	return printf("%lld\n",rs),0;
}