#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> c(n);
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	vector <vector <int> > ans;
	for(int it = 1; it <= n; it++)
	{
		int ind = -1;
		int val = (n + 1) / 2;
		if(it % 2 == 1)
		{
			val -= (it) / 2;
		}
		else
		{
			val += (it) / 2;
		}
		for(int i = 0; i < n; i++)
		{
			if(c[i] == val)
			{
				ind = i;
			}
		}
		if(it == 1)
		{
			vector <int> mass;
			mass.push_back(ind + 1);
			if(ind != n - 1)
			{
				mass.push_back(n - ind - 1);
			}
			vector <int> c1;
			for(int j = 0; j < n - ind - 1; j++)
			{
				c1.push_back(c[ind + 1 + j]);
			}
			for(int j = 0; j < ind + 1; j++)
			{
				c1.push_back(c[j]);
			}
			c = c1;
			if(mass.size() <= 1)
			{
				continue;
			}
			ans.push_back(mass);
		}
		else if(it % 2 == 1)
		{
			vector <int> mass;
			vector <int> c1;
			mass.push_back(it - 1);
			mass.push_back(ind + 1 - it + 1);
			if(ind != n -1)
			{
				mass.push_back(n - 1 - ind);
			}
			for(int j = 0; j < n - 1 - ind; j++)
			{
				c1.push_back(c[j + ind + 1]);
			}
			for(int j = it - 1; j < ind + 1; j++)
			{
				c1.push_back(c[j]);
			}
			for(int j = 0; j < it - 1; j++)
			{
				c1.push_back(c[j]);
			}
			c = c1;
			if(mass.size() <= 1)
			{
				continue;
			}
			ans.push_back(mass);
		}
		else
		{
	//		cout << ind << "\n";
			vector <int> mass;
			vector <int> c1;
			if(ind != 0)
			{
				mass.push_back(ind);
			}
			mass.push_back(n - it - ind + 1);
			mass.push_back(it - 1);
			for(int j = n - it + 1; j < n; j++)
			{
				c1.push_back(c[j]);
			}
			for(int j = ind; j < n - it + 1; j++)
			{
				c1.push_back(c[j]);
			}
			for(int j = 0; j < ind; j++)
			{
				c1.push_back(c[j]);
			}
			c = c1;
			if(mass.size() <= 1)
			{
				continue;
			}
			ans.push_back(mass);
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}