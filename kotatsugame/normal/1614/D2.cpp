#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int LIM=20000000;
bool isp[LIM+1];
vector<int>ps;
int N;
int sum[LIM+1];
long long dp[LIM+1];
main()
{
	for(int i=2;i<=LIM;i++)if(!isp[i])
	{
		ps.push_back(i);
		if(i<=LIM/i)for(int j=i*i;j<=LIM;j+=i)isp[j]=true;
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		for(int d=1;d*d<=A;d++)if(A%d==0)
		{
			sum[d]++;
			if(d<A/d)sum[A/d]++;
		}
	}
	for(int i=LIM;i>=1;i--)
	{
		long long now=(long long)i*sum[i];
		for(int j=0;j<ps.size()&&i*ps[j]<=LIM;j++)
		{
			int nj=i*ps[j];
			now=max(now,dp[nj]+(long long)i*(sum[i]-sum[nj]));
		}
		dp[i]=now;
	}
	printf("%lld\n",dp[1]);
}