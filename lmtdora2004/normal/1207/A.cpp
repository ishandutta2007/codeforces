#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
	{
		int ans=0;
		int b, p, f, h, c;
		cin>>b>>p>>f>>h>>c;
		if(h>c)
		{
			int take=min(p, b/2);
			p-=take;
			b-=take*2;
			ans+=take*h;
			take=min(f, b/2);
			ans+=take*c;
		}
		else
		{
			int take=min(f, b/2);
			f-=take;
			b-=take*2;
			ans+=take*c;
			take=min(p, b/2);
			ans+=take*h;
		}
		cout<<ans<<endl;
	}
}