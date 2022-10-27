#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > A(n, vector <int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	vector <pair <int, int> > ans;
	if(n < m)
	{
		for(int i = 0; i < n; i++)
		{
			int x = 1e9;
			for(int j = 0; j < m; j++)
			{
				x = min(x, A[i][j]);
			}
			for(int j = 0; j < m; j++)
			{
				A[i][j] -= x;
			}
			while(x--)
			{
				ans.push_back({0, i + 1});
			}
		}
		for(int j = 0; j < m; j++)
		{
			int x = 1e9;
			for(int i = 0; i < n; i++)
			{
				x = min(x, A[i][j]);
			}
			for(int i = 0; i < n; i++)
			{
				A[i][j] -= x;
			}
			while(x--)
			{
				ans.push_back({1, j + 1});
			}
		}
	}
	else
	{
		for(int j = 0; j < m; j++)
		{
			int x = 1e9;
			for(int i = 0; i < n; i++)
			{
				x = min(x, A[i][j]);
			}
			for(int i = 0; i < n; i++)
			{
				A[i][j] -= x;
			}
			while(x--)
			{
				ans.push_back({1, j + 1});
			}
		}
		for(int i = 0; i < n; i++)
		{
			int x = 1e9;
			for(int j = 0; j < m; j++)
			{
				x = min(x, A[i][j]);
			}
			for(int j = 0; j < m; j++)
			{
				A[i][j] -= x;
			}
			while(x--)
			{
				ans.push_back({0, i + 1});
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] != 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		if(ans[i].first == 0)
		{
			cout << "row ";
		}
		else
		{
			cout << "col ";
		}
		cout << ans[i].second << "\n";
	}
    return 0;
}