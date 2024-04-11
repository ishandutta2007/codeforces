#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > cac;

int a[55][55], b[55][55];

signed main()
{
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<m; j++)
		{
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
			{
				b[i][j]=1;
				b[i+1][j]=1;
				b[i][j+1]=1;
				b[i+1][j+1]=1;
				cac.push_back({i,j});
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(a[i][j]!=b[i][j])
			{
				cout<<"-1";
				return 0;
			}
		}
	}
	cout<<cac.size()<<endl;
	for(auto i:cac)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
}