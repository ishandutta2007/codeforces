#include <bits/stdc++.h>

using namespace std;

signed main()
{
	int n;
	map<int, int> a;
	int ans=0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int cac;
		cin>>cac;
		a[cac]++;
		ans=max(ans, a[cac]);
	}
	cout<<ans;
}