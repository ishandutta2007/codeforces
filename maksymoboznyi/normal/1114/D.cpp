#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 5e3 + 5;

int dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i == 1 || x != a.back())
            a.pb(x);
    }
    if (a.size() == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i + 1 < a.size(); i++)
        if (a[i] == a[i + 1])
            dp[i][i + 1] = 0;
        else
            dp[i][i + 1] = 1;
    for (int len = 3; len <= a.size(); len++)
    for (int l = 0; l + len - 1 < a.size(); l++) {
        int r = l + len - 1;
        if (a[l] == a[r])
            dp[l][r] = dp[l + 1][r - 1] + 1;
        else
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
    }
    cout << dp[0][a.size() - 1];
    return 0;
}