/**
 *    author:  Mohamed.Abo_Okail
 *    created: 05/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
int grid1[50][50], grid2[50][50];
int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	int n, m, s = 0;
	cin >> n >> m;
	vector< pair<int, int> > v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid1[i][j];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if(grid1[i][j] && grid1[i - 1][j - 1] && grid1[i][j - 1] && grid1[i - 1][j])
			{
				v.push_back({i, j});
				grid2[i][j] = 1;
				grid2[i][j - 1] = 1;
				grid2[i - 1][j] = 1;
				grid2[i - 1][j - 1] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(grid2[i][j] != grid1[i][j])
				return cout <<  -1 << endl, 0;
		}
	}

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}

}