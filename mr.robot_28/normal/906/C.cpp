#include<bits/stdc++.h>
 
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	vector <int> dp(1 << n, 1e9);
	vector <pair <int, int> > pred(1 << n);
	vector <int> mask1(n, 0);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		mask1[a] |= (1 << b);
		mask1[b] |= (1 << a);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dp[0] = 0;
	for(int i = 0; i < n; i++)
	{
		dp[(1 << i)] = 0;
	}
	for(int i = 1; i < (1 << n); i++)
	{
		if(dp[i] == 1e9){
			continue;
		}
		for(int j = 0; j < n; j++)
		{
			if(((1 << j) & i) == 0)
			{
				if((i & mask1[j]) == i)
				{
					dp[i | (1 << j)] = 0;
				}
			}
		}
	}
	for(int mask = 1; mask < (1 << n); mask++)
	{
		for(int j = 0; j < n; j++)
		{
			if((1 << j) & mask)
			{
				int maskto = mask1[j] | mask;
				if(dp[maskto] > dp[mask] + 1)
				{
					dp[maskto] = dp[mask] + 1;
					pred[maskto] = {mask, j};
				}
			}
		}
	}
	if(dp[(1 << n) - 1] == 1e9)
	{
		cout << "A";
		return 0;
	}
	cout << dp[(1 << n) - 1] << "\n";
	int stmask = (1 << n) - 1;
	vector <int> vec;
	while(pred[stmask].first != 0)
	{
		vec.push_back(pred[stmask].second + 1);
		stmask = pred[stmask].first;
	}
	for(int i = vec.size() - 1; i >= 0; i--)
	{
		cout << vec[i] << " ";
	}
	return 0;
}