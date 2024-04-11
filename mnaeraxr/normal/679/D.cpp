#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 500 + 1;

int dist[maxn][maxn];
bool vis[maxn];
double prob[maxn];

double max_prob_dist[maxn];
bool ok[maxn];

vi adj[maxn];

/*
3 3
1 2
2 3
1 3
 */
double second_day(int g1, int d1, int n){
    int total = 0;

    for (int u = 1; u <= n; ++u){
        prob[u] = 0;
        vis[u] = false;
        if (dist[g1][u] == d1) ++total;
    }

    vector<int> valid;

    for (int u = 1; u <= n; ++u){
        if (dist[u][g1] != d1) continue;

        for (auto v : adj[u]){
            prob[v] += 1.0 / adj[u].size() / total;
            if (!vis[v]){
            	valid.push_back(v);
            	vis[v] = true;
            }
        }
    }

    double ans = 0;

    for (int g2 = 1; g2 <= n; ++g2){
        double cur = 0;

        for (int u : valid){
            int d = dist[u][g2];
            max_prob_dist[d] = max(max_prob_dist[d], prob[u]);
            ok[d] = true;
        }

        for (int u : valid){
            int d = dist[u][g2];
            if (ok[d]){
                cur += max_prob_dist[d];
                ok[d] = false;
                max_prob_dist[d] = 0;
            }
        }

        ans = max(cur, ans);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    memset(dist, 0x3f, sizeof dist);

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        dist[u][v] = dist[v][u] = 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    double ans = 0;
    for (int g1 = 1; g1 <= n; ++g1){
        double cur = 0;

        for (int d1 = 0; ;++d1){
            int total = 0;
            for (int u = 1; u <= n; ++u)
                if (dist[u][g1] == d1) ++total;

            if (total == 0) break;

            double sday  = second_day(g1, d1, n);
            double tmp = 1.0 * total / n * max(1.0 / total, sday);
            cur += tmp;
        }

        ans = max(ans, cur);
    }

    cout.precision(17);
    cout << fixed << ans << endl;

    return 0;
}