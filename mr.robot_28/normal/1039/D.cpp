#include<bits/stdc++.h>
 
using namespace std;
vector <vector <int> > g;
vector <int> res;
pair <int, int> dfs(int v, int k, int p = -1)
{
	int sum = 0;
	int mx1 = 0, mx2 = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			pair <int, int> a = dfs(to, k, v);
			sum += a.first;
			if(a.second > mx1)
			{
				mx2 = mx1;
				mx1 = a.second;
			}
			else if(a.second > mx2)
			{
				mx2 = a.second;
			}
		}
	}
	if(mx1 + mx2 + 1 >= k)
	{
		sum++;
		mx1 = 0;
	}
	else
	{
		mx1++;
	}
	return {sum, mx1};
}
void go_to(int a, int b, int left, int right)
{
	if(b < a)
	{
		return;
	}
	if(left == right)
	{
		for(int i = a; i <= b; i++)
		{
			res[i] = left;
		}
		return;
	}
	int m = (a + b) / 2;
	int val = dfs(0, m).first;
	res[m] = val;
	go_to(a, m - 1, val, right);
	go_to(m + 1, b, left, val);
}
signed main() {
	int n;
	cin >> n;
	res.resize(n + 1);
	g.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	go_to(1, n, 0, n);
	for(int i = 1; i <= n; i++)
	{
		cout << res[i] << "\n";
	}
    return 0;
}