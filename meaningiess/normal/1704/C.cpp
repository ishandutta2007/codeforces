#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010],b[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,l=1,r=1e9+1,ans;cin>>n>>m;ans=m;
		for (i=1;i<=m;i++) cin>>a[i];
		sort(a+1,a+m+1);
		for (i=1;i<=m;i++) b[i]=a[i]-a[i-1]-1;
		b[1]=a[1]-a[m]+n-1;
		sort(b+1,b+m+1);
		int t=0;
		for (i=m;i;i--)
		{
			ans+=min(b[i],t*2);
			if (b[i]<=t*2)
			{
				continue;
			}
			else if (b[i]<=t*2+1)
			{
				t++;
			}
			else
			{
				ans++;t+=2;
			}
		}
		cout<<ans<<endl;
	}
}