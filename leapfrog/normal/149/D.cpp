#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1000000007;int n,p[705],dp[705][705][3][3];char c[705];stack<int>s;
inline void dfs(int l,int r)
{
	if(l+1>=r) return(void)(dp[l][r][0][1]=dp[l][r][0][2]=dp[l][r][1][0]=dp[l][r][2][0]=1);
	if(p[r]==l)
	{
		dfs(l+1,r-1);
		for(int i=0;i<=2;i++) for(int j=0;j<=2;j++) for(int k=0;k<=2;k++) for(int g=0;g<=2;g++)
			if((!k^!g)&&(!k||!i||k!=i)&&(!j||!g||j!=g))
				(dp[l][r][k][g]+=dp[l+1][r-1][i][j])%=P;//printf("%d , %d , %d , %d\n",k,i,j,g);
	}
	else
	{
		dfs(l,p[r]-1),dfs(p[r],r);
		for(int i=0;i<=2;i++) for(int j=0;j<=2;j++) for(int k=0;k<=2;k++) for(int g=0;g<=2;g++)
			if(!j||j!=k)
				(dp[l][r][i][g]+=1ll*dp[l][p[r]-1][i][j]*dp[p[r]][r][k][g]%P)%=P;//printf("%d %d %d %d\n",i,j,k,g);
	}
}
signed main()
{
	scanf("%s",c+1),n=strlen(c+1),memset(dp,0,sizeof(dp));int r=0;
	for(int i=1;i<=n;i++) if(c[i]=='(') s.push(i);else p[i]=s.top(),s.pop();
	dfs(1,n);for(int i=0;i<=2;i++) for(int j=0;j<=2;j++) (r+=dp[1][n][i][j])%=P;
	return printf("%lld\n",r),0;
}