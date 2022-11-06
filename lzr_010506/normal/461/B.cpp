#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, col[100010];
vector<int> a[100010];
long long dp[100010][2];
void dfs(int now)
{
    dp[now][0] = 1;
    dp[now][1] = 0;
    for(int i = 0; i < a[now].size(); i ++)
    {
        int to=a[now][i];
        dfs(to);
        dp[now][1] = (dp[now][1] * dp[to][0] + dp[now][0] * dp[to][1]) % mod;
        dp[now][0] = dp[now][0] * dp[to][0] % mod;
    }
    if(col[now] == 1) dp[now][1] = dp[now][0];
    else dp[now][0] = (dp[now][0] + dp[now][1]) % mod;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i ++)
    {
        int x;
        scanf("%d", &x);
        a[x].push_back(i);
    }
    for(int i = 0; i < n; i ++)
	    scanf("%d", &col[i]);
    dfs(0);
    cout << dp[0][1] << endl;
    return 0;
}