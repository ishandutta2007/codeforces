#include <bits/stdc++.h>

using namespace std;

signed main()
{
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		int s, i, e;
		cin>>s>>i>>e;
		int lo=0, hi=e;
		while(lo<hi)
		{
			int mid=(lo+hi+1)/2;
			if(i+mid<s+(e-mid))
			{
				lo=mid;
			}
			else
			{
				hi=mid-1;
			}
		}
		if(s+e<=i) cout<<0;
		else cout<<lo+1;
		cout<<endl;
	}
}