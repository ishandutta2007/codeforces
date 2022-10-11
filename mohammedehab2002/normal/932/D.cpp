#include <iostream>
using namespace std;
int dp[20][400005],w[400005],cur=1;
long long cum[400005];
int main()
{
	int q;
	scanf("%d",&q);
	int last=0;
	while (q--)
	{
		int t;
		long long u,x;
		scanf("%d%I64d%I64d",&t,&u,&x);
		u^=last;
		x^=last;
		if (t==1)
		{
			cur++;
			w[cur]=x;
			for (int i=19;i>=0;i--)
			{
				if (dp[i][u] && w[dp[i][u]]<w[cur])
				u=dp[i][u];
			}
			dp[0][cur]=dp[0][u];
			if (w[u]>=w[cur])
			dp[0][cur]=u;
			cum[cur]=x+cum[dp[0][cur]];
			for (int i=1;i<20;i++)
			{
				if (dp[i-1][cur])
				dp[i][cur]=dp[i-1][dp[i-1][cur]];
			}
		}
		else
		{
			int v=u;
			last=(w[u]<=x);
			for (int i=19;i>=0;i--)
			{
				if (dp[i][v] && cum[u]-cum[dp[0][dp[i][v]]]<=x)
				{
					v=dp[i][v];
					last+=(1<<i);
				}
			}
			printf("%d\n",last);
		}
	}
}