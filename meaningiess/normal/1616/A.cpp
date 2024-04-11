#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,a[1111],h[111]={};cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			h[abs(a[i])]++;
		}
		int ans=0;
		for (i=1;i<=100;i++)
		{
			ans+=min(h[i],2);
		}
		ans+=min(h[0],1);
		cout<<ans<<endl;
	}
}