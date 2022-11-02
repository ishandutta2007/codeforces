#include <bits/stdc++.h>

using namespace std;

const int N = 444;

int d[N][N];
int deg[N];
bool was[N];
double prob[N];
double prob_dist[N];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        fill(d[i], d[i] + n, N);       
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        d[a][b] = d[b][a] = 1;
        deg[a]++;
        deg[b]++;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    double res = 0.0;
    for (int a = 0; a < n; a++) {
        double cur = 0.0;
        for (int d0 = 0; d0 < n; d0++) {
            vector<int> at;
            for (int b = 0; b < n; b++)
                if (d[a][b] == d0)
                    at.push_back(b);
            if (at.size() == 0)
                continue;
            for (int i = 0; i < n; i++) { 
                was[i] = false;
                prob[i] = 0.0;
                prob_dist[i] = 0.0;
            }
            vector<int> next;
            for (int v : at) 
                for (int to = 0; to < n; to++)
                    if (d[v][to] == 1) { 
                        prob[to] += 1.0 / (at.size() * deg[v]);
                        if (!was[to]) {
                            was[to] = true;
                            next.push_back(to);
                        }
                    }
            double t = 0.0;
            for (int b = 0; b < n; b++) {
                double ct = 0.0;
                for (int v : next)
                    prob_dist[d[b][v]] = max(prob_dist[d[b][v]], prob[v]);
                for (int v : next) {
                    int cur_d = d[b][v];
                    ct += prob_dist[cur_d];
                    prob_dist[cur_d] = 0.0; 
                }
                t = max(t, ct);
            }
            cur += max(1.0 / n, at.size() * 1.0 / n * t);
        }
        res = max(res, cur);
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res << endl;
    return 0;
}