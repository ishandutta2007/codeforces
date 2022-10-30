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
int n,a[1000005],b[1000005],rs;
int main()
{
	read(n);for(int i=1,x;i<=n;i++) read(x),b[i]=b[i-1]^i,rs^=x;
	for(int i=2,x;i<=n;i++) x=n/i,rs^=(x&1)*b[i-1],rs^=b[n-x*i];
	return printf("%d\n",rs),0;
}