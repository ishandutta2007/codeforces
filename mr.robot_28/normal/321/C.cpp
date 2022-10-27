#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> sz;
vector <int> used;
vector <int> ans;
void calc_sz(int v, int pr)
{
	sz[v] = 1;
	used[v]++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(!ans[to] && to != pr)
		{
			calc_sz(to, v);
		sz[v] += sz[to];
		}
	}
}
int centroid(int v, int t)
{
	int siz = sz[v];
	int pr = -1;
	bool run = true;
	while(run){
		run = false;
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if(to != pr && !ans[to] && sz[to] >= siz / 2)
			{
				run =true;
				pr = v;
				v = to;
				break;
			}
		}
	}
	return v;
}
void solve(int v, int t)
{
	calc_sz(v, -1);
	v = centroid(v, t);
	ans[v] = t;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(!ans[to])
		{
			solve(to, t + 1);
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    g.resize(n);
    used.resize(n);
    ans.resize(n);
    sz.resize(n);
    
    for(int i = 0; i < n - 1; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    solve(0, 1);
    for(int i = 0; i < n; i++)
    {
    	int cur = ans[i] - 1;
    	char t = cur + 'A';
    	cout << t << " ";
    }
    return 0;
}