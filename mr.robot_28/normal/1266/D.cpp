#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	vector <int> cnt(n);
	for(int i = 0; i < m; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		cnt[x - 1] += d;
		cnt[y - 1] -= d;
	}
	vector <int> cntplus(n), cntminus(n);
	for(int i = 0; i < n; i++)
	{
		if(cnt[i] > 0)
		{
			cntplus[i] = cnt[i];
		}
		else
		{
			cntminus[i] = -cnt[i];
		}
	}
	int i = 0, j = 0;
	vector <pair <pair <int, int>, int> > ans;
	while(i < n && j < n)
	{
		while(j < n && cntplus[i])
		{
			while(j < n && !cntminus[j])
			{
				j++;
			}
			if(cntminus[j] >= cntplus[i])
			{
				cntminus[j] -= cntplus[i];
				ans.push_back({{i, j}, cntplus[i]});
				cntplus[i] = 0;
			}
			else
			{
				ans.push_back({{i, j}, cntminus[j]});
				cntplus[i] -= cntminus[j];
				cntminus[j] = 0;
				j++;
			}
		}
		i++;
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first.first + 1<< " " << ans[i].first.second + 1 << " " << ans[i].second << "\n";
	}
	return 0;
}