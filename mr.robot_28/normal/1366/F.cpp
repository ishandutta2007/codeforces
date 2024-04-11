#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t= power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
double point(pair <int, int> a, pair <int, int> b)
{
	double dk = a.first - b.first;
	double db = b.second - a.second;
	return db / dk;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector <vector <pair <int, int> > > g(n);
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	vector <vector <int> > dp(n, vector <int> (m + 1, -1e18));
	dp[0][0] = 0;
	for(int j = 1; j <= m; j++)
	{
		for(int i = 0; i < n; i++){
			for(int it = 0; it < g[i].size(); it++)
			{
				int to = g[i][it].first;
				int w = g[i][it].second;
				dp[i][j] = max(dp[i][j], dp[to][j - 1] + w);
			}
		}
	}
	vector <int> ans(m + 1, 0);
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < n; j++)
		{
			ans[i] = max(ans[i], dp[j][i]);
		}
	}
	if(q <= m){
		int sum = 0;
		for(int i = 1; i <= q; i++){
			sum = (sum + ans[i]) % const1;
		}
		cout << sum;
		return 0;
	}
	int sum = 0;
	for(int i = 1; i <= m; i++)
	{
		sum = (sum + ans[i]) % const1;
	}
	vector <pair <int, int> > vec;
	vector <pair <int, int> > st;
	for(int i = 0; i < n; i++)
	{
		int maxv = 0;
		for(int j = 0; j < g[i].size(); j++)
		{
			int w = g[i][j].second;
			maxv = max(maxv, w);
		}
		vec.push_back({maxv, dp[i][m] - m * maxv});
	}
	sort(vec.begin(),vec.end());
	for(int i = 0; i < vec.size(); i++)
	{
		while(st.size() > 0 && st.back().first == vec[i].first)
		{
			st.pop_back();
		}
		while(st.size() > 1 && point(st[st.size() - 2], st[st.size() - 1]) >= point(st[st.size() - 2], vec[i]))
		{
			st.pop_back();
		}
		st.push_back(vec[i]);
	}
	int two = power(2, const1 - 2);
	for(int i = 0; i < st.size(); i++)
	{
		if(i == st.size() - 1 || point(st[i], st[i + 1]) > m)
		{
			if(i == 0 || point(st[i], st[i - 1]) < q)
			{
				int mint = m + 1;
				if(i != 0)
				{
					int e =floor(point(st[i], st[i - 1])) + 1;
					mint = max(mint, e);
				}
				int maxt = q;
				if(mint > maxt)
				{
					continue;
				}
				if(i != st.size() -1 ){
					int e = floor(point(st[i], st[i + 1]));
					maxt = min(maxt, e);
				}
				int minval = st[i].first * mint+ st[i].second;
				int maxval = st[i].first * maxt+ st[i].second;
				int sumval = (minval + maxval) % const1;
				sum += sumval * (maxt - mint + 1) % const1 * two % const1;
				if(sum >= const1)
				{
					sum -= const1;
				}
			}
		}
	}
	cout << sum;
    return 0;
}