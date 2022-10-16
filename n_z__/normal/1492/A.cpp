#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int p,a,b,c;
		cin>>p>>a>>b>>c;
		int ans=(a-p%a)%a;
		ans=min(ans,(b-p%b)%b);
		ans=min(ans,(c-p%c)%c);
		cout<<ans<<endl;
	}
}