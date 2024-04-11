#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 1050;
int cnk[maxn][maxn];
const int mod = 1e9 + 7;
int dp[maxn];
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int m, n;
    cin >> m >> n;
    cnk[0][0] = 1;
    for(int i = 1; i < maxn; i++)
    {
        cnk[i][0] = 1;
        for(int j = 1; j <= i; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                cnk[i][j] += cnk[i - 1][j - k];
                cnk[i][j] %= mod;
            }
        }
    }
    dp[0] = 1;
    for(int i = 1; i <maxn; i++)
    {
        for(int j = 0; j < i; j++)
        {
        dp[i] += cnk[i - 1][j] * dp[i - j - 1] % mod;
        dp[i] %= mod;
        }
    }
    vector <int> mass;
    for(int i = 0; i < m; i++)
    {
        mass.push_back(i);
    }
    vector <vector <int> > united;
    united.push_back(mass);
    vector <string> s(n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        vector <vector <int> > united1;
        for(int j = 0; j < united.size(); j++)
        {
            vector <int> go_to[2];
            for(int u = 0; u < united[j].size(); u++)
            {
                int ind = united[j][u];
                go_to[s[i][ind]- '0'].push_back(ind);
            }
            if(go_to[0].size())
            {
                united1.push_back(go_to[0]);
            }
            if(go_to[1].size())
            {
                united1.push_back(go_to[1]);
            }
        }
        united = united1;
    }
    int ans = 1;
    for(int i = 0; i < united.size(); i++)
    {
 //       cout << united[i].size() << " ";
        ans = ans * dp[united[i].size()] % mod;
    }
    cout << ans;
	return 0;
}