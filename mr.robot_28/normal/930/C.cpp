#include<bits/stdc++.h>
 
using namespace std;
#define double long double
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <pair <int, int> > A(n);
	vector <pair <int, int> > scan;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first >> A[i].second;
		A[i].first--;
		A[i].second--;
		scan.push_back({A[i].first, -1});
		scan.push_back({A[i].second, 1});
	}
	sort(scan.begin(), scan.end());
	vector <int> cnt(m);
	int bal = 0;
	for(int i = 0; i < scan.size(); i++)
	{
		cnt[scan[i].first] = max(bal, cnt[scan[i].first]);
		bal -= scan[i].second;
		cnt[scan[i].first] = max(bal, cnt[scan[i].first]);
		if(i == scan.size() - 1)
		{
			for(int j = scan[i].first + 1; j < m; j++)
			{
				cnt[j] = bal;
			}
		}
		else
		{
			for(int j = scan[i].first + 1; j < scan[i + 1].first; j++)
			{
				cnt[j] = bal;
			}
		}
	}
	vector <int> d(m + 1, 1e9);
	d[0] = -1e9;
	int ans = 0;
	vector <int> cnt1(m), cnt2(m);
	for(int i = 0; i < m; i++)
	{
		int j = upper_bound(d.begin(), d.end(), cnt[i]) - d.begin();
		if(d[j - 1] <= cnt[i] && cnt[i] < d[j])
		{
			d[j] = cnt[i];
			cnt2[i] = j;
		}
	}
	vector <int> d1(m + 1, 1e9);
	d1[0] = -1e9;
	for(int i = m - 1; i >= 0; i--)
	{
		int j = upper_bound(d1.begin(), d1.end(), cnt[i]) - d1.begin();
		if(d1[j - 1] <= cnt[i] && cnt[i] < d1[j])
		{
			cnt1[i] = j;
			d1[j] = cnt[i];
		}
	}
	for(int i = 0; i < m; i++)
	{
		ans = max(ans, cnt2[i] + cnt1[i] - 1);
	}
	cout << ans;
	return 0;
}