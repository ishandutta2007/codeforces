#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,a[5000],b[3003][3003],b1[5000],x;
int combination(int n,int k)
{
	int sum=0;
	if (n<k) return 0;
	if (n==k||k==0)
	{
		return 1;
	}
	else
	{
		return combination(n-1,k)+combination(n-1,k-1);
	}
}
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;ans=0;x=0;
		memset(b1,0,sizeof(b1));
		memset(b,0,sizeof(b)); 
		for (int i=1;i<=n;i++) cin>>a[i],b[i][a[i]]++;
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=n;j++)
		    b[i][j]+=b[i-1][j];
		/*for (int i=1;i<=n;i++)
		  for (int j=i+1;j<=n;j++)
		  if (a[i]==a[j])
		    for (int k=i+1;k<=j-1;k++)
		      ans+=(b[n][a[k]]-b[j][a[k]]);*/
		for (int i=1;i<=n;i++)
		{
			int j=i+2;
			x=b[n][a[i+1]]-b[j][a[i+1]];
			if (a[i]==a[j]) ans+=x;//cout<<x<<" "<<ans<<" "<<i<<" "<<j<<endl;
			while (j<n)
			{
				j++;
				x+=b[n][a[j-1]]-b[j][a[j-1]];
				x-=b[j-2][a[j]]-b[i][a[j]];
				if (a[i]==a[j]) ans+=x;//cout<<x<<" "<<ans<<" "<<i<<" "<<j<<endl;
			}
			
		}
	    cout<<ans<<endl;
	}
}