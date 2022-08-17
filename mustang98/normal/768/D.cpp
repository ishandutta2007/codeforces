#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_k = 1111, max_n = 8111;

ld dp[max_n][max_k];

int main()
{
    int k, q;
    cin >> k >> q;
    for (int j = 0; j <= k; ++j)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i < max_n; ++i)
    {
        dp[i][0] = 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i < max_n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            dp[i][j] = dp[i - 1][j] * j / k;
            dp[i][j] += dp[i - 1][j - 1] * (k - j + 1) / k;
        }
    }

    /*for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/
    ld p;
    for (int i = 0; i < q; ++i)
    {
        cin >> p;
        //p = 1000;
        p /= 2000;
        for (int i = 0; ; ++i)
        {
            if (dp[i][k] >= p)
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}