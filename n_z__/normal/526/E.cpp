#include<bits/stdc++.h>
using namespace std;
long long a[2000001];
int f[2000001],g[2000001];
int main()
{
	int n,q;
	cin>>n>>q;
	for(int x=1;x<=n;x++)cin>>a[x],a[x+n]=a[x];
	for(int x=1;x<=n+n;x++)a[x]+=a[x-1];
	for(int x=1,y;x<=q;x++)
	{
		cin>>y;
		int z=0,ans=1+(n-1)*(a[n]>y);
		for(int j=1;j<=n+n;j++)
		{
			for(;a[j]-a[z]>y;z++);
			f[j]=f[z]+1;
			g[j]=j+(z!=0)*(g[z]-j);
			if(j-g[j]>=n)ans=min(ans,f[j]-f[g[j]]);
		}
		cout<<ans<<endl;
	}
}