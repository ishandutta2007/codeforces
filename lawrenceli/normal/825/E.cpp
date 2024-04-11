#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, m;
vector<int> adj[maxn];
int indeg[maxn];
int ans[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        indeg[a]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            pq.push(i);

    int cnt = n;
    while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        ans[x] = cnt--;
        for (int i : adj[x]) {
            indeg[i]--;
            if (indeg[i] == 0) pq.push(i);
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}