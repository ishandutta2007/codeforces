#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = (int)1e9 + 10;
const int N = 1111;

int calc_dist(const vector<vector<int>>& g, const vector<vector<int>>& w, int s, int t) {
    vector<int> dist(g.size(), INF);
    set<pii> q;
    dist[s] = 0;
    q.insert(pii(dist[s], s));
    while (q.size()) {
        int v = q.begin()->second;
        if (v == t)
            break;
        q.erase(q.begin());
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            int len = w[v][i];
            if (dist[to] > dist[v] + len) {
                q.erase(pii(dist[to], to));
                dist[to] = dist[v] + len;
                q.insert(pii(dist[to], to));
            }
        }
    }
    return dist[t];
}

vector<int> calc_path(const vector<vector<int>>& g, const vector<vector<int>>& w, int s, int t) {
    vector<int> dist(g.size(), INF);
    vector<int> par(g.size());
    set<pii> q;
    dist[s] = 0;
    q.insert(pii(dist[s], s));
    while (q.size()) {
        int v = q.begin()->second;
        if (v == t)
            break;
        q.erase(q.begin());
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            int len = w[v][i];
            if (dist[to] > dist[v] + len) {
                q.erase(pii(dist[to], to));
                par[to] = v;
                dist[to] = dist[v] + len;
                q.insert(pii(dist[to], to));
            }
        }
    }
    int v = t;
    vector<int> path;
    while (v != s) {
        path.push_back(v);
        v = par[v];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

bool must_have[N][N];
int pos_at[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int len, s, t;
    cin >> len >> s >> t;
    vector<vector<int>> g(n);
    vector<vector<int>> w(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pos_at[a][b] = g[a].size();
        pos_at[b][a] = g[b].size();
        if (c != 0)
            must_have[a][b] = must_have[b][a] = true;
        else
            c = INF;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }
    int dist = calc_dist(g, w, s, t);
    if (dist < len) {
        cout << "NO" << endl;
        return 0;
    }
    auto g1 = g;
    auto w1 = w;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < w1[i].size(); j++)
            if (w1[i][j] == INF)
                w1[i][j] = 1;
    int dist2 = calc_dist(g1, w1, s, t);
    if (dist2 > len) {
        cout << "NO" << endl;
        return 0;
    }
    auto path = calc_path(g1, w1, s, t);
    vector<pii> to_change;
    for (int i = 0; i < path.size() - 1; i++)
        if (!must_have[path[i]][path[i + 1]])
            to_change.push_back(pii(path[i], path[i + 1]));
    for (pii e : to_change) {
        int a = e.first;
        int b = e.second;
        w[a][pos_at[a][b]] = 1;
        w[b][pos_at[b][a]] = 1;
    }
    ll cur_dist = calc_dist(g, w, s, t);
    assert (cur_dist == dist2);
    for (pii e : to_change) {
        if (cur_dist == len)
            break;
        int a = e.first;
        int b = e.second;
        w[a][pos_at[a][b]] = INF;
        w[b][pos_at[b][a]] = INF;
        int upper_dist = min(len, calc_dist(g, w, s, t));
        int delta = upper_dist - cur_dist;
        w[a][pos_at[a][b]] = 1 + delta;
        w[b][pos_at[b][a]] = 1 + delta;
        cur_dist = upper_dist;
    }
    assert (calc_dist(g, w, s, t) == len);
    assert (cur_dist == len);
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++)
            if (i < g[i][j]) {
                cout << i << " " << g[i][j] << " " << w[i][j] << "\n";
            }
}