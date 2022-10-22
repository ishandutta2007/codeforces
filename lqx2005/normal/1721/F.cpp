#include<bits/stdc++.h>
#define FOR(i, j, k) for(int i = (j); i <= (k); ++i)
#define ROF(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 4e5 + 10, inf = 0x3f3f3f3f;
struct Edge {
    int to, nxt, cap;
}e[N * 3];
int hd[N], et = 1, cur[N];
int dep[N];
void addedge(int u, int v, int w) {
    e[++et] = Edge{v, hd[u], w}, hd[u] = et;
}
void add(int u, int v, int w) {
    addedge(u, v, w), addedge(v, u, 0);
}
deque<int> q;
int bfs(int s, int t, int n) {
    FOR(i, 1, n) cur[i] = hd[i];
    memset(dep, 0x3f, (n + 1) << 2);
    dep[s] = 0;
    q.emplace_back(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(int i = hd[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if(e[i].cap && dep[v] > dep[u] + 1) {
                dep[v] = dep[u] + 1;
                q.emplace_back(v);
            }
        }
    }
    return dep[t] < inf;
}
int dfs(int u, int t, int in) {
    if(u == t || !in) return in;
    int flow = 0, f;
    for(int &i = cur[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(e[i].cap && dep[v] == dep[u] + 1 && (f = dfs(v, t, min(in, e[i].cap))) > 0) {
            e[i].cap -= f, e[i ^ 1].cap += f;
            in -= f;
            flow += f;
            if(!in) break;
        }
    }
    if(flow == 0) dep[u] = inf;
    return flow;
}
int dinic(int s, int t, int n) {
    int flow = 0;
    while(bfs(s, t, n)) flow += dfs(s, t, inf);
    return flow;
}
int n1, n2, m;
int U[N], V[N], mt = 0;
int arr[N][2];
void dfs(int u, int t) {
    if(arr[u][t] != -1) return;
    arr[u][t] = 1;
    for(int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(e[i ^ t].cap) {
            dfs(v, t);
        }
    }
    return;
}
map<pair<int, int>, int> id;
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    me(arr, -1);
    cin >> n1 >> n2 >> m >> q;
    FOR(i, 1, n1) add(1, i + 1, 1);
    FOR(i, 1, n2) add(n1 + i + 1, n1 + n2 + 2, 1);
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        add(u + 1, v + n1 + 1, 1);
        id[{u + 1, v + n1 + 1}] = i;
    }
    int cnt = dinic(1, n1 + n2 + 2, n1 + n2 + 2);
    FOR(i, 1, n1) {
        int u = i + 1;
        for(int i = hd[u]; i; i = e[i].nxt) {
            if(e[i].to == 1) continue;
            if(!e[i].cap) {
                U[++mt] = u;
                V[mt] = e[i].to;
            }
        }
    }
    dfs(1, 0);
    dfs(n1 + n2 + 2, 1);
    ll sum = 0;
    // FOR(i, 1, mt) cout << U[i] - 1 <<" " << V[i] - n1 - 1 << endl;
    FOR(i, 1, mt) sum += id[{U[i], V[i]}];
    FOR(i, 1, q) {
        int opt;
        cin >> opt;
        if(opt == 1) {
            cout << 1 << "\n";
            if(arr[U[mt]][1] == 1) cout << (U[mt] - 1) << "\n";
            else cout << - (V[mt] - n1 - 1) << "\n";
            sum -= id[{U[mt], V[mt]}];
            mt--;
            cout << sum << "\n";
        } else {
            cout << mt << "\n";
            FOR(j, 1, mt) cout << id[{U[j], V[j]}] << "\n";
        }
        cout.flush();
        // cout << endl;
    }
    return 0;
}