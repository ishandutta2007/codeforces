#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 1e4 + 4;
const int M = 1e3 + 3;

int m, dp[N][M], n, d[N], g, r;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    //n = 1e4;
    //m = 1e4 + 1;
    for (int i = 1; i <= m; i++)
        cin >> d[i];
        //d[i] = i - 1;
    sort(d + 1, d + m + 1);
    cin >> g >> r;
    queue<pair<pair<int, int>, int> > q;
    for (int i = 1; i <= m; i++)
        for (int t = 0; t < g; t++)
            dp[i][t] = 2e9 + 5;
    dp[1][0] = 0;
    q.push({{0, 1}, 0});
    while (q.size() > 0) {
        int dist = -q.front().first.first, v = q.front().first.second, t = q.front().second;
        q.pop();
        if (dist != dp[v][t])
            continue;
        if (v != 1) {
            int t2 = t + d[v] - d[v - 1];
            if (t2 <= g && dp[v - 1][t2 % g] > dp[v][t] + d[v] - d[v - 1] + r * (t == 0)) {
                dp[v - 1][t2 % g] = dp[v][t] + d[v] - d[v - 1] + r * (t == 0);
                q.push({{-dp[v - 1][t2 % g], v - 1}, t2 % g});
            }
        }
        if (v != m) {
            int t2 = t + d[v + 1] - d[v];
            if (t2 <= g && dp[v + 1][t2 % g] > dp[v][t] + d[v + 1] - d[v] + r * (t == 0)) {
                dp[v + 1][t2 % g] = dp[v][t] + d[v + 1] - d[v] + r * (t == 0);
                q.push({{-dp[v + 1][t2 % g], v + 1}, t2 % g});
            }
        }
    }
    int ans = 2e9 + 5;
    for (int i = 0; i < g; i++)
        if (dp[m][i] != -1)
            ans = min(ans, dp[m][i]);
    if (ans == 2e9 + 5)
        cout << -1;
    else
        cout << ans - r << "\n";
    return 0;
}