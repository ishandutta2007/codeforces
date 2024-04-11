//
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
int n,dp[65],sg=0;
int main()
{
	read(n),memset(dp,-1,sizeof(dp));
	for(int i=1,x;i<=n;i++)
	{
		read(x);if(dp[x]!=-1) {sg^=dp[x];continue;}
		int j=1,X=x;for(;;j++) {X-=j;if(X<=j) break;}
		sg^=(dp[x]=j);
	}
	return puts(sg?"NO":"YES"),0;
}