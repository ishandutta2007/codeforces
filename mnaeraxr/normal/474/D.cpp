#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;
const int MOD = 1000000007;

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, K;
    cin >> T >> K;

    dp[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        dp[i] = dp[i - 1];
        if (i >= K)
            dp[i] = (dp[i] + dp[i - K]) % MOD;
    }

    for (int i = 1; i < MAXN; ++i)
        dp[i] = (dp[i] + dp[i - 1]) % MOD;

    for (int i = 0; i < T; ++i)
    {
        int a, b;
        cin >> a >> b;
        int v = (dp[b] - dp[a - 1]) % MOD;
        if (v < 0) v += MOD;
        cout << v << endl;
    }

    return 0;
}