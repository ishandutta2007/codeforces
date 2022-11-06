#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
using std::swap;
const int N=1e6+5;
int n,m;
int a[N][4];
int dp[N][4];
char s[N];
signed main()
{
	int x=0,y=0,z=0,w=0;
	register int i,j,k;
	scanf("%d%d",&n,&m);
	if(n==1||m==1)
		return puts("0"),0;
	if(n>=4&&m>=4)
		return puts("-1"),0;
	if(n>=m)
	{

		for(i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(j=1;j<=m;j++)
				a[i][j]=s[j];
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(j=1;j<=m;j++)
				a[j][i]=s[j];
		}
		swap(n,m);
	}
	memset(dp,0x3f,sizeof(dp));
	if(m==2)
	{
		for(i=1;i<=2;i++)
			for(j=1;j<=2;j++)
				x^=a[i][j];
		if(x)
			dp[2][a[2][1]^a[2][2]]=0,dp[2][a[2][1]^a[2][2]^1]=2;
		else
			dp[2][0]=dp[2][1]=1;
		for(i=3;i<=n;i++)
		{
			dp[i][a[i][1]^a[i][2]]=dp[i-1][a[i][1]^a[i][2]^1];
			dp[i][a[i][1]^a[i][2]^1]=dp[i-1][a[i][1]^a[i][2]]+1;
		}
		printf("%d\n",min(dp[n][0],dp[n][1]));
		return 0;
	}
	z=a[1][1]^a[1][2];
	w=a[1][2]^a[1][3];
	dp[1][z<<1|w]=0;
	dp[1][z<<1|(!w)]=1;
	dp[1][(!z)<<1|w]=1;
	dp[1][(!z)<<1|(!w)]=1;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<8;j++)
		{
			x=0;
			z=a[i][1]^a[i][2];
			w=a[i][2]^a[i][3];
			if(j&1)
				z^=1,x++;
			if((j>>1)&1)
				z^=1,w^=1,x++;
			if((j>>2)&1)
				w^=1,x++;
			dp[i][z<<1|w]=min(dp[i][z<<1|w],dp[i-1][(!z)<<1|(!w)]+x);
		}
	}
	int ans=0x3f3f3f3f;
	for(i=0;i<8;i++)
		ans=min(ans,dp[n][i]);
	if(ans==0x3f3f3f3f)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}