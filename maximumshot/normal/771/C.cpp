#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n, k;
vec< int > g[N];
ll result = 0;

ll dp[N][5];
int cn[N][5];

void dfs(int v, int par = -1) {
    cn[v][0]++;
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
        for(int x = 0;x < k;x++) {
            cn[v][(x + 1) % k] += cn[to][x];
            dp[v][(x + 1) % k] += dp[to][x] + 1ll * (x == 0) * cn[to][x];
        }
    }
    vec< ll > sum(k);
    vec< int > cnt(k);
    for(int u, w, i = 0;i < (int)g[v].size();i++) {
        u = g[v][i];
        if(u == par) continue;
        for(int x = 0;x < k;x++) {
            for(int y = 0;y < k;y++) {
                int ln = (x + y + 2);
                ln = (ln + k - 1) / k;
                result += (dp[u][x] - 1ll * cn[u][x] * (x > 0)) * cnt[y] +
                          (sum[y] - 1ll * cnt[y] * (y > 0)) * cn[u][x] +
                          1ll * ln * cn[u][x] * cnt[y];
            }
        }
        for(int x = 0;x < k;x++) {
            sum[x] += dp[u][x];
            cnt[x] += cn[u][x];
        }
    }
    for(int x = 0;x < k;x++) {
        result += dp[v][x];
    }
}

int main() {

    scanf("%d %d", &n, &k);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    cout << result << "\n";

    return 0;
}