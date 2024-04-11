#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
vector <vector <int> > g;
vector <bool> dp;
vector <vector <int> > cycle;
vector <int> pred;
vector <int> used, p;
void dfs(int v)
{
	used[v] = 1;
	for(int j = 0; j < g[v].size(); j++)
	{
		int to = g[v][j];
		if(used[to] == 1)
		{
			stack <int> vec;
			int st = v;
			int mask = 0;
			bool flag = true;
			while(st != to)
			{
				vec.push(st);
				if((1 << (st / 5000)) & mask)
				{
					flag = false;
				}
				mask |= (1 << (st / 5000));
				st = p[st];
			}
			vec.push(st);
			if((1 << (st / 5000)) & mask)
			{
				flag = false;
			}
			if(!flag)
			{
				continue;
			}
			mask |= (1 << (st / 5000));
			dp[mask] = true;
			cycle[mask].clear();
			while(vec.size() > 0)
			{
				cycle[mask].push_back(vec.top());
				vec.pop();
			}
		}
		else if(used[to] == 0)
		{
			p[to] = v;
			dfs(to);
		}
	}
	used[v] = 2;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	p.resize(5000 * k);
	pred.resize((1 << k), -1);
	dp.resize((1 << k), false);
	cycle.resize(1 << k);
	g.resize(5000 * k);
	used.resize(5000 * k);
	vector <vector <int> > mass(k);
	int sum = 0;
	vector <int> localsum(k);
	for(int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		mass[i].resize(n);
		for(int j = 0; j < n; j++)
		{
			cin >> mass[i][j];
			sum += mass[i][j];
			localsum[i] += mass[i][j];
		}
		sort(mass[i].begin(), mass[i].end());
	}
	if(sum % k != 0)
	{
		cout << "No";
		return 0;
	}
	sum /= k;
	vector <int> iter(k);
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < k; j++)
		{
			iter[j] = 0;
		}
		for(int j = 0; j < mass[i].size(); j++)
		{
			for(int w = 0; w < k; w++)
			{
				if(w == i)
				{
					continue;
				}
				while(iter[w] < mass[w].size() && mass[w][iter[w]]  + sum - localsum[w] < mass[i][j])
				{
					iter[w]++;
				}
				if(iter[w] < mass[w].size() && mass[w][iter[w]]  + sum - localsum[w] == mass[i][j])
				{
					g[i * 5000 + j].push_back(w * 5000 + iter[w]);
				}
			}
		}
	}
	for(int i = 0; i < 5000 * k; i++)
	{
		if(!used[i])
		{
			dfs(i);
		}
	}
	for(int j = 0; j < k; j++)
	{
		if(localsum[j] != sum)
		{
			continue;
		}
		cycle[(1 << j)].clear();
		cycle[(1 << j)].push_back(j * 5000);
		dp[(1 << j)] = true;
	}
	for(int i = 1; i < (1 << k); i++)
	{
		for(int mask1 = i; mask1 > 0; mask1 = (mask1 - 1) & i)
		{
			if((mask1 ^ i) != 0 && dp[mask1] && dp[mask1 ^ i])
			{
				dp[i] = true;
				pred[i] = mask1;
				break;
			}
		}
	}
	if(!dp[(1 << k) - 1])
	{
		cout << "No";
		return 0;
	}
	int v = (1 << k) - 1;
	queue <int> q;
	q.push(v);
	cout << "Yes\n";
	vector <pair <int, int> > ans(k);
	while(q.size() > 0)
	{
		v = q.front();
		q.pop();
		if(pred[v] == -1)
		{
			for(int j = 0; j < cycle[v].size(); j++)
			{
				ans[cycle[v][j] / 5000] = {cycle[v][j] % 5000, cycle[v][(j + 1) % cycle[v].size()] / 5000};
			}
		}
		else
		{
			q.push(pred[v]);
			q.push(v ^ pred[v]);
		}
	}
	for(int i = 0; i < k; i++)
	{
		ans[i].first = mass[i][ans[i].first];
		ans[i].second++;
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}