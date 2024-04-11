#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> t(n);
	vector <pair <int, int> > mass;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> t[i];
		mass.push_back({a[i], t[i]});
	}
	sort(mass.begin(), mass.end());
	multiset <int> timer;
	int ans = 0;
	int sum = 0;
	int pred = 0;
	for(int i = 0; i < mass.size(); i++)
	{
		while(pred < mass[i].first)
		{
			if(timer.size() == 0)
			{
				break;
			}
			sum += *timer.begin();
			ans += sum;
			timer.erase(timer.begin());
			pred++;
		}
		int j = i;
		while(j < mass.size() && mass[j].first == mass[i].first)
		{
			sum += mass[j].second;
			timer.insert(-mass[j].second);
			j++;
		}
		pred = mass[i].first;
		i = j - 1;
	}
	while(timer.size() > 0)
	{
		sum += *timer.begin();
		ans += sum;
		timer.erase(timer.begin());
	}
	cout << ans;
	return 0;
}