#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)5e3 + 10;
const int MOD = 1000000007;

int dp[MAXN][MAXN];
int fac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, A, B, K;
    cin >> N >> A >> B >> K;

    if (B < A)
    {
        A = N - A + 1;
        B = N - B + 1;
    }

    dp[0][A] = 1;
    for (int i = 1; i <= K; ++i)
    {
        for (int j = 1; j < B; ++j)
        {
            dp[i][j] += dp[i - 1][j - 1] + dp[i][j - 1];
            dp[i][j] %= MOD;
        }
        /*
        cout << "............." << endl;
        for (int j = 0; j < B; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
         */
        memset(fac, 0, sizeof fac);
        for (int j = B - 1, f = 0; j > 0; --j)
        {
            fac[max(0, 2 * j  - B + 1)] += dp[i - 1][j];
            fac[max(0, 2 * j  - B + 1)] %= MOD;

            dp[i][j] = (f + dp[i][j]) % MOD;

            f = (f + dp[i - 1][j]) % MOD;
            f = (f - fac[j] + MOD) % MOD;
        }
        /*
        for (int j = 0; j < B; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
        */
    }

    int ans = 0;
    for (int i = 1; i < B; ++i)
        ans = (ans + dp[K][i]) % MOD;
    cout << ans << endl;

    return 0;
}