#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int a[maxN];
int n;
int dp[maxN];
vector < int > g[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].emplace_back(a[i]);
    }
    for (int i = 1; i + 1 <= n; i++) {
        g[i].emplace_back(i + 1);
        g[i + 1].emplace_back(i);
    }
    queue < int > q;
    memset(dp, -1, sizeof dp);
    dp[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dp[to] == -1) {
                dp[to] = dp[v] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    return 0;
}