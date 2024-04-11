#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000+5,Mod=998244353;
char a[MaxN],b[MaxN];
int la[MaxN],lb[MaxN];
int dp[MaxN][MaxN][2];
signed main()
{
	register int n,m;
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	register int Sum=0;
	rep(x,1,n)
		la[x]=((a[x]==a[x-1])?1:(la[x-1]+1));
	rep(y,1,m)
		lb[y]=((b[y]==b[y-1])?1:(lb[y-1]+1));
	rep(x,1,n)
		rep(y,1,m)
		{
			if(a[x]!=b[y])
				dp[x][y][0]=lb[y];
			if(a[x]!=b[y])
				dp[x][y][1]=la[x];
			if(a[x]!=a[x-1])
				dp[x][y][0]+=dp[x-1][y][0];
			if(a[x]!=b[y])
				dp[x][y][0]+=dp[x-1][y][1];
			if(a[x]!=b[y])
				dp[x][y][1]+=dp[x][y-1][0];
			if(b[y]!=b[y-1])
				dp[x][y][1]+=dp[x][y-1][1];
			if(dp[x][y][0]>=Mod)
				dp[x][y][0]-=Mod;
			if(dp[x][y][1]>=Mod)
				dp[x][y][1]-=Mod;
			Sum=(Sum+dp[x][y][0]+dp[x][y][1]);
			if(Sum>=Mod)
				Sum-=Mod;
			if(Sum>=Mod)
				Sum-=Mod;
		}
	printf("%lld\n",Sum);
	return 0;
}