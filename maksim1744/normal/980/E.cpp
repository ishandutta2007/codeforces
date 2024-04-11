/*
    31.10.2018 20:07:04
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector< vector< int > > g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // printTree(g);
    vector< char > u(n, false);
    queue< int > q;
    q.push(n - 1);
    vector< int > d(n, 1000000000);
    vector< int > p(n, -1);
    d[n - 1] = 0;
    while (!q.empty()) {
        int v = q.front();
        u[v] = true;
        q.pop();
        for (auto t : g[v]) {
            if (!u[t]) {
                q.push(t);
                d[t] = d[v] + 1;
                p[t] = v;
            }
        }
    }
    vector< vector< int > > logp(n, vector< int >(21, -1));
    for (int i = 0; i < n; ++i) {
        // logp[i][0] = i;
        logp[i][0] = p[i];
    }
    for (int i = 1; i < logp[0].size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (logp[j][i - 1] != -1) {
                logp[j][i] = logp[logp[j][i - 1]][i - 1];
            }
        }
    }
    // print(logp);
    // print(d);
    // print(p);
    u.assign(n, false);
    u[n - 1] = true;
    int sz = 1;
    for (int i = n - 2; i >= 0; --i) {
        int v = i;
        int path = 0;
        while (!u[v]) {
            int j = 0;
            while (j < logp[v].size() && logp[v][j] != -1 && !u[logp[v][j]]) {
                ++j;
            }
            // cout << j << ' ' << path << ' ' << v << ' ';
            // v = logp[v][j];
            if (j == 0) {
                ++path;
                break;
            } else {
                path += (1 << (j - 1));
                v = logp[v][j - 1];
            }
            // cout << v << endl;
        }
        if (sz + path <= n - k) {
            sz += path;
            v = i;
            while (!u[v]) {
                u[v] = true;
                v = p[v];
            }
        }
        if (sz == n - k) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!u[i]) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
    return 0;
}