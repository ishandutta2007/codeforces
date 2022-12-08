#include <bits/stdc++.h>
#define int long long
int base=37, mod=1000000007;
using namespace std;

int dp[8005], cac[8005];
string s;
int n;
int lcp[8005][8005];

signed main()
{
	cin>>s;
	n=s.size();
	s='!'+s;
	for(int i=1; i<=n; i++)
	{
		cac[i]=cac[i/10]+1;
		for(int j=1; j<=n; j++)
		{
			lcp[i][j]=(s[i]==s[j]?lcp[i-1][j-1]+1:0);
		}
	}
	for(int i=1; i<=n; i++)
	{
		dp[i]=69420;
		for(int j=1; j<=i; j++)
		{
			int k=i, tot=1;
			while(k>=j&&lcp[i][k]>=j)
			{
				dp[i]=min(dp[i], dp[k-j]+cac[tot]+j);
				//cout<<i<<" "<<k<<" "<<dp[i]<<endl;
				tot++, k-=j;
			}
		}
	}
	cout<<dp[n];
}