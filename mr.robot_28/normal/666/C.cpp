#include<bits/stdc++.h>
using namespace std;
const int const1 = 1e9 + 7;
vector <int> fact(1e5 + 1), fact1(1e5 + 1);
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return 1LL * t * t % const1;
	}
	int t = power(a, b / 2);
	t = 1LL * t * t % const1;
	return 1LL * t * a % const1;
}
int cnk(int a, int b){
	return 1LL * fact[a] * fact1[a - b] % const1 * fact1[b] % const1;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    int m;
    cin >> m;
    string s;
    cin >> s;
    fact[0] = 1;
    for(int i = 1; i <= 1e5; i++)
    {
    	fact[i] = 1LL * fact[i - 1] * i % const1;
    }
    fact1[1e5] = power(fact[1e5], const1 - 2);
    for(int i = 1e5 - 1; i >= 0; i--)
    {
    	fact1[i] = 1LL * fact1[i + 1] * (i + 1) % const1;
    }
    int n = s.size();
    map <int, int> mp;
    mp[n] = 0;
    int t = sqrt(2e5) + 3;
    int q = 26;
    int dp[t][100001];
    vector <int> st1(1e5 + 1), st2(1e5 + 1);
    st1[0] = 1;
    st2[0] = 1;
    for(int i = 1; i <= 1e5; i++)
    {
    	st1[i] = 1LL * st1[i - 1] * q % const1;
    	st2[i] = 1LL * st2[i - 1] * (q - 1) % const1;
    }
    for(int i = n; i <= 1e5; i++)
    {
    	dp[0][i] = 1LL * dp[0][i - 1] * q % const1;
    	dp[0][i] += 1LL * cnk(i - 1, n - 1) * st2[i - n] % const1;
    	if(dp[0][i] >= const1)
    	{
    		dp[0][i] -= const1;
    	}
    }
    int it = 0;
    while(m--)
    {
    	int type;
    	cin >> type;
    	if(type == 1)
    	{
    		string s;
    		cin >> s;
    		n = s.size();
    		if(mp.count(n))
    		{
    			continue;
    		}
    		it++;
    		mp[n] = it;
    		for(int i = n; i <= 1e5; i++)
    		{
    			dp[it][i] = 1LL * dp[it][i - 1] * q % const1;
    			dp[it][i] += 1LL * cnk(i - 1, n - 1) * st2[i - n] % const1;
    			if(dp[it][i] >= const1)
    			{
    				dp[it][i] -= const1;
    			}
    		}
    	}
    	else
    	{
    		int n1;
    		cin >> n1;
    		cout << dp[mp[n]][n1] << "\n";
    	}
    }
	return 0;
}