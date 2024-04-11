#include<cstdio>
using namespace std;
int T,N;
int P[4040];
bool ex[4040];
bool dp[4040];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<2*N;i++)scanf("%d",&P[i]);
		for(int i=1;i<=2*N;i++)
		{
			ex[i]=true;
			dp[i]=false;
		}
		dp[0]=true;
		int mx=2*N;
		for(int i=2*N-1;i>=0;)
		{
			while(!ex[mx])mx--;
			int j=i;
			while(mx!=P[j])
			{
				ex[P[j]]=false;
				j--;
			}
			ex[mx]=false;
			int K=i-j+1;
			i=j-1;
			for(int k=N-1;k>=0;k--)
			{
				if(dp[k])dp[k+K]=true;
			}
		}
		puts(dp[N]?"YES":"NO");
	}
}