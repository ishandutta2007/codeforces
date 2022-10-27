#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp1(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
	return a.first.first * b.first.second > a.first.second * b.first.first;
}
bool cmp(pair <int, int> a, pair <int, int> b)
{
	return a.first * b.second > a.second * b.first;
}
signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, n, m;
	cin >> k >> n >> m;
	vector <int> a(k);
	for(int i = 0; i < k; i++)
	{
		cin >> a[i];
	}
	vector <vector <pair <pair <int, int>, int> > > updates(k);
	vector <pair <pair <int, int>, int> > mass;
	vector <int> type(n);
	for(int i = 0; i < n; i++)
	{
		int t, ind, b;
		cin >> t >> ind >> b;
		ind--;
		type[i] = t;
		updates[ind].push_back({{t, b}, i});
	}
	for(int i = 0; i < k; i++)
	{
		sort(updates[i].begin(), updates[i].end());
		vector <pair <int, int> > mass1, mass2;
		int w = -1;
		int ind1 = -1;
		int sum1 = a[i];
		for(int j = 0; j < updates[i].size(); j++)
		{
			if(updates[i][j].first.first == 1)
			{
				ind1 = updates[i][j].second;
				w = updates[i][j].first.second;
			}
			else if(updates[i][j].first.first == 2)
			{
				mass1.push_back({updates[i][j].first.second, updates[i][j].second});
			}
			else
			{
				mass2.push_back({updates[i][j].first.second, updates[i][j].second});
			}
		}
		if(w > a[i])
		{
			mass1.push_back({w - a[i], ind1});
		}
		sort(mass1.begin(), mass1.end());
		reverse(mass1.begin(), mass1.end());
		reverse(mass2.begin(), mass2.end());
			int it1 = 0, it2 = 0;
			int c = a[i];
			while(it1 < mass1.size() && it2 < mass2.size())
			{
				if(cmp({mass1[it1].first + c, c}, {mass2[it2].first, 1}))
				{
					mass.push_back({{mass1[it1].first, c}, mass1[it1].second});
					c += mass1[it1].first;
					it1++;
				}
				else
				{
					mass.push_back({{mass2[it2].first - 1, 1}, mass2[it2].second});
					it2++;
				}
			}
			while(it1 < mass1.size())
			{
				mass.push_back({{mass1[it1].first, c}, mass1[it1].second});
				c += mass1[it1].first;
				it1++;
			}
			while(it2 < mass2.size())
			{
				mass.push_back({{mass2[it2].first - 1, 1}, mass2[it2].second});
				it2++;
			}
	}
	sort(mass.begin(), mass.end(), cmp1);
	k = mass.size();
	cout << min(m, k) << "\n";
	vector <int> mass01, mass02, mass03;
	for(int i = 0; i < min(m, k); i++)
	{
		int ind = mass[i].second;
		if(type[ind] == 1)
		{
			mass01.push_back(ind);
		}
		else if(type[ind] == 2)
		{
			mass02.push_back(ind);
		}
		else
		{
			mass03.push_back(ind);
		}
	}
	for(int i = 0; i < mass01.size(); i++)
	{
		cout << mass01[i] + 1 << " ";
	}
	for(int i = 0; i< mass02.size(); i++)
	{
		cout << mass02[i] + 1 << " ";
	}
	for(int i = 0; i < mass03.size(); i++)
	{
		cout << mass03[i] + 1 << " ";
	}
    return 0;
}