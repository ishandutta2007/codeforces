#include<bits/stdc++.h>
using namespace std;

signed main() {	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	int t;
  	cin >> t;
  	while(t--)
  	{
  		int n;
  		cin >> n;
  		vector <int> p(n);
  		for(int i = 0; i < n; i++)
  		{
  			cin >> p[i];
  			p[i]--;
  		}
  		vector <int> c(n);
  		for(int i = 0; i < n; i++)
  		{
  			cin >> c[i];
  		}
  		vector <bool> used(n, false);
  		int ans = 1e9;
  		for(int i = 0; i < n; i++)
  		{
  			if(used[i])
  			{
  				continue;
  			}
  			vector <int> cycle;
  			int v = i;
  			while(!used[v])
  			{
  				used[v] = true;
  				cycle.push_back(v);
  				v = p[v];
  			}
  			int m = cycle.size();
  			for(int j = 1; j <= m; j++)
  			{
  				if(m % j != 0)
  				{
  					continue;
  				}
  				for(int s = 0; s < j; s++)
  				{
  					bool flag = true;
  					for(int pos = s; pos + j < m; pos += j)
  					{
  						if(c[cycle[pos]] != c[cycle[pos + j]])
  						{
  						 	flag = false;
  						}
  					}
	  				if(flag)
  					{
  						ans = min(ans, j);
  						break;
  					}
  				}
  			}
  		}
  		cout << ans << "\n";
  	}
    return 0;
}