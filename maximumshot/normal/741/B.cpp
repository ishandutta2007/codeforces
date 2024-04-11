#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1005;

int n, m, w;
int weight[N];
int b[N];
int g[N][N];
int t[N][N];

int main() {

    scanf("%d %d %d", &n, &m, &w);

    for(int i = 1;i <= n;i++) scanf("%d", &weight[i]);
    for(int i = 1;i <= n;i++) scanf("%d", &b[i]);

    for(int u, v, i = 1;i <= m;i++) {
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
        t[u][v] = t[v][u] = 1;
    }

    vec< vec< int > > comp;
    vec< int > tmp;
    vec< char > used(n + 1);

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        queue< int > q;
        q.push(i);
        tmp.clear();
        tmp.push_back(i);
        used[i] = 1;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to = 1;to <= n;to++) {
                if(t[v][to] && !used[to]) {
                    used[to] = 1;
                    q.push(to);
                    tmp.push_back(to);
                }
            }
        }
        comp.push_back(tmp);
    }

//    cout << "\n";
//    for(auto i : comp) {
//        for(auto j : i)
//            cout << j << " ";
//        cout << "\n";
//    }
//    cout << "\n";

    int sz = (int)comp.size();

    vec< vec< int > > dp(sz + 1, vec< int >(w + 1, -inf));

    dp[0][0] = 0;

    for(int iter = 0;iter < sz;iter++) {
        dp[iter + 1] = dp[iter];
        int sum_w = 0;
        int sum_b = 0;
        for(int x : comp[iter]) {
            sum_w += weight[x];
            sum_b += b[x];
            for(int now = weight[x];now <= w;now++) {
                if(dp[iter][now - weight[x]] != -inf)
                   dp[iter + 1][now] = max(dp[iter + 1][now], dp[iter][now - weight[x]] + b[x]);
            }
        }
        for(int now = sum_w;now <= w;now++) {
            if(dp[iter][now - sum_w] != -inf)
                dp[iter + 1][now] = max(dp[iter + 1][now], dp[iter][now - sum_w] + sum_b);
        }
    }

    int res = 0;

    for(int now = 0;now <= w;now++) {
        if(dp[sz][now] != -inf)
            res = max(res, dp[sz][now]);
    }

    printf("%d\n", res);

    return 0;
}