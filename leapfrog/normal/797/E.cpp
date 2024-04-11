//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,a[100005],dp[100005][405];
int main()
{
	read(n);int p,k;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=n;i>=1;i--) for(int j=1;j<=400;j++) if(i+j+a[i]>n) dp[i][j]=1;else dp[i][j]=dp[i+j+a[i]][j]+1;
	for(read(m);m--;)
	{
		read(p),read(k);
		if(k<=400) {printf("%d\n",dp[p][k]);continue;}
		int cnt=0;while(p<=n) p=p+a[p]+k,++cnt;
		printf("%d\n",cnt);
	}
	return 0;
}