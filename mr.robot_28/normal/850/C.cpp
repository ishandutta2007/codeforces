#include <bits/stdc++.h>
using namespace std;
vector <set <int> > mass(40);
vector <int> val(40);
bool found(int x, int l, int r)
{
	set <int> :: iterator it;
	it = mass[x].lower_bound(l);
	if(it != mass[x].end() && *it <= r)
	{
		return true;
	}
	return false;
}
map <int, int> dp;
int calc(int mask)
{
	if(mask == 0)
	{
		return 0;
	}
	if(dp[mask])
	{
		return dp[mask];
	}
	int t = 32-__builtin_clz(mask);
	int rmask = 0;
	vector <int> p;
	for(int k1 = 1; k1 <= t; k1++)
	{
		int go_to_mask = rmask | (mask >> k1);
		p.push_back(calc(go_to_mask));
		rmask |= ((1 << (k1 - 1)) & mask);
	}
	sort(p.begin(), p.end());
	if(0 < p[0])
	{
		return dp[mask] = 0;
	}
	for(int j = 0; j < p.size() - 1; j++)
	{
		if(p[j] + 1 < p[j + 1])
		{
			return dp[mask] = p[j] + 1;
		}
	}
	return dp[mask] = p[p.size() - 1] + 1;
}
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	int ans = 0;
	vector <pair <int, int> > allmass;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		int t = a[i];
		for(int j = 2; j * j <= a[i]; j++)
		{
			int cnt = 0;
			while(t % j == 0)
			{
				cnt++;
				t = t / j;
			}
			if(cnt != 0)
			{
				allmass.push_back({j, cnt});
			}
		}
		if(t != 1)
		{
			allmass.push_back({t, 1});
		}
	}
	sort(allmass.begin(), allmass.end());
 	int m = unique(allmass.begin(), allmass.end()) - allmass.begin();
	for(int i = 0; i < m; i++)
	{
		int j = i;
		int mask1 = 0;
		while(j < m && allmass[i].first == allmass[j].first)
		{
			mask1 |= (1 << (allmass[j].second - 1));
			j++;
		}
		ans ^= calc(mask1);
		i = j - 1;
	}
	if(ans)
	{
		cout << "Mojtaba";
	}
	else
	{
		cout << "Arpa";
	}
	return 0; 
}