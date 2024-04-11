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
int n,v[100005],dp[100005];
int main()
{
	read(n);int sm=n*(n+1)/2;
	if(sm&1) puts("1");else puts("0");
	printf("%d ",n>>1);for(int i=n,c=1;i>1;i-=2) printf("%d ",i-(c^=1));
	return putchar('\n'),0;
}