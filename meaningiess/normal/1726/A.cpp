#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mn[2020][2020],mx[2020][2020],a[2020];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,ans;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		ans=a[n]-a[1];
		for (i=2;i<=n;i++) ans=max(ans,a[i-1]-a[i]);
		for (i=1;i<=n;i++) {mx[i][i]=mn[i][i]=a[i];for (j=i+1;j<=n;j++) mn[i][j]=min(mn[i][j-1],a[j]),mx[i][j]=max(mx[i][j-1],a[j]);}
		for (i=2;i<n;i++) ans=max(ans,a[n]-mn[1][i]);
		for (i=2;i<n;i++) ans=max(ans,mx[i][n]-a[1]);
		cout<<ans<<endl;
	}
}