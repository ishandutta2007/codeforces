#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int maxn = 405;
const int inf = 1e9;

int n, m, deg[maxn], dist[maxn][maxn];
bool mat[maxn][maxn];
ld p[maxn], best[maxn];
bool u[maxn], u2[maxn];

int V[maxn], vs;
int W[maxn], wsze;
int V2[maxn], v2s;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = inf;
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = mat[b][a] = 1;
        dist[a][b] = dist[b][a] = 1;
        deg[a]++, deg[b]++;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    ld ma = 0;

    for (int i = 0; i < n; i++) {
        ld sum = 0;
        for (int d = 0; d < n; d++) {
            for (int j = 0; j < n; j++) p[j] = u[j] = 0;

            vs = 0;
            for (int j = 0; j < n; j++)
                if (dist[i][j] == d)
                    V[vs++] = j;

            if (vs == 0) continue;

            wsze = 0;
            for (int j1 = 0; j1 < vs; j1++) {
                int j = V[j1];
                for (int k = 0; k < n; k++)
                    if (mat[j][k]) {
                        if (!u[k]) u[k] = 1, W[wsze++] = k;
                        p[k] += ld(1) / (vs * deg[j]);
                    }
            }

            ld ma2 = ld(1) / vs;
            for (int j = 0; j < n; j++) {
                v2s = 0;
                for (int k1 = 0; k1 < wsze; k1++) {
                    int k = W[k1];
                    int x = dist[j][k];
                    if (!u2[x]) u2[x] = 1, V2[v2s++] = x;
                    best[x] = max(best[x], p[k]);
                }
                ld sum2 = 0;
                for (int k1 = 0; k1 < v2s; k1++) {
                    int k = V2[k1];
                    sum2 += best[k];
                    u2[k] = best[k] = 0;
                }
                ma2 = max(ma2, sum2);
            }

            sum += ld(vs) / n * ma2;
            //if (i == 0) cout << sum << ' ' << v.size() << ' ' << w.size() << endl;
            //if (i == 0) cout << ld(v.size()) / n * ma2 << ' ' << ma2 << endl;
        }

        ma = max(ma, sum);
    }

    cout << fixed << setprecision(10) << ma << '\n';
}