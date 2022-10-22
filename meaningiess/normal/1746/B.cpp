#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,s=0,ans=0;cin>>n;
		for (i=1;i<=n;i++) {cin>>a[i];s+=a[i];}
		for (i=1;i<=n && s<=n-i;i++) if (a[i]) ans++;
		cout<<ans<<endl;
	}
}