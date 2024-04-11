//
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[100005],dp[100005][2];
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);long long sm=0;int rs=0;
	for(int i=1;i<=n;i++) if(sm<=a[i]) rs++,sm+=a[i];
	return printf("%d\n",rs),0;
}