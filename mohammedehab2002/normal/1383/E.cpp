#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[1000005][2][2],tot0=1,tot1,bl[1000005];
int nex[1000005],f=1;
int main()
{
	string s;
	cin >> s;
	int n=s.size();
	nex[n-1]=n;
	for (int i=n-2;i>=0;i--)
	{
		nex[i]=nex[i+1];
		if (s[i]!=s[i+1])
		nex[i]=i+1;
	}
	dp[n][1][0]=1;
	dp[n][0][1]=1;
	for (int i=n-1;i>=0;i--)
	{
		if (s[i]=='0')
		{
			dp[i][0][0]=(dp[nex[i]][1][0]*(nex[i]-i))%mod; 
			tot0=(tot0-bl[nex[i]-i]+mod)%mod;
			if (nex[i]!=n)
			bl[nex[i]-i]=dp[nex[i]][1][0];
			tot0=(tot0+bl[nex[i]-i]+f)%mod;
		}
		else
		{
			tot1=(tot1+dp[nex[i]][0][1])%mod;
			f=0;
		}
		dp[i][0][1]=tot0;
		dp[i][1][0]=tot1;
	}
	printf("%d",(dp[0][0][0]+dp[0][1][0])%mod);
}