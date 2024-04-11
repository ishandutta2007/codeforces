#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 3 * (int)1e5 + 3;
vector < int > g[N];
queue < int > q;
int dist1[N];
int dist2[N];
int num[N];
int x[N];
int deg[N];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int a, b;
    int mi = 1;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] < deg[mi]) {
            mi = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        dist1[i] = -1;
        dist2[i] = -1;
    }
    q.push(mi);
    dist1[mi] = 0;
    //cout << mi << '\n';
    int en = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (dist1[to] == -1) {
                dist1[to] = dist1[v] + 1;
                q.push(to);
                if (dist1[to] > dist1[en]) {
                    en = to;
                }
            }
        }
    }
    q.push(en);
    dist2[en] = 0;
    int be = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (dist2[to] == -1) {
                dist2[to] = dist2[v] + 1;
                q.push(to);
                if (dist2[to] > dist2[be]) {
                    be = to;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dist1[i] = -1;
    }
    q.push(be);
    dist1[be] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (dist1[to] == -1) {
                dist1[to] = dist1[v] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist2[i] == dist2[be]) {
            num[i] = 1;
            x[1]++;
            continue;
        }
        num[i] = dist1[i] + 1;
        x[num[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int to = g[i][j];
            if (abs(num[to] - num[i]) > 1) {
                cout << "NO";
                return 0;
            }
        }
    }
    //cout << en << " " << be << '\n';
    long long ne = 0;
    for (int i = 1; i <= n + 2; i++) {
        ne += 1LL * x[i] * (x[i] - 1) / 2;
        if (i > 1) {
            ne += 1LL * x[i] * x[i - 1];
        }
    }
    if (ne == m) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << num[i] << " ";
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}