#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> mass1(n);
	vector <int> p(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		mass1[i] = a[i];
	}
	sort(mass1.begin(), mass1.end());
	for(int i = 0; i < n; i++)
	{
		a[i] = lower_bound(mass1.begin(), mass1.end(), a[i]) - mass1.begin();
	}
	vector <pair <int, int> >mass2;
	for(int i = 0; i < n; i++)
	{
		mass2.push_back({a[i], i});
	}
	sort(mass2.begin(), mass2.end());
	vector <pair <int, int> > ans;
	for(int i = n - 1; i >= 0; i--)
	{
		int j = i;
		while(j >= 0 && mass2[j].first == mass2[i].first)
		{
			j--;
		}
		j++;
		for(int k = j; k <= i; k++)
		{
		int ind = mass2[k].second;
		int ind1 = mass2[k].second;
		for(int d = i + 1; d < n; d++)
		{
			if(d == i + 1 && mass2[d].second < ind)
			{
				mass2[k].second = mass2[d].second;
			}
			if(mass2[d].second > ind)
			{
				continue;
			}
			ans.push_back({mass2[d].second, ind});
			if(d == n - 1 || mass2[d + 1].second > ind)
			{
				mass2[d].second = ind;
			}
			else
			{
				mass2[d].second = mass2[d + 1].second;
			}
		}
		}
		i = j;
	}
	for(int i = 0; i < n  - 1; i++)
	{
		if(mass2[i + 1].second < mass2[i].second && mass2[i + 1].first > mass2[i].first)
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
	return 0;
}