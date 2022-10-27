#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		vector <vector <char> > A(n, vector <char> (m));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> A[i][j];
			}
		}
		if(A[n - 1][m - 1] == 'B')
		{
			cout << "No\n";
			continue;
		}
		bool flag = true;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(A[i][j] == 'B')
				{
					if(i > 0)
					{
						if(A[i - 1][j] == 'G')
						{
							flag = false;
						}
						if(A[i - 1][j] == '.')
						{
							A[i - 1][j] = '#';
						}
					}
					if(j > 0)
					{
						if(A[i][j - 1] == 'G')
						{
							flag = false;
						}
						if(A[i][j - 1] == '.')
						{
							A[i][j - 1] = '#';
						}
					}
					if(i < n - 1)
					{
						if(A[i + 1][j] == 'G')
						{
							flag = false;
						}
						if(A[i + 1][j] == '.')
						{
							A[i + 1][j] = '#';
						}
					}
					if(j < m - 1)
					{
						if(A[i][j + 1] == 'G')
						{
							flag = false;
						}
						if(A[i][j + 1] == '.')
						{
							A[i][j + 1] = '#';
						}
					}
				}
			}
		}
		if(!flag)
		{
			cout << "No\n";
			continue;
		}
		queue <pair <int, int> > q;
		vector <vector <bool> > used(n, vector <bool> (m));
		if(A[n - 1][m - 1] != '#'){
		q.push({n - 1, m - 1});
		used[n - 1][m - 1] = true;
		}
		while(q.size() != 0)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(x > 0 && A[x - 1][y] != '#' && !used[x - 1][y]){
				used[x - 1][y] = true;
				q.push({x - 1, y});
			}
			if(y > 0 && A[x][y - 1] != '#' && !used[x][y - 1]){
				used[x][y - 1] = true;
				q.push({x, y - 1});
			}
			if(x < n - 1 && A[x + 1][y] != '#' && !used[x + 1][y]){
				used[x + 1][y] = true;
				q.push({x + 1, y});
			}
			if(y < m - 1 && A[x][y + 1] != '#' && !used[x][y + 1]){
				used[x][y + 1] = true;
				q.push({x, y + 1});
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(A[i][j] == 'G' && !used[i][j])
				{
					flag = false;
				}
			}
		}
		if(!flag){
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
		}
	}
	return 0;
}