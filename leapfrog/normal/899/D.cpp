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
#define int long long
int n,mx9;
signed main()
{
	read(n);if(n<=4) return printf("%lld\n",n*(n-1)/2),0;
	int pw=5,nw=0,rs=0;while(n>=pw) nw++,pw*=10;
	for(int i=0;i<9;i++) {int cn=(i+1)*pw/5-1,l=max(1ll,cn-n),r=min(n,cn-1);rs+=max(r-l+1,0ll)/2;}
	return printf("%lld\n",rs),0;
}