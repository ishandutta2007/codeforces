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
    	vector <vector <int> > g(n);
    	vector <bool> used(n);
    	int a = -1;
    	for(int i = 0;  i < n; i++)
    	{
    		int k;
    		cin >> k;
    		g[i].resize(k);
    		for(int j = 0; j < k; j++)
    		{
    			cin >> g[i][j];
    			g[i][j]--;
    		}
    		bool flag = false;
    		for(int j = 0; j < k; j++)
    		{
    			if(used[g[i][j]])
    			{
    				continue;
    			}
    			flag = true;
    			used[g[i][j]] = true;
    			break;
    		}
    		if(!flag)
    		{
    			a = i;
    		}
    	}
    	if(a == -1)
    	{
    		cout << "OPTIMAL\n";
    		continue;
    	}
    	cout << "IMPROVE\n";
    	cout << a + 1 << " ";
    	for(int i = 0; i < n; i++)
    	{
    		if(!used[i])
    		{
    			cout << i + 1;
    			break;
    		}
    	}
    	cout << "\n";
    }
    return 0;
}