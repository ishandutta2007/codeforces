#include<bits/stdc++.h>
using namespace std;
vector <bool> used;
vector <vector <int> > g;
void dfs(int v)
{
	used[v] = true;
	for(int i= 0; i < g[v].size(); i++)
	{
		if(!used[g[v][i]])
		{
			dfs(g[v][i]);
		}
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	used.resize(n, false);
	vector <pair <int, int> > A(k);
	g.resize(n);
	for(int i = 0; i < k; i++)
	{
		cin >> A[i].first >> A[i].second;
		g[A[i].first - 1].push_back(A[i].second - 1);
		g[A[i].second - 1].push_back(A[i].first - 1);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			dfs(i);
			cnt++;
		}
	}
	cout << k - n + cnt;
    return 0;
}