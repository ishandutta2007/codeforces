#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define vi vector<int>
#define ll long long
using namespace std;
template<int N, int M> struct maxflow {
    using F = ll;
    const F oo = 0x3f3f3f3f3f3f3f3f;
    struct Edge {
        int to, nxt;
        F f;
    } e[M << 1];
    int head[N], cur[N], tot = 1;
    void clear(int n) { memset(head, 0, sizeof(int) * (n + 1)), tot = 1; }
    void addedge(int u, int v, F f) {e[++tot] = Edge{v, head[u], f}; head[u] = tot; }
    void add(int u, int v, F f) { addedge(u, v, f), addedge(v, u, 0); }
    F dep[N];
    deque<int> q;
    int bfs(int s, int t, int n) {
        for(int i = 1; i <= n; i++) cur[i] = head[i], dep[i] = oo;
        dep[s] = 0;
        q.push_back(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop_front();
            for(int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if(e[i].f && dep[v] > dep[u] + 1) {
                    dep[v] = dep[u] + 1;
                    q.push_back(v);
                }
            }
        }
        return dep[t] < oo;
    }
    F dfs(int u, int t, F in) {
        if(u == t || !in) return in;
        F out = 0, f;
        for(int &i = cur[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if(dep[v] == dep[u] + 1 && (f = dfs(v, t, min(in, e[i].f))) > 0) {
                out += f, in -= f, e[i].f -= f, e[i ^ 1].f += f;
                if(!in) break;
            }
        }
        if(out == 0) dep[u] = -1;
        return out;
    }
    F dinic(int s, int t, int n) {
        F flow = 0;
        while(bfs(s, t, n)) flow += dfs(s, t, oo);
        return flow;
    }
};
const int N = 1e5 + 10;
maxflow<N * 2, N * 30> so;
vector<int> factor[N];
int n, a[N], id1[N], id2[N], id3[N], id4[N], tot = 0;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    so.clear(n * 4 + 2);
    int s = ++tot, t = ++tot;
    for(int i = 1; i <= n; i++) {
        id1[a[i]] = ++tot, id2[a[i]] = ++tot, id3[a[i]] = ++tot, id4[a[i]] = ++tot;
        so.add(s, id1[a[i]], 1), so.add(s, id2[a[i]], 1), so.add(id3[a[i]], t, 1), so.add(id4[a[i]], t, 1);
    }
    for(int i = 1; i <= n; i++) {
        int v = a[i];
        for(auto d : factor[v]) if(id1[d]) {
            if(v != d) so.add(id1[v], id3[d], 1);
            if(v != d) so.add(id2[v], id4[d], 1);
            so.add(id1[v], id4[d], 1);
        }
    }
    int ans = n * 2 - so.dinic(s, t, tot);
    cout << n - ans << endl;
    for(int i = 1; i <= n; i++) id1[a[i]] = id2[a[i]] = id3[a[i]] = id4[a[i]] = 0;
    tot = 0;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int v = 5e4;
    for(int i = 1; i <= v; i++) for(int j = i; j <= v; j += i) factor[j].push_back(i);
    int t;
    for(cin >> t; t--; solve());
}