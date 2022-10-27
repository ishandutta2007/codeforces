#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <vector <char> > A(n, vector <char> (n));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	vector <vector <int> > dp(n, vector <int> (n));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i != 0 && j!= 0)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
			}
			else if(i != 0)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else if(j != 0)
			{
				dp[i][j] = dp[i][j - 1];
			}
			if(A[i][j] != 'a')
			{
				dp[i][j]++;
			}
		}
	}
	if(dp[n - 1][n - 1] <= k)
	{
		for(int i = 0; i < 2 * n - 1; i++)
		{
			cout << 'a';
		}
		return 0;
	}
	set <pair <int, pair <int, int> > > Q;
	int e = -1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(dp[i][j] == k)
			{
				e = max(e, i + j);
			}
		}
	}
	if(e == -1)
	{
		Q.insert({0, {0, 0}});
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(dp[i][j] == k && i + j == e)
			{
				if(i != n - 1)
				{
					Q.insert({i + 1 + j, {i + 1, j}});
				}
				if(j != n - 1)
				{
					Q.insert({i + 1 + j, {i, j + 1}});
				}
			}
		}
	}
	for(int p = 0; p <= e; p++)
	{
		cout << "a";
	}
	for(int k = e + 1; k < 2 * n - 1; k++)
	{
		int minchar = 26;
		set <pair <int, int> > O;
		while(Q.size() > 0)
		{
			pair < int, pair <int, int> > v = *Q.begin();
			Q.erase(Q.begin());
			int x = v.second.first;
			int y = v.second.second;
			int sum = v.first;
			minchar = min(minchar, A[x][y] - 'a');
			O.insert({x, y});
		}
		while(O.size() > 0)
		{
			pair < int, int> v= *O.begin();
			O.erase(O.begin());
			int x = v.first;
			int y = v.second;
			if(A[x][y] - 'a' == minchar)
			{
				if(x != n - 1)
				{
					Q.insert({k + 1, {x + 1, y}});
				}
				if(y != n - 1)
				{
					Q.insert({k + 1, {x, y + 1}});
				}
			}
		}
		char t = minchar + 'a';
		cout << t;
	}
	return 0;
}