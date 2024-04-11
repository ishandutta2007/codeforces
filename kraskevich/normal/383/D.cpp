#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pll;
#define F first
#define S second
#define MP make_pair

const int N = 1111;
const int A = 10001;
const int S = 20022;
const int MOD = 1000 * 1000 * 1000 + 7;

int a[N];
int dp[N][S];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < S; s++)
        {
            if (dp[i][s] == 0)
                continue;
            dp[i + 1][s + a[i]] += dp[i][s];
            dp[i + 1][s + a[i]] %= MOD;
            dp[i + 1][s - a[i]] += dp[i][s];
            dp[i + 1][s - a[i]] %= MOD;
        }
        dp[i + 1][A + a[i]]++;
        dp[i + 1][A - a[i]]++;
        res += dp[i + 1][A];
        res %= MOD;
    }
    cout << res;
}