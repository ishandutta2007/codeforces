#include <bits/stdc++.h>

using namespace std;

int d[1005], h[1005];

signed main()
{
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		int n, x;
		cin>>n>>x;
		int dmax=0, rmvmax=0;;
		for(int i=1; i<=n; i++)
		{
			cin>>d[i]>>h[i];
			dmax=max(dmax, d[i]);
			rmvmax=max(rmvmax, d[i]-h[i]);
		}
		if(dmax>=x) cout<<1<<endl;
		else if(rmvmax==0) cout<<-1<<endl;
		else cout<<(x-dmax-1)/rmvmax+2<<endl;
	}
}