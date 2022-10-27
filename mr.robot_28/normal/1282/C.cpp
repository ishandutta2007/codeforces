#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
const int  CONST = 998244353;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> m;
	while(m--)
	{
		int n, T, a, b;
		cin >> n >> T >> a >> b;
		vector <pair <int, int> > t(n);
		vector <int> type(n);
		int cnt1 = 0, cnt2 = 0;
		int ans = 0;
		int sumtime = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> type[i];
			if(type[i] == 0)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		for(int i = 0; i < n; i++)
		{
			cin >> t[i].first;
			t[i].second = i;
		}
		sort(t.begin(), t.end());
		int r = t[0].first - 1;
		if(a * cnt1 < r)
		{
			ans = max(ans, cnt1 + min((r - a * cnt1) / b, cnt2));
		}
		else
		{
			ans = max(ans, r / a);
		}
		for(int i = 0; i < n - 1; i++)
		{
			if(type[t[i].second] == 0)
			{
				sumtime += a;
				cnt1--;
			}
			else
			{
				sumtime += b;
				cnt2--;
			}
			if(sumtime < t[i + 1].first)
			{
				if(a * cnt1 + sumtime < t[i + 1].first)
				{
					ans = max(ans, cnt1 + i + 1 + min((t[i + 1].first - 1 - sumtime - cnt1 * a) / b, cnt2));
				}
				else
				{
					ans = max(ans, (t[i + 1].first - 1- sumtime) / a + i + 1);
				}
			}
		}
		if(type[t[n - 1].second] == 0)
		{
			sumtime += a;
			cnt1--;
		}
		else
		{
			sumtime += b;
			cnt2--;
		}
		if(sumtime <= T)
		{
			ans = max(ans, n);
		}
		cout << ans << "\n";
	}
	return 0;
}