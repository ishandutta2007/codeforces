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
int n,a[55],dp[26][2500055];char us[55];
int main()
{
	read(n);for(int i=1;i<=n*2;i++) read(a[i]),a[i]++;
	sort(a+1,a+n*2+1),memset(dp,-1,sizeof(dp)),dp[0][0]=1;
	int sm=0;for(int i=3;i<=n*2;i++) sm+=a[i];
	for(int i=3;i<=n*2;i++) for(int j=sm;j>=a[i];j--) for(int k=min(i-2,n-1);k;k--) if(~dp[k-1][j-a[i]]&&!~dp[k][j]) dp[k][j]=i;
	int mx=1e9;for(int i=0;i<=sm;i++) if(~dp[n-1][i]) mx=min(max(i,sm-i),mx);
	for(int k=n-1;k;k--) {int wh=dp[k][mx];us[wh]=1,mx-=a[wh];}
	printf("%d ",a[1]-1);for(int i=3;i<=n*2;i++) if(us[i]) printf("%d ",a[i]-1);
	putchar('\n');for(int i=n*2;i>=3;i--) if(!us[i]) printf("%d ",a[i]-1);
	return printf("%d\n",a[2]-1),0;
}