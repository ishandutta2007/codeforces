#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int mod = 1000000007;
const int Maxn = 200005;
const int Inf = 1000000000;

int T;
int n, m;
int s, t;
vector <int> neigh[Maxn];
int dist[Maxn];
int dp[Maxn][2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        scanf("%d %d", &s, &t);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            dist[i] = Inf;
            dp[i][0] = dp[i][1] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        queue <int> Q; Q.push(t);
        dist[t] = 0;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int i = 0; i < neigh[v].size(); i++) {
                int u = neigh[v][i];
                if (dist[v] + 1 < dist[u]) {
                    dist[u] = dist[v] + 1;
                    Q.push(u);
                }
            }
        }
        vector <iii> seq;
        for (int i = 1; i <= n; i++) {
            seq.push_back(iii(dist[i], ii(i, 1)));
            seq.push_back(iii(dist[i] + 1, ii(i, 0)));
        }
        sort(seq.rbegin(), seq.rend());
        for (int i = 0; i < seq.size(); i++) {
            ii v = seq[i].second;
            if (v.first == s && v.second == 0)
                dp[s][0] = (dp[s][0] + 1) % mod;
            for (int j = 0; j < neigh[v.first].size(); j++) {
                int u = neigh[v.first][j];
                if (dist[v.first] == dist[u]) {
                    if (v.second == 0)
                        dp[u][1] = (dp[u][1] + dp[v.first][v.second]) % mod;
                } else if (dist[v.first] > dist[u])
                    dp[u][v.second] = (dp[u][v.second] + dp[v.first][v.second]) % mod;
            }
        }
        int res = (dp[t][0] + dp[t][1]) % mod;
        printf("%d\n", res);
    }
    return 0;
}