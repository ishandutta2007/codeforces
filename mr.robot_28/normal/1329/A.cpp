#include <bits/stdc++.h>
 
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <pair <int, int> > l(m);
	for(int i = 0; i < m; i++)
	{
		cin >> l[i].first;
		l[i].second = i;
	}
	vector <int> ans(m);
	int j = 0;
	vector <int> maxright(n);
	for(int i = 0; i < l.size(); i++)
	{
		if(j + l[i].first > n)
		{
			cout << -1;
			return 0;
		}
		ans[i] = j;
			maxright[i] = ans[i] + l[i].first - 1;
		if(i != 0)
		{
			maxright[i] = max(maxright[i - 1], maxright[i]);
		}
		j++;
	}
	int right = n - 1;
	for(int i = l.size() - 1; i >= 0; i--)
	{
		if(maxright[i] < right)
		{
			ans[i] += right - ans[i] - l[i].first + 1;
		}
		else
		{
			break;
		}
		right -= l[i].first;
	}
	if(ans[0] > 0)
	{
		cout << -1;
		return 0;
	}
	for(int i = 0; i < m; i++)
	{
		cout << ans[i] + 1 << " ";
	}
	return 0;
}