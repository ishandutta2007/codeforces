#include<vector>
#include<cstdio>
#include<numeric>
#include<algorithm>
#include<functional>

int const nax = 3e5 + 10;
int n, b[nax], dp[nax], ans[nax];
std::vector<int> a[nax];

int main () {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%1d", b + i);
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    std::fill(dp + 1 , dp + 1 + n, -5);

    std::function< void (int , int) > dfs = [&] (int nod, int from) -> void {
        dp[nod] = b[nod] ? 1 : -1;
        for (int i : a[nod]) {
            if (i == from) continue;
            dfs(i, nod);
            dp[nod] += std::max(0, dp[i]);
        }
    };
    dfs(1, 0);

    int cur_ans = (ans[1] = dp[1]);

    std::function< void (int, int) > trace = [&] (int nod, int from) -> void {
        for (int i : a[nod]) {
            if (i == from) continue;
            ans[i] = dp[i] + std::max(0,(ans[nod] - std::max(0, dp[i])));
            trace(i, nod);
        }
    };
    trace(1, 0);
    for (int i = 1 ; i <= n;  ++ i)
        printf("%d ", ans[i]);
}