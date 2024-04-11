#include<cstdio>
#include<cstring>
using namespace std;
char S[1<<20];
int dp[1<<20];
bool ex[1<<20];
main()
{
	scanf("%s",S);
	int N=strlen(S);
	for(int i=0;i<N;i++)
	{
		int r=0;
		for(int j=i;j<N;j++)
		{
			int c=S[j]-'a';
			if(r>>c&1)break;
			r|=1<<c;
			ex[r]=true;
		}
	}
	for(int i=0;i<1<<20;i++)if(ex[i])dp[i]=__builtin_popcount(i);
	for(int i=0;i<1<<20;i++)for(int j=0;j<20;j++)if(!(i>>j&1))
	{
		if(dp[i|1<<j]<dp[i])dp[i|1<<j]=dp[i];
	}
	int ans=0;
	for(int i=0;i<1<<20;i++)if(ex[i])
	{
		int now=__builtin_popcount(i)+dp[(1<<20)-1^i];
		if(ans<now)ans=now;
	}
	printf("%d\n",ans);
}