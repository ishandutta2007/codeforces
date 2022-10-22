#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010],ans[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,q,i,nw=0;cin>>n>>q;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=n;i;i--)
		{
			if (nw<q && nw<a[i]) nw++,ans[i]=1;
			else if (nw>=a[i]) ans[i]=1;
			else ans[i]=0;
		}
		for (i=1;i<=n;i++) cout<<ans[i];cout<<endl;
	}
}