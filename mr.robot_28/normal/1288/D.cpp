#include<bits/stdc++.h>
using namespace std;
const int CONST = 1e9 + 7;
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > A(n, vector <int> (m));
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < m; j++)
    	{
    		cin >> A[i][j];
    	}
    }
    if(n == 1)
    {
    	cout << 1 << " " << 1 << "\n";
    	return 0;
    }
    int ans = 0;
    pair <int, int> t;
    t.first = t.second = 1;
    vector <pair <int, int> > maxmin((1 << m) ,{-1, -1});
    for(int i = 0; i < n; i++)
    {
    	vector <int> mask((1 << m), 1e9);
    	for(int j = 0; j < (1 << m); j++)
    	{
    		for(int k = 0; k < m; k++)
    		{
    			if(((1 << k) & j) != 0)
    			{
    				mask[j] = min(mask[j] ,A[i][k]);
    			}
    		}
    	}
    	for(int j = 0; j < (1 << m); j++)
    	{
    		if(maxmin[(1 << m) - 1 - j].first != -1)
    		{
    			int u = min(maxmin[(1 << m) - 1 - j].second, mask[j]);
    			if(u > ans)
    			{
    				ans = u;
    				t.first = i + 1;
    				t.second = maxmin[(1 << m) - 1 - j].first + 1;
    			}
    		}	
    	}
    	for(int j = 0; j < (1 << m); j++)
    	{
    		if(maxmin[j].first == -1 || maxmin[j].second < mask[j])
    		{
    			maxmin[j].second = mask[j];
    			maxmin[j].first = i;
    		}
    	}
    }
    cout << t.first << " "<< t.second << "\n";
    return 0;
}