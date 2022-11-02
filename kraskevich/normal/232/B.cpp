#include <iostream>

using namespace std;


const int N = 100 + 10;
const int K = N * N + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

int c[N][N];
int c_pow_m[N][N];
int dp[N][K];

void calc_cnk()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i][j] = 0;
        }
    }
    c[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            c[i][j] = c[i - 1][j];
            if (j)
            {
                c[i][j] += c[i - 1][j - 1];
                c[i][j] %= MOD;
            }
        }
    }
}

long long bin_pow(int base, long long n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = res * 1ll * base % MOD;
        }
        base = base * 1ll * base % MOD;
        n /= 2;
    }
    return res;
}

void calc_cnk_pow_m(long long m)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            c_pow_m[i][j] = bin_pow(c[i][j], m);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    long long n, m, k;
    cin >> n >> m >> k;

    calc_cnk();
    calc_cnk_pow_m(m / n);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (int length = 1; length <= n; length++)
    {
        for (int prev_sum = 0; prev_sum <= k; prev_sum++)
        {
            for (int cur_sum = prev_sum; cur_sum <= k && cur_sum - prev_sum <= n; cur_sum++)
            {
                int add = dp[length - 1][prev_sum] * 1ll * c_pow_m[n][cur_sum - prev_sum] % MOD;
                if (length <= m % n)
                {
                    add = add * 1ll * c[n][cur_sum - prev_sum] % MOD;
                }
                dp[length][cur_sum] += add;
                dp[length][cur_sum] %= MOD;
            }
        }
    }

    cout << dp[n][k];

    return 0;
}