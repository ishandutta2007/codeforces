#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e7 + 20;
const int mod = 1e9 + 7;
ll dp[maxn][2];
int main()
{
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i < maxn; i++)
    {
        dp[i][1] = ((2 * dp[i - 1][1]) % mod + dp[i - 1][0]) % mod;
        dp[i][0] = (3 * dp[i - 1][1]) % mod;
    }
    int n;
    cin >> n;
    cout << dp[n][0];
}