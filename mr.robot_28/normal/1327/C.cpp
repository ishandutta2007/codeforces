#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector <pair <int, int> > s(k), f(k);
    int left = 0, right = 0, up = 0, down = 0;
    for(int i = 0; i < k; i++)
    {
    	cin >> s[i].first >> s[i].second;
    	left =max(left, s[i].second - 1);
    	up = max(up, s[i].first - 1);
    }
    bool flag = true;
    for(int i = 0; i < k; i++)
    {
    	cin >> f[i].first >> f[i].second;
    }
    string ans  = "";
    while(left > 0)
    {
    	ans += "L";
    	left--;
    	right++;
    }
    while(up > 0)
    {
     	ans += "U";
    	up--;
    	down++;
    }
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < m - 1; j++)
    	{
    		if(i % 2 == 0)
    		{
    			ans += "R";
    		}
    		else
    		{
    			ans += "L";
    		}
    	}
    	if(i != n - 1)
    	{
    		ans += "D";
    	}
    }
    cout << ans.size() << "\n";
    cout << ans;
    return 0;
}