#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e2;
const ll inf = 1e15;
ll dp[maxn][maxn * maxn] , pd[maxn][maxn * maxn] , a[maxn];
int main()
{
    int n , k , s;
    cin >> n >> k >> s;
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn * maxn; j++)
            dp[i][j] = inf;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    s = min(s , n * (n - 1));
    for(int z = 0; z <= s; z++)
        pd[1][z] = dp[1][z] = a[0];
    for(int z = 0; z <= s; z++)
        pd[0][z] = dp[0][z] = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i + 1; j++)
        {
            for(int z = 0; z <= s; z++)
            {
                if(!j)
                {
                    dp[j][z] = 0;
                    continue;
                }
                if(z < (i - j + 1))
                    dp[j][z] = dp[j][z];
                else
                    dp[j][z] = min(dp[j][z] , pd[j - 1][z - (i - j + 1)] + a[i]);
            }
        }
        for(int j = 0; j < maxn; j++)
            for(int z = 0; z <= s; z++)
                pd[j][z] = dp[j][z];
    }
    cout << dp[k][s];
}