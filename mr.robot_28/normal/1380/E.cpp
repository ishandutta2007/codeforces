#include <bits/stdc++.h>
                  
using namespace std;

signed main(){
	int n, m;
	cin >> n >> m;
	vector <int> ind(m);
	vector <set <pair <int, int> > > s(m);
	for(int i = 0; i < m; i++)
	{
		ind[i] = i;
	}
	int ans = n - 1;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	for(int i = 0; i < n; i++)
	{
		int j = i;
		while(j < n && a[j] == a[i])
		{
			j++;
		}
		ans -= (j - i - 1);
		s[a[i]].insert({i, j - 1});
		i = j - 1;
	}
	cout << ans << "\n";
	for(int i = 0; i < m - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int k1, k2;
		k1 = ind[a];
		k2 = ind[b];
		set <pair <int, int> > :: iterator it1, it2;
		if(s[k1].size() < s[k2].size())
		{
			for(it1 = s[k1].begin(); it1 != s[k1].end(); it1++)
			{
				int al, ar;
				al = it1 -> first;
				ar = it1 -> second;
				it2 = s[k2].lower_bound({ar + 1, 0});
				if(s[k2].size() != 0 && it2 != s[k2].end() && it2 -> first == ar + 1)
				{
					ar = it2 -> second;
					s[k2].erase(it2);
					ans--;
				}
				it2 = s[k2].lower_bound({ar + 1, 0});
				if(s[k2].size() != 0 && it2 != s[k2].begin())
				{
					it2--;
					if(it2 -> second == al - 1)
					{
						al = it2 -> first;
						s[k2].erase(it2);
						ans--;
					}
				}
				s[k2].insert({al, ar});
			}
			ind[a] = k2;
		}
		else
		{
			for(it1 = s[k2].begin(); it1 != s[k2].end(); it1++)
			{
				int al, ar;
				al = it1 -> first;
				ar = it1 -> second;
				it2 = s[k1].lower_bound({ar + 1, 0});
				if(s[k1].size() != 0 && it2 != s[k1].end() && it2 -> first == ar + 1)
				{
					ar = it2 -> second;
					s[k1].erase(it2);
					ans--;
				}
				it2 = s[k1].lower_bound({ar + 1, 0});
				if(s[k1].size() != 0 && it2 != s[k1].begin())
				{
					it2--;
					if(it2 -> second == al - 1)
					{
						al = it2 -> first;
						s[k1].erase(it2);
						ans--;
					}
				}
				s[k1].insert({al, ar});
			}
		}
		cout << ans << "\n";
	}
	return 0;
}