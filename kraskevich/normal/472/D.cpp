#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9 + 10;
const int NN = 2222;
const string N = "NO";
const string Y = "YES";

vector<int> g[NN];
vector<int> w[NN];
int par[NN];
long long d[NN];
int dist[NN][NN];
bool in[NN];
bool u[NN];
int n;

void dfs(int v, long long h) {
    u[v] = true;
    d[v] = h;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        long long hh = w[v][i];
        if (!u[to])
            dfs(to, hh + h);
   }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    for (int i = 0; i < n; i++)
        if (dist[i][i]) {
            cout << N;
            return 0;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (dist[i][j] == 0 || dist[i][j] != dist[j][i]) {
                cout << N;
                return 0;
            }
        } 
    fill(d, d + n, INF);
    d[0] = 0;
    par[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!in[j] && (v == -1 || d[j] < d[v]))
                v = j;
        in[v] = true;
        for (int to = 0; to < n; to++)
            if (!in[to] && d[to] > dist[to][v]) {
                d[to] = dist[to][v];
                par[to] = v;
            }
    }
    for (int i = 1; i < n; i++) {
        g[i].push_back(par[i]);
        g[par[i]].push_back(i);
        w[i].push_back(dist[i][par[i]]);
        w[par[i]].push_back(dist[i][par[i]]);
    }
    for (int i = 0; i < n; i++) {
        fill(u, u + n, false);
        dfs(i, 0);
        for (int j = 0; j < n; j++)
            if (d[j] != dist[i][j]) {
                cout << N;
                return 0;
            }
    }
    cout << Y;
    return 0;
}