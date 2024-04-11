#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
#define int long long
vector <vector <pair <int, int> > > A;
vector <bool> used;
vector <int> cost;
vector <int> Max, imax, max1, max2;
int M = 0;
void dfs(int v)
{
	used[v] = true;
	for(int i = 0; i < A[v].size(); i++)
	{
		int to = A[v][i].first, s = A[v][i].second;
		if(!used[to])
		{
			dfs(to);
			if(Max[to] - s + cost[to] > Max[v])
			{
				imax[v] = to;
				max1[v] = Max[v];
			}
			Max[v] = max(Max[to] - s + cost[to], Max[v]);
		}
	}
	if(Max[v] + cost[v] > M)
	{
		M = Max[v] + cost[v];
	}
}
void dfs1(int v)
{
	used[v] = true;
	if(max2[v] > M)
	{
		M = max2[v];
	}
	for(int i = 0; i < A[v].size(); i++)
	{
		int to = A[v][i].first, s = A[v][i].second;
		if(!used[to])
		{
			if(max2[v] > s)
			{
				max2[to] = max(max2[v] - s + cost[to], max2[to]);
			}
			if(to == imax[v])
			{
				if(max1[v] + cost[v] > s)
				{
					max2[to] = max(max2[to], max1[v] + cost[v] - s + cost[to]);
				}
			}
			else
			{
				if(Max[v] + cost[v] > s)
				{
					max2[to] = max(Max[v] + cost[v] - s + cost[to], max2[to]);
				}
			}
			dfs1(to);
		}
	}
}
signed main() {
	int n;
	cin >> n;
	used.resize(n);
	A.resize(n);
	cost.resize(n);
	Max.resize(n, 0);
	max1.resize(n, 0);
	max2.resize(n, 0);
	imax.resize(n);
	for(int i = 0; i < n; i++)
	{
		imax[i] = i;
		cin >> cost[i];
	}
	for(int i = 0; i < n - 1; i++)
	{
		int v, u, s;
		cin >> v >> u >> s;
		v--;
		u--;
		A[v].push_back({u, s});
		A[u].push_back({v, s});
	}
	dfs(0);
	for(int i = 0; i < n; i++)
	{
		used[i] = false;
	}
	max2[0] = cost[0];
	dfs1(0);
	cout << M;
	return 0;
}