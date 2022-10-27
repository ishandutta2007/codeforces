#include <bits/stdc++.h>
using namespace std;

 
signed main(){
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
	vector <vector <bool> > used(n, vector <bool> (m, false));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] && j < m - 1 && i < n - 1 && A[i][j + 1] && A[i + 1][j] && A[i + 1][j + 1])
			{
				ans.push_back({i + 1, j + 1});
				used[i][j] = used[i + 1][j] = used[i][j + 1] = used[i + 1][j + 1] = true;
			}
			if(A[i][j] && !used[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}