#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> s(n);
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	n = unique(s.begin(), s.end()) - s.begin();
	vector <pair <int, int> > index;
	for(int i = 0; i < n; i++)
	{
		if(i == n - 1)
		{
			index.push_back({2e18, i});
		}
		else
		{
			index.push_back({s[i + 1] - s[i], i});
		}
	}
	sort(index.begin(), index.end());
	vector <int> pref(n);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			pref[i] = index[i].first;
		}
		else
		{
			pref[i] = index[i].first + pref[i - 1];
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		int l1 = -1, r1 = n;
		while(r1 - l1 > 1)
		{
			int midd = (r1 + l1) / 2;
			if(index[midd].first <= r - l)
			{
				l1 = midd;
			}
			else
			{
				r1 = midd;
			}
		}
//		cout << l1 << " ";
		int sum = n * (r - l + 1);
//		cout << sum << " ";
		if(l1 != -1)
		{
			sum += (pref[l1] - (l1 + 1) * (r - l + 1));
		}
		cout << sum << " ";
	}
	return 0;
}