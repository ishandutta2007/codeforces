#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, a, b;
vector<int> V[N];
int dp[N];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 0; j < V[i].size(); j++) {
            int u = V[i][j];
            if (u < i) {
                dp[i] = max(dp[i], dp[u] + 1);
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (long long)V[i].size() * dp[i]);
    }

    printf("%I64d\n", ans);

    return 0;
}