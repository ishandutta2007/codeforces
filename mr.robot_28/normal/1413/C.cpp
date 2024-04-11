#include<bits/stdc++.h>
using namespace std;
bool cmp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
	return a.first.second < b.first.second;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector <int> a(6);
	for(int i = 0; i < 6; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int t = 6;
	int n;
	cin >> n;
	vector <int> b(n);
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	int ans = 1e18;
	vector <pair <pair <int, int>, int> > vec;
	int cnt1 = 0;
	int maxval = 1e18;
	for(int i = 0; i < n; i++)
	{
		cnt1++;
		int j = i;
		while(j < n && b[j] == b[i])
		{
			j++;
		}
		int c = j - i;
		maxval = min(maxval, b[i] - a[c - 1]);
		for(int i1 = 0; i1 < t; i1++)
		{
			for(int j1 = i1; j1 < t; j1++)
			{
				vec.push_back({{b[i] - a[j1], b[i] - a[i1]}, i});
			}
		}
		i = j - 1;
	}
	sort(vec.begin(), vec.end(), cmp);
	for(int i = 0; i < vec.size(); i++)
	{
	//	cout << vec[i].first.first << " " << vec[i].first.second << " " << vec[i].second <<"\n";
	}
	vector <bool> used(n);
	int cnt = 0;
	int max1 = 0;
	set <pair <int, int> > s;
	vector <int> pred(n, -1);
	for(int i = 0; i < vec.size(); i++)
	{
		if(pred[vec[i].second] != -1)
		{
			s.erase({pred[vec[i].second], vec[i].second});
		}
		pred[vec[i].second] = max(vec[i].first.first, pred[vec[i].second]);
		s.insert({pred[vec[i].second], vec[i].second});
		max1 = max(max1, vec[i].first.second);
		if(!used[vec[i].second])
		{
			cnt++;
			used[vec[i].second] = 1;
		}
		if(cnt == cnt1)
		{
			ans = min(ans, max1 - s.begin() -> first);
		}
	}
	cout << ans;
	return 0;
}