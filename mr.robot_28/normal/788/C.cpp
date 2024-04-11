#include <bits/stdc++.h>
                  
using namespace std;
int ans = 1e9;
vector <vector <int> > g(2001);
vector <int> h(2001);
vector <bool> used(2001);
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <bool> used1(2001);
	for(int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		a = a - n;
		if(used1[a + 1000])
		{
			continue;
		}
		used1[a + 1000] = true;
		for(int j = 0; j <= 2000; j++)
		{
			if(j + a >= 0 && j + a <= 2000)
			{
				g[j].push_back(j + a);
			}
		}
	}
	queue <int> q;
	q.push(1000);
	used[1000] = true;
	while(q.size() != 0)
	{
		int v = q.front();
		q.pop();
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if(!used[to])
			{
				h[to] = h[v] + 1;
				used[to] = true;
				q.push(to);
			}
			if(to == 1000)
			{
				cout << h[v] + 1;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}