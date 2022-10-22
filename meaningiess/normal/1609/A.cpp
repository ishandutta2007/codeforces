#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[20];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,tp=0,mx=0;ll ans=0;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) {while (a[i]%2==0) a[i]/=2,tp++;mx=max(mx,a[i]),ans+=a[i];}
		ans+=((1ll<<tp)-1)*mx;cout<<ans<<endl;
	}
}