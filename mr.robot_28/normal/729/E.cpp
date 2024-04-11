#include <bits/stdc++.h>

using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	s--;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int t = 0;
	if(a[s] != 0)
	{
		a[s] = 0;
		t++;
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	int it = 0;
	vector <bool> used(n, 0);
	int ans = 1e9;
	int cnt1 = 0;
	for(int h = 0; h < n; h++)
	{
		cnt++;
		while(it < n && a[it] <= h)
		{
			if(!used[a[it]])
			{
				cnt--;
				used[a[it]] = 1;
			}
			else if(a[it] == 0)
			{
				cnt1++;
			}
			it++;
		}
		if(h != 0 || cnt1 == 0)
		{
		ans = min(ans, max(cnt1 + n - it, cnt));	
		}
	}
	cout << ans + t;
	return 0;
}