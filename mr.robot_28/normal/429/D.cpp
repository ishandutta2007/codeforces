#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int mindist = 1e9;
	int sum = 0;
	set <pair <int, int> > s1;
	set <pair <int, int> > s2;
	for(int i = 0; i < n; i++)
	{
		sum += a[i];
		while(s1.size() > 0)
		{
			pair <int, int> v = *s1.begin();
			if(mindist < (i - v.first) * (i - v.first))
			{
				s1.erase(s1.begin());
				s2.erase({v.second, v.first});
			}
			else
			{
				break;
			}
		}
		set <pair <int, int> > :: iterator it;
		it = s2.lower_bound({sum - sqrt(mindist), 0});
		int d = mindist;
		while(it != s2.end() && (it -> first - sum) * (it -> first - sum) <= d)
		{
			int y = it -> first;
			int x = it -> second;
			mindist = min(mindist, ((x - i) * (x - i) + (sum - y) * (sum - y)));
			it++;
		}
		s1.insert({i, sum});
		s2.insert({sum, i});
	}
	cout << mindist;
	return 0;
}