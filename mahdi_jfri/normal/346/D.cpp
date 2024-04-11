#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

vector<int> adj[maxn];

int t[maxn] , d[maxn];

bool visited[maxn];

deque<int> dq;

int main()
{
	memset(d , 63 , sizeof d);
	int n , m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;
		adj[b].pb(a);
		t[a]++;
	}
	int s , t1;
	scanf("%d%d", &s, &t1);
	s-- , t1--;
	d[t1] = 0;
	dq.pb(t1);
	while(!dq.empty())
	{
		int v = dq.front();
		dq.pop_front();
		if(visited[v])
			continue;
		visited[v] = 1;
		for(auto u : adj[v])
		{
			t[u]--;
			if(t[u] == 0 && d[u] > d[v])
			{
				d[u] = d[v];
				dq.push_front(u);
			}
			if(t[u] > 0 && d[u] > d[v] + 1)
			{
				d[u] = d[v] + 1;
				dq.push_back(u);
			}
		}
	}
	if(d[s] > maxn)
		d[s] = -1;
	cout << d[s] << endl;
}