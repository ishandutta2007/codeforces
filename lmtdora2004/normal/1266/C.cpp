#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

signed main()
{
	cin>>n>>m;
	if(n==m&&n==1)
	{
		cout<<0;
		return 0;
	}
	if(m==1)
	{
		for(int i=1; i<=n; i++)
		{
			cout<<i+1<<endl;
		}
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cout<<i*(n+j)<<" ";
		}
		cout<<endl;
	}
}