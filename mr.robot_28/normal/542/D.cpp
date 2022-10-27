#include <bits/stdc++.h>
using namespace std;
#define int long long
long long A;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A;
	if(A == 1)
	{
		cout << 1;
		return 0;
	}
	vector <int> dels;
	dels.push_back(1);
	for(int i = 2; i * i <= A; i++)
	{
		if(A % i == 0)
		{
			dels.push_back(i);
			if(i * i != A)
			{
				dels.push_back(A / i);
			}
		}
	}
	dels.push_back(A);
	sort(dels.begin(), dels.end());
	vector <pair <int, int> > dels1;
	for(int i = 0; i < dels.size(); i++)
	{
		vector <pair <int, int> > mass;
		int a = dels[i] - 1;
		for(int j = 2; j * j <= dels[i] - 1; j++)
		{
			int c = 0;
			while(a % j == 0)
			{
				c++;
				a = a / j;
			}
			if(c != 0)
			{
				mass.push_back({j, c});
			}
		}
		if(a > 1)
		{
			mass.push_back({a, 1});
		}
		if(mass.size() == 1)
		{
			dels1.push_back({mass[0].first, dels[i]});
		}
	}
	sort(dels1.begin(), dels1.end());
	vector <vector <int> > dp(dels1.size() + 1, vector <int>(dels.size()));
	dp[0][0] = 1;
	int ans = 0;
	for(int i = 0; i < dels1.size(); i++)
	{
		int j= i;
		while(j < dels1.size() && dels1[j].first == dels1[i].first)
		{
			for(int k = 0; k < dels.size(); k++)
			{
				int k1 = lower_bound(dels.begin(), dels.end(), dels[k] * (dels1[j].second)) - dels.begin();
				if(k1 != dels.size() && dels[k1] == dels[k] * (dels1[j].second))
				{
					dp[j + 1][k1] += dp[i][k];
				}
				dp[j + 1][k] += dp[j][k];
			}
			j++;
		}
		i = j - 1;
	}
//	cout << dels.size() - 1 << "\n";
	cout << dp[dels1.size()][dels.size() - 1];
	return 0;
}