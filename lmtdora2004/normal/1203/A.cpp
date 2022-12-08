#include <bits/stdc++.h>

using namespace std;

signed main()
{
	int q;
	cin>>q;
	for(int i=1; i<=q; i++)
	{
		int a[250];
		map<int, int> cnt;
		int n;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		for(int i=2; i<=n; i++)
		{
			cnt[a[i]-a[i-1]]++;
		}
		if(cnt[-1]>=n-2||cnt[1]>=n-2)
		{
			cout<<"YES\n"; 
		}
		else
		{
			cout<<"NO\n";
		}
	}
}