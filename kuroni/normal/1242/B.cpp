#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, u, v, ans = -1;
bool chk[N];
vector<int> adj[N];
list<int> li;
queue<int> q;

void BFS(int s) {
    li.pop_back();
    for (q.push(s); !q.empty(); q.pop()) {
        int u = q.front();
        for (int &v : adj[u]) {
            chk[v] = true;
        }
        for (auto it = li.begin(); it != li.end();) {
            if (chk[*it]) {
                it = next(it);
            } else {
                q.push(*it);
                it = li.erase(it);
            }
        }
        for (int &v : adj[u]) {
            chk[v] = false;
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        li.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (!li.empty()) {
        BFS(li.back());
        ans++;
    }
    cout << ans;
}