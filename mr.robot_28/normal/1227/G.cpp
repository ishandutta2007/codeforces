#include <bits/stdc++.h>
using namespace std;


signed main()
{
	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector <vector <pair <int, int> > > classes(n + 1);
	classes[0].push_back({0, n});
	vector <vector <int> > table(n, vector <int> (n + 1));
	for(int i = 0; i < n; i++)
	{
		int rc = a[i].first;
		int lc = a[i].first - classes[i].size();
		for(int j = 0; j < classes[i].size(); j++)
		{
			int l = classes[i][j].first;
			int r = classes[i][j].second;
			if(r != l)
			{
				if(rc <= 0)
			{
				classes[i + 1].push_back({l, r});
			}
			else if(r == l + 1 || lc <= 0)
			{
				classes[i + 1].push_back({l, r - 1});
				classes[i + 1].push_back({r, r});
				table[a[i].second][r] = 1;
			}
			else if(lc > r - l - 1)
			{
				for(int j = l; j <= r - 1; j++)
				{
					table[a[i].second][j] = 1;
				}
				classes[i + 1].push_back({l, r - 1});
				classes[i + 1].push_back({r, r});
				lc -= r - l - 1;
			}
			else
			{
				for(int j = l; j <= l + lc; j++)
				{
					table[a[i].second][j] = 1;
				}
				classes[i + 1].push_back({l, l + lc});
				classes[i + 1].push_back({l + lc + 1, r});
				lc = 0;
			}
			rc--;
			}
		}
		for(int j = 0; j  < classes[i].size(); j++)
		{
			int l = classes[i][j].first;
			int r = classes[i][j].second;
			if(r == l && rc <= 0)
			{
				classes[i + 1].push_back({l, r});
			}
			else if(r == l)
			{
				classes[i + 1].push_back({l, r});
				table[a[i].second][l] = 1;
				rc--;
			}
		}
	}
	cout << n + 1 << "\n";
	for(int j = 0; j < n + 1; j++){
		for(int i = 0; i < n; i++)
		{
			cout << table[i][j];
		}
		cout << "\n";
	}
	return 0;
}