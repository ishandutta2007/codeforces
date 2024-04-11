#include<cstdio>
#include<cstring>
const int N=1e5+5;
int n,ans;
char s[N];
int dp[N];
signed main()
{
	int res=0,cur;
	register int i;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		if(i>1&&s[i-1]!=s[i])
			dp[i]=dp[i-1]+1;
		else
			dp[i]=1;
	for(i=1;i<=n;i++)
		if(dp[i]>ans)
			ans=dp[i];
	if(ans==n)
	{
		printf("%d\n",ans);
		return 0;
	}
	if(s[1]!=s[n])
	{
		cur=1;
		while(cur<n&&s[cur+1]!=s[cur])
			cur++;
		res+=cur;
		cur=n;
		while(cur>1&&s[cur-1]!=s[cur])
			cur--;
		res+=n-cur+1;
		if(res>ans)
			ans=res;
	}
	printf("%d\n",ans);
	return 0;
}