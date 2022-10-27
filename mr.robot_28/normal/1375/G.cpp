#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
int cnt1 = 0, cnt2 = 0;
vector <int> h;
void dfs(int v, int p = -1)
{
	if(h[v] % 2 == 0)
	{
		cnt1++;
	}
	else
	{
		cnt2++;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			h[to] = h[v] + 1;
			dfs(to, v);
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    h.resize(n, 0);
    g.resize(n);
    for(int i = 0; i < n- 1; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    dfs(0);
    cout << min(cnt1 - 1, cnt2 - 1);
	return 0;
}