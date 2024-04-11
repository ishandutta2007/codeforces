#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100+5;
int dp[2][MaxN][MaxN],com[MaxN<<1][MaxN<<1];
bitset<MaxN> arr[MaxN];
int Read(void)
{
	int x;
	cin>>x;
	return x;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	const int p=Read();
	com[0][0]=1;
	rep(i,1,200)
	{
		com[i][0]=1,com[i][i]=1;
		rep(j,1,i-1)
		{
			com[i][j]=(com[i-1][j-1]+com[i-1][j]);
			if(com[i][j]>=p) com[i][j]-=p;
		}
	}
	dp[1][0][0]=1,arr[1][0]=true;
	dp[1][1][1]=1,arr[1][1]=true;
	rep(i,2,n)
		dp[1][i][1]=((long long)i*dp[1][i-1][1])%p,arr[1][i]=true;
	rep(t,2,m)
	{
		const bool Now=(t&1),Last=(!Now);
		rep(a,1,n)
			rep(x,0,k)
			{
				dp[Now][a][x]=0;
				if(x&&(t+(x-1)>a))
					continue;
				unsigned long long Answer=0;
				rep(b,1,a)
				{
					unsigned long long Record=0;
					Record+=(unsigned long long)dp[Last][b-1][0]*dp[Last][a-b][x];
					if(x)
						Record+=(unsigned long long)dp[Last][b-1][x]*dp[Last][a-b][0];
					Answer+=(Record=((Record%p)*com[a-1][b-1]))%p;
					if(!(arr[t-1][b-1]&&arr[t-1][a-b]))
						continue;
					Record=0;
					int* DP1=dp[Last][b-1],*DP2=dp[Last][a-b]+x;
					rep(y,1,x-1)
					{
						Record+=(unsigned long long)(*(++DP1))*(*(--DP2));
						if((y&15)==15) Record%=p;
					}
					Answer+=(Record=((Record%p)*com[a-1][b-1]))%p;
				}
				if(((dp[Now][a][x]=(Answer%p))>=1)&&x)
					arr[t][a]=true;
			}
		dp[Now][0][0]=1,arr[t][0]=true;
	}
	cout<<dp[m&1][n][k]<<endl;
	return 0;
}