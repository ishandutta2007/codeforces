#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1111];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,k,ans=1;cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for (i=1;i<=n;i++)
		{
			for (j=i+1;j<=n;j++)
			{
				int res=0;
				for (k=1;k<=n;k++) if (k==i || k==j || (a[k]-a[i])*(k-j)==(a[k]-a[j])*(k-i)) res++;
				ans=max(ans,res);
			}
		}
		cout<<n-ans<<endl;
	}
}