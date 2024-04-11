#include<bits/stdc++.h>
 
using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b)
{
	return a.second < b.second;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <pair <int, int> > x(n);
	vector <pair <pair <int, int>, int> > scan;
	vector <int> uniq;
	int last = -2e9;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first >> x[i].second;
	}
	sort(x.begin(), x.end(), cmp);
	for(int i = 0; i < n; i++)
	{
		scan.push_back({{x[i].first - k + 1, -1}, x[i].second});
		scan.push_back({{x[i].first + 1, 1}, x[i].second});
		for(int j = 0; j < min(k, x[i].second - last); j++)
		{
			uniq.push_back(x[i].second - j);
		}
		last = x[i].second;
	}
	sort(scan.begin(), scan.end());
	sort(uniq.begin(), uniq.end());
	vector <int> left(scan.size()), right(scan.size());
	for(int i = 0; i < scan.size(); i++)
	{
		left[i] = lower_bound(uniq.begin(), uniq.end(), scan[i].second - k + 1) - uniq.begin();
		right[i] = lower_bound(uniq.begin(), uniq.end(), scan[i].second) - uniq.begin();
	}
	int Un = uniq.size();
	uniq.clear();
	uniq.shrink_to_fit();
	vector <int> ends(Un, -2e9);
	vector <int> val(Un, 0);
	vector <long long> ans(n + 1);
	for(int i = 0; i < scan.size(); i++)
	{
		int x = scan[i].first.first;
		int type = scan[i].first.second;
		int y = scan[i].second;
		for(int ind = left[i]; ind <= right[i]; ind++)
		{
			ans[val[ind]] += (x - ends[ind]);
			ends[ind] = x;
			val[ind] -= type;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}