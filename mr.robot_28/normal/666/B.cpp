#include<bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > g(n);
    vector <vector <int> > g1(n);
    vector <vector <int> > dist(n, vector <int> (n, 1e9)), dist1(n, vector <int> (n, 1e9));  
    for(int i = 0; i < m; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g1[b].push_back(a);
    }
    vector <vector <int> > mass(n), mass1(n);
    for(int i = 0; i < n; i++)
    {
    	dist[i][i] = 0;
    	queue <int> q;
    	q.push(i);
    	while(q.size() != 0)
    	{
    		int v = q.front();
    		q.pop();
    		mass[i].push_back(v);
    		for(int j = 0; j < g[v].size(); j++)
    		{
    			int to = g[v][j];
    			if(dist[i][to] == 1e9)
    			{
    				dist[i][to] = dist[i][v] + 1;
    				q.push(to);
    			}
    		}
    	}
    }
	for(int i = 0; i < n; i++)
    {
    	dist1[i][i] = 0;
    	queue <int> q;
    	q.push(i);
    	while(q.size() != 0)
    	{
    		int v = q.front();
    		q.pop();
    		mass1[i].push_back(v);
    		for(int j = 0; j < g1[v].size(); j++)
    		{
    			int to = g1[v][j];
    			if(dist1[i][to] == 1e9)
    			{
    				dist1[i][to] = dist1[i][v] + 1;
    				q.push(to);
    			}
    		}
    	}
    }
    vector <int> massans(4);
    int ans = 0;
    for(int a = 0; a < n; a++)
    {
    	for(int b = 0; b < n; b++)
    	{
    		if(dist[a][b] == 1e9 || a == b)
    		{
    			continue;
    		}
    		for(int i = 1; i <= min((int)mass1[a].size(), 4); i++)
    		{
    			for(int j = 1; j <= min((int)mass[b].size(), 4); j++)
    			{
    				int c = mass1[a][mass1[a].size() - i];
    				int d = mass[b][mass[b].size() - j];
    				if(c == a || c == b || c == d ||
					d == a || d == b || d == b)
					{
						continue;
					}
					int sum = 0;
					sum = dist[c][a] + dist[a][b] + dist[b][d];
					if(sum > ans)
					{
						ans = sum;
						massans[0] = c;
						massans[1] = a;
						massans[2] = b;
						massans[3] = d;
					}
    			}
    		}
    	}
    }
    for(int i = 0; i < 4; i++)
    {
    	cout << massans[i] + 1 << " ";
    }
	return 0;
}