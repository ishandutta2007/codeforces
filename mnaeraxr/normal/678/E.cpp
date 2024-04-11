#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Probably bad (greedy from ffao[18489412])

    int n; cin >> n;

    vector<vector<double>> p(n, vector<double>(n));
    vector<vector<double>> dp(n, vector<double>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> p[i][j];

    vector<bool> mk(n);

    dp[0][0] = 1.0;
    int last = 0;
    mk[last] = 1;

    for (int j = 1; j < n; ++j){
        int cur = -1;
        for (int i = 0; i < n; ++i) if (!mk[i]){
            dp[j][i] = dp[j - 1][i] * p[i][last] + dp[j - 1][last] * p[last][i];
            if (cur == -1 || dp[j][cur] < dp[j][i])
                cur = i;
        }

        mk[cur] = true;
        last = cur;
    }

    cout.precision(17);
    cout << fixed << dp[n - 1][last] << endl;

    return 0;
}