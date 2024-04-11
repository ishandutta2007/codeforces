#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		int cnta = 0, cntb = 0;
		vector <pair <int, int> > mass;
		for(int i = 0; i< n; i++)
		{
			int j= i;
			while(j < n && s[j] == s[i])
			{
				j++;
			}
			mass.push_back({j - i, s[i] - 'A'});
			i = j - 1;
		}
		int ans = n;
		int cnt = 0;
		for(int i = mass.size() - 1; i >= 0; i--)
		{
			if(mass[i].second == 0)
			{
				ans -= 2 * min(cnt, mass[i].first);
				cnt -= min(cnt, mass[i].first);
			}
			else
			{
				cnt += mass[i].first;
			}
		}
		ans -= cnt - (cnt % 2);
		cout << ans << "\n";
	}
	return 0;
}