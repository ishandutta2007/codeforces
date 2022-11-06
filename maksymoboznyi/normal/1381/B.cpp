#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 4e3 + 3;

int n, p[N], dp[2][N];
int q1 = 0, q2 = 1;
vector<int> b;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    cin >> n;
    for (int i = 1; i <= n + n; i++)
        cin >> p[i];
    b.clear();
    int cur = 1;
    while (cur <= n + n) {
        int cc = cur;
        while (cur <= n + n && p[cur] <= p[cc])
            cur++;
        b.pb(cur - cc);
    }
    for (int i = 1; i <= n + n; i++)
        dp[q1][i] = 0;
    dp[q1][0] = 1;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j <= n + n; j++) {
            if (j >= b[i])
                dp[q2][j] = max(dp[q1][j], dp[q1][j - b[i]]);
            else
                dp[q2][j] = dp[q1][j];
        }
        swap(q1, q2);
    }
    if (dp[q1][n])
        cout << "YES\n";
    else
        cout << "NO\n";
    }
    return 0;
}