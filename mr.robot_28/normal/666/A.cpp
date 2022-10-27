#include<bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    set <string> st;
    int n = s.size();
    vector <vector <bool> > dp(n, vector <bool> (4));
    for(int i = n - 2; i >= 5; i--)
    {
    	for(int j = 2; j <= 3; j++)
    	{
    		if(j + i == n)
    		{
    			dp[i][j] = true;
    			if(j == 2)
    			{
    				string s1 = "";
    				s1 += s[i];
					s1 += s[i + 1];
    				st.insert(s1);
    			}
    			else
    			{
    				string s1 = "";
    				s1 += s[i];
    				s1 += s[i + 1];
    				s1 += s[i + 2];
    				st.insert(s1);
    			}
    			continue;
    		}
    		if(j + i > n)
    		{
    			continue;
    		}
    		bool flag = false;
    		for(int j1 = 2; j1 <= 3; j1++)
    		{
    			if(i + j + j1 > n || !dp[i + j][j1])
    			{
    				continue;
    			}
    			if(j != j1){
    				flag = true;
    			}
    			for(int k = 0; k < j1; k++)
    			{
    				if(s[i + k] != s[i + j + k])
					{
						flag = true;
					}
    			}
    		}
    		dp[i][j] = flag;
    		if(dp[i][j])
    		{
    			if(j == 2)
    			{
    				string s1 = "";
    				s1 += s[i];
					s1 += s[i + 1];
    				st.insert(s1);
    			}
    			else
    			{
    				string s1 = "";
    				s1 += s[i];
    				s1 += s[i + 1];
    				s1 += s[i + 2];
    				st.insert(s1);
    			}
    		}
    	}
    }
    cout << st.size() << "\n";
    set <string> :: iterator it;
    for(it = st.begin(); it != st.end(); it++)
    {
    	cout << *it << "\n";
    }
	return 0;
}