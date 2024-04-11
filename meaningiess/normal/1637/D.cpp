#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[111][21111],a[111],b[111],s[111];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,sum=0;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) cin>>b[i];
		for (i=1;i<=n;i++) s[i]=s[i-1]+a[i]+b[i];sum=s[n];
		for (j=0;j<=n;j++) for (i=0;i<=sum;i++) f[j][i]=1e16;
		f[0][0]=0;
		for (i=1;i<=n;i++)
		{
			for (j=0;j<=sum;j++)
			{
				if (j>=a[i])f[i][j]=min(f[i][j],f[i-1][j-a[i]]+2*(j-a[i])*a[i]+2*(s[i-1]-j+a[i])*b[i]);
				if (j>=b[i])f[i][j]=min(f[i][j],f[i-1][j-b[i]]+2*(j-b[i])*b[i]+2*(s[i-1]-j+b[i])*a[i]);
			}
		}
		ll ans=1e16;
		for (i=0;i<=sum;i++) ans=min(ans,f[n][i]);
		for (i=1;i<=n;i++) ans+=a[i]*a[i]*(n-1)+b[i]*b[i]*(n-1);
		cout<<ans<<endl;
	}
}