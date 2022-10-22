#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[1010][1010];int e[1010][1010],a[1010],l[1010],r[1010],st[20][1010];
int main()
{
	int n,m,i,j,k,ans=0;cin>>n>>m;
	for (i=1;i<=n;i++) cin>>s[i]+1;
	for (i=1;i<=n;i++)
	{
		int lst=1;for (j=2;j<=m+1;j++)
		{
			if (s[i][j]!=s[i][j-1])
			{
				for (k=lst;k<j;k++) e[i][k]=j-1;
				lst=j;
			}
		}
	}
	for (i=1;i<=m;i++)
	{
		int tp=0,lst=1;
		for (j=2;j<=n+1;j++) if (s[j][i]!=s[j-1][i])
		{
			a[++tp]=j-lst;l[tp]=lst;r[tp]=j-1;lst=j;
		}
		for (j=2;j<tp;j++) if (a[j-1]>=a[j] && a[j]<=a[j+1])
		{
			int mn=10000;
			for (k=l[j]-(r[j]-l[j]+1);k<=r[j]+(r[j]-l[j]+1);k++)
			{
				mn=min(mn,e[k][i]);
			}
			ans+=(mn-i+1);
		}
	}
	cout<<ans;
}