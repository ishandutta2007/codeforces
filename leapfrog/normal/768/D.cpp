#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int k,q;double dp[10005][1005];
int main()
{
	read(k),read(q),dp[0][0]=1.0;int n=10000;
	for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) dp[i][j]=dp[i-1][j]*j/k+dp[i-1][j-1]*(k-j+1)/k;
	for(int i=1,w,r;i<=q;i++)
	{
		scanf("%d",&w),r=0;
		for(int i=1;i<=n;i++) if(dp[i][k]*2000>=w) {r=i;break;}
		printf("%d\n",r);
	}
	return 0;
}