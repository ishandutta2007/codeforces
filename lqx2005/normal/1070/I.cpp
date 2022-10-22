#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 600 + 10;
const int oo = 0x3f3f3f3f;
namespace flow {
    const int N = 600 * 2 + 10, M = N << 1;
    struct Edge {
        int to, nxt, f;
    }e[M << 1];
    int head[N], tot = 1;
    int dep[N], cur[N];
    void clear() {memset(head, 0, sizeof(head)), tot = 1; }
    void adde(int u, int v, int w) {e[++tot] = Edge{v, head[u], w}, head[u] = tot; }
    void fadd(int u, int v, int w) {adde(u, v, w), adde(v, u, 0); }
    int bfs(int s, int t, int n) {
        for(int i = 1; i <= n; i++) cur[i] = head[i], dep[i] = oo;
        static queue<int> q;
        q.push(s);
        dep[s] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = cur[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if(e[i].f && dep[v] > dep[u] + 1) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        // cout << dep[t] << endl;
        return dep[t] < oo;
    }
    
    int dfs(int u, int t, int in) {
        if(u == t || !in) return in;
        int f = 0, flow = 0;
        for(int &i = cur[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if(dep[v] == dep[u] + 1 && (f = dfs(v, t, min(in, e[i].f))) > 0) {
                flow += f, in -= f, e[i].f -= f, e[i ^ 1].f += f;
                if(!in) break;
            }
        }
        if(!flow) dep[u] = -1;
        return flow;
    }
    
    int dinic(int s, int t, int n) {
        int flow = 0;
        while(bfs(s, t, n)) flow += dfs(s, t, oo);
        return flow;
    }
}
int n, m, k, deg[N], id[N][2], a[N], b[N], ans[N];
vector<int> e[N];

void quit() {
    for(int i = 1; i <= m; i++) cout << ans[i] <<" ";
    cout << endl;
    return;
}

void solve() {
    flow::clear();
    memset(deg, 0, sizeof(deg));
    memset(id, 0, sizeof(id));
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++) e[i].clear();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
        a[i] = u, b[i] = v;
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    int flag = 0;
    for(int u = 1; u <= n; u++) if(deg[u] > 2 * k) flag = 1;
    if(flag) return quit();
    int s = n + m + 1, t = n + m + 2;
    for(int i = 1; i <= m; i++) flow::fadd(s, i, 1);
    int sum = 0;
    for(int i = 1; i <= m; i++) {
        int u = a[i], v = b[i];
        if(deg[u] > k && deg[v] > k) {
            sum++;
            flow::fadd(i, u + m, oo);
            id[i][0] = flow::tot - 1;
            flow::fadd(i, v + m, oo);
            id[i][1] = flow::tot - 1;
        }
    }
    for(int i = 1; i <= n; i++) if(deg[i] > k) flow::fadd(i + m, t, 2 * k - deg[i]);
    int res = flow::dinic(s, t, n + m + 2);
    if(res < sum) return quit();
    for(int i = 1; i <= m; i++) {
        if(deg[a[i]] <= k || deg[b[i]] <= k) {
            if(deg[a[i]] > k) e[a[i]].push_back(i);
            if(deg[b[i]] > k) e[b[i]].push_back(i);
            continue;
        }
        if(flow::e[id[i][0]].f < oo) e[b[i]].push_back(i);
        else e[a[i]].push_back(i);
    }
    int col = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < sz(e[i]); j += 2) {
            col++;
            ans[e[i][j - 1]] = ans[e[i][j]] = col;
        }
    }
    for(int i = 1; i <= m; i++) if(!ans[i]) ans[i] = ++col;
    return quit();
}

int main() {
    int t;
    for(cin >> t; t--; solve());
    return 0;
}