#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
vector <vector <int> > g1, g;
vector <int> h;
vector <int> used1;
int p, k;
int power(int a, int b)
{
	if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % p;
	}
	else if(b == 1)
	{
		return a;
	}
	else
	{
		return a * power(a, b - 1) % p;
	}
}
int power1(int a, int b){
	if(b == 1)
	{
		return a;
	}
	else if(b % 2 == 0)
	{
		int t= power1(a, b / 2);
		return t * t % mod;
	}
	else
	{
		return a * power1(a, b - 1) % mod;
	}
}
vector <bool> used;
void go_to(int i)
{
	if(!used[i])
		{
			queue <int> q;
			q.push(i);
			used[i] = 1;
			while(q.size() != 0)
			{
				int v = q.front();
				q.pop();
				for(int j = 0; j < g[v].size(); j++)
				{
					int to = g[v][j];
					if(!used[to])
					{
						q.push(to);
						used[to] = 1;
					}
				}
			}
		}
}
void dfs(int v, int p = -1)
{
	used1[v] = 1;
	for(int i = 0; i < g1[v].size(); i++)
	{
		int to = g1[v][i];
		if(used1[to] == 1)
		{
			if(power(k, -h[to] + h[v] + 1) != 1)
			{
				go_to(v);
			}
		}
		else if(used1[to] == 0)
		{
			h[to] = h[v] + 1;
			dfs(to, v);
		}
	}
	used1[v] = 2;
}
signed main()
{
	cin >> p >> k;
	if(k == 0)
	{
		cout << power1(p, p - 1);
		return 0;
	}
	used1.resize(p);
	g1.resize(p);
	used.resize(p);
	h.resize(p);
	g.resize(p);
	for(int i = 0; i < p; i++)
	{
		int to = (1LL * i * k) % p;
		g[i].push_back(to);
		g[to].push_back(i);
		g1[i].push_back(to);
	}
	for(int i = 1; i < p; i++)
	{
		if(!used1[i])
		{
			dfs(i);
		}
	}
	int pr = 1;
	for(int i = 1; i < p; i++)
	{
		if(!used[i])
		{
			queue <int> q;
			q.push(i);
			used[i] = 1;
			while(q.size() != 0)
			{
				int v = q.front();
				q.pop();
				for(int j = 0; j < g[v].size(); j++)
				{
					int to = g[v][j];
					if(!used[to])
					{
						q.push(to);
						used[to] = 1;
					}
				}
			}
			pr = 1LL * pr * p % mod;
		}
	}
	if(k == 1)
	{
		pr = pr * p % mod;
	}
	cout << pr;
	return 0;
}