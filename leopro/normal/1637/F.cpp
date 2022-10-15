#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) {cout << ans << '\n'; return;}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &x: h) cin >> x;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    queue<int> bfs;
    int idx = max_element(h.begin(), h.end()) - h.begin();
    vector<int> e(n), maxFromIdx(n, -1);
    for (int i = 0; i < n; ++i) {
        if (tree[i].size() == 1 && i != idx) {
            bfs.push(i);
        }
    }
    vector<int> neighboursSeen(n);
    while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();
        if (cur != idx && neighboursSeen[cur] == tree[cur].size() - 1) {
            neighboursSeen[cur]++;
            for (int next: tree[cur]) {
                neighboursSeen[next]++;
                if (maxFromIdx[next] == -1) {
                    bfs.push(next);
                    continue;
                }
                if (maxFromIdx[cur] == -1 || e[maxFromIdx[cur]] < e[maxFromIdx[next]]) {
                    maxFromIdx[cur] = maxFromIdx[next];
                }
            }
            if (maxFromIdx[cur] == -1) maxFromIdx[cur] = cur;
            e[maxFromIdx[cur]] = max(e[maxFromIdx[cur]], h[cur]);
        }
    }
    vector<int> ind;
    for (int c: tree[idx]) {
        ind.push_back(maxFromIdx[c]);
    }
    sort(ind.rbegin(), ind.rend(), [&](int u, int v) { return e[u] < e[v]; });
    if (tree[idx].size() == 1) {
        e[idx] = h[idx];
        e[ind[0]] = h[idx];
    } else {
        e[ind[0]] = h[idx];
        e[ind[1]] = h[idx];
    }
    cout << accumulate(e.begin(), e.end(), 0LL) << '\n';
}