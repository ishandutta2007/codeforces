#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, u, v, k, dst[N], num[N], a[N];
vector<int> adj[N];

void BFS(int st) {
    fill(dst + 1, dst + n + 1, -1);
    queue<int> q;
    for (dst[st] = 0, num[st] = 1, q.push(st); !q.empty(); q.pop()) {
        int u = q.front();
        for (int& v : adj[u]) {
            if (dst[v] == -1) {
                dst[v] = dst[u] + 1;
                num[v] = 1;
                q.push(v);
            } else if (dst[v] == dst[u] + 1) {
                num[v]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        adj[v].push_back(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    BFS(a[k]);
    int mi = 0, mx = 0;
    for (int i = 1; i < k; i++) {
        if (dst[a[i]] != dst[a[i + 1]] + 1) {
            mi++;
        }
        if (dst[a[i]] != dst[a[i + 1]] + 1 || num[a[i]] > 1) {
            mx++;
        }
    }
    cout << mi << " " << mx;
}