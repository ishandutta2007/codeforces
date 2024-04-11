#include<bits/stdc++.h>
 
using namespace std;
#define int long long
int n;
vector <int> t, h;
vector <vector <int> > g;
vector <int> in, out, dp, dp1;
vector <bool> used;
int mass[200001];
void dfs(int v, int p = -1)
{
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v);
		}
	}
	int s = 0;
	int sum = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			mass[++s] = dp[to] - dp1[to];
			sum += dp1[to];
		}
	}
	sort(mass + 1, mass + s + 1);
	reverse(mass + 1, mass + s + 1);
	for(int i = 0; i <= s; i++)
	{
		sum += mass[i];
		if(p != -1)
		{
			dp[v] = max(dp[v], 1LL * min(in[v] + 1 + s - i, out[v] + i) * t[v] + sum);
			dp1[v] = max(dp1[v], 1LL * min(in[v] + s - i, out[v] + i + 1) * t[v] + sum);
		}
		else
		{
			dp[v] = max(dp[v], 1LL * min(in[v] + s - i, out[v] + i) * t[v] + sum);
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	t.resize(n);
	g.resize(n);
	h.resize(n);
	in.resize(n);
	out.resize(n);
	dp.resize(n);
	dp1.resize(n);
	used.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	int sum = 0;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		sum += t[a] + t[b];
		if(h[a] == h[b])
		{
			g[a].push_back(b);
			g[b].push_back(a);
		}
		else
		{
			if(h[a] > h[b])
			{
				swap(a, b);
			}
			in[a]++;
			out[b]++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			dfs(i);
			sum -= dp[i];
		}
	}
	cout << sum;
	return 0;
}