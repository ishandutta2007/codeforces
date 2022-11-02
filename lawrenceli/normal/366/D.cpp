#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1010;
const int MAXM = 3010;

struct edge {
    int n, l, r;
    edge() {}
    edge(int n, int r) : n(n), l(0), r(r) {}
    edge(int n, int l, int r) : n(n), l(l), r(r) {}
    bool operator<(const edge& e) const {
        return r < e.r;
    }
};

int n, m, nums[MAXM], cnt, lt, ans;
vector<edge> adj[MAXN];
set<int> st;

priority_queue<edge> pq;
bool vis[MAXN];
int dist[MAXN];

void dijkstra() {
    for (int i=0; i<n; i++) {
        vis[i] = 0; dist[i] = 0;
    }
    while (!pq.empty()) pq.pop();
    pq.push(edge(0, 1e9));
    while (!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (vis[e.n]) continue;
        vis[e.n] = 1; dist[e.n] = e.r;
        for (int i=0; i<adj[e.n].size(); i++) {
            if (adj[e.n][i].l > lt) continue;
            pq.push(edge(adj[e.n][i].n, min(e.r, adj[e.n][i].r)));
        }
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        int a, b, l, r; scanf("%d %d %d %d", &a, &b, &l, &r);
        a--; b--;
        adj[a].push_back(edge(b, l, r));
        adj[b].push_back(edge(a, l, r));
        st.insert(l);
    }
    for (typeof(st.begin()) it = st.begin(); it != st.end(); it++) {
        nums[cnt++] = *it;
    }
    for (int i=0; i<cnt; i++) {
        lt = nums[i];
        dijkstra();
        ans = max(ans, dist[n-1] - lt + 1);
    }
    if (ans == 0) printf("Nice work, Dima!\n");
    else printf("%d\n", ans);
    return 0;
}