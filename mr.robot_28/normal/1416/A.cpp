#include<bits/stdc++.h>
using namespace std;
 
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		vector <pair <int, int> > mass;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			mass.push_back({a[i], i});
		}
		sort(mass.begin(), mass.end());
		vector <int> ans(n, -1);
		vector <int> index(n);
		for(int i = 0; i < n; i++)
		{
			index[i] = i + 1;
		}
		for(int i = 0; i < n; i++)
		{
			int j = i + 1;
			int maxa = mass[i].second + 1;
			while(j < n && mass[j].first == mass[i].first)
			{
				maxa = max(maxa, mass[j].second - mass[j - 1].second);
				j++;
			}
			j--;
			maxa = max(maxa, n - mass[j].second);
			i = j;
			while(index.size() > 0 && index.back() >= maxa)
			{
				ans[index.back() - 1] = mass[i].first;
				index.pop_back();
			}
		}
		for(int i = 0; i < n; i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}