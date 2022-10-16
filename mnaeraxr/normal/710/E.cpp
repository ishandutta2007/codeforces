#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 20000000 + 20;

int64 dp[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int64 n, x, y;
    cin >> n >> x >> y;

    memset(dp, oo, sizeof dp);

    dp[1] = x;
    dp[2] = x + y;

    for (int i = 2; i <= n; ++i){
        dp[i] = min(dp[i], dp[i - 1] + x);
        dp[i] = min(dp[i], dp[i + 1] + x);

        dp[2 * i] = min(dp[2 * i], dp[i] + y);
        dp[2 * i - 1] = min(dp[2 * i - 1], dp[2 * i] + x);
    }


    cout << dp[n] << endl;


    return 0;
}