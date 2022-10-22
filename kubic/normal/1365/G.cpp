#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define ull unsigned long long 
int n,dp[1<<13],id[N];ull ans[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<(1<<13);++i)
	{dp[i]=dp[i&i-1]+1;if(dp[i]==6) id[++id[0]]=i;if(id[0]>=n) break;}
	for(int i=0,cnt=0;i<13;++i,cnt=0)
	{
		ull x;for(int j=1;j<=n;++j) if(id[j]>>i&1) ++cnt;
		if(cnt)
		{
			printf("? %d ",cnt);
			for(int j=1;j<=n;++j) if(id[j]>>i&1) printf("%d ",j);
			fflush(stdout);scanf("%llu",&x);
			for(int j=1;j<=n;++j) if(!(id[j]>>i&1)) ans[j]|=x;
		}
	}printf("! ");for(int i=1;i<=n;++i) printf("%llu ",ans[i]);return 0;
}