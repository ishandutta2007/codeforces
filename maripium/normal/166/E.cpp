#include <iostream>

using namespace std;

const int mod = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int dp[n+1][5];

    dp[1][4] = 0;
    dp[1][3] = 1;
    dp[1][2] = 1;
    dp[1][1] = 1;

    for (int i = 2; i<n+1; i++)
    {
        for (int j = 1; j<5; j++)
        {
            dp[i][j] = 0;
            for (int k = 1; k<5; k++)
            {
                if (j!=k)
                {
                    dp[i][j] = (dp[i][j]%mod + dp[i-1][k]%mod)%mod;
                }
            }
        }
    }
    cout << dp[n][4]%mod;
    return 0;
}