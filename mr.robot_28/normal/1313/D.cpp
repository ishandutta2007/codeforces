#include<bits/stdc++.h>
 
using namespace std;
vector <int> color;
int n, m, k;
int cnt_byte(int a)
{
	int ans = 0;
	while(a > 0)
	{
		ans += a % 2;
		a = a / 2;
	}
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	vector <pair <int, int> > upd(n);
	for(int i = 0; i < n; i++)
	{
		cin >> upd[i].first >> upd[i].second;
	}
	sort(upd.begin(), upd.end());
	vector <int> dp((1 << k), -1e9);
	dp[0] = 0;
	vector <pair <pair <int, int>, int> > scan;
	for(int i = 0; i < upd.size(); i++)
	{
		scan.push_back({{upd[i].first, 1}, i});
		scan.push_back({{upd[i].second + 1, -1}, i});
	}
	sort(scan.begin(), scan.end());
	set <int> free;
	for(int i = 0; i < k; i++)
	{
		free.insert(i);
	}
	vector <int> dp1((1 << k), -1e9);
	vector <int> b(n);
	vector <int> calc((1 << k));
	for(int i = 0; i < (1 << k); i++)
	{
		calc[i] = cnt_byte(i) % 2;
	}
	int j = 0;
	int numb = 0;
	int last = 1;
	while(j < scan.size())
	{
		numb++;
		int x = scan[j].first.first;
		for(int p = 0; p < (1 << k); p++)
		{
			if(calc[p] % 2 == 1)
			{
				dp[p] += (x - last);
			}
			dp1[p] = -1e9;
		}
		int mask = (1 << k) - 1;
		while(j < scan.size() && x == scan[j].first.first && scan[j].first.second == -1)
		{
			int ind = b[scan[j].second];
			mask -= (1 << ind);
			free.insert(ind);
			j++;
		}
		for(int p = 0; p < (1 << k); p++)
		{
			dp1[p & mask] = max(dp1[p & mask], dp[p]);
		}
		while(j < scan.size() && x == scan[j].first.first)
		{
			int ind = (*free.begin());
			free.erase(free.begin());
			b[scan[j].second] = ind;
			for(int p = 0; p < (1 << k); p++)
			{
				if((p & (1 << ind)) == 0)
				{
					dp1[p + (1 << ind)] = max(dp1[p + (1 << ind)], dp1[p]);
				}
			}
			j++;
		}
		for(int p = 0; p < (1 << k); p++)
		{
			dp[p] = dp1[p];
			dp1[p] = -1e9;
		}
		last = scan[j - 1].first.first;
	}
	int ans = 0;
	for(int i = 0; i < (1 << k); i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}