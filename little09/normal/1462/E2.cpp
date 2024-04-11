#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[200005],s[200005]; 
long long C[200005][101]; 
long long ans;
const long long mod=1000000007;
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int main()
{
	C[0][0]=1;
	for (int i=1;i<=200000;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=100;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	int T=read();
	while (T--)
	{
		cin >> n >> m >> k;
		for (int i=1;i<=n;i++) a[i]=0;
		for (int i=1;i<=n;i++) 
		{
			int x=read();
			a[x]++;
		}
		for (int i=1;i<=n;i++) s[i]=(s[i-1]+a[i])%mod;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			int u=i+k;
			if (u>n) u=n;
			for (int j=1;j<=min(m,a[i]);j++)
			{
				ans=(ans+C[a[i]][j]*C[s[u]-s[i]][m-j])%mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}