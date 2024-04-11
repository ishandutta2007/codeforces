#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const MAXN = 3005;

int n;
int a[MAXN];
int N, S, T;
vec< pii > g[MAXN * 2];
// {to, {cap, cost}}

vec< int > cp, fl, co;
vec< pii > ed;

inline int getTo(int id, int v) {
    return ed[id].first == v ? ed[id].second : ed[id].first;
}

inline void addEdge(int u, int v, int capacity, int cost) {
    cp.push_back(capacity);
    fl.push_back(0);
    co.push_back(cost);
    g[u].push_back(make_pair(v, (int)cp.size() - 1));
    ed.push_back(make_pair(u, v));
}

int phi[MAXN * 2];
bool used[MAXN * 2];

int dfs(int v) {
    if(used[v]) return phi[v];
    used[v] = 1;
    int mn = INT_MAX;
    for(pii iter : g[v]) {
        int to, id;
        tie(to, id) = iter;
        if(id % 2 == 0) continue;
        mn = min(mn, dfs(to) + co[id ^ 1]);
    }
    return phi[v] = mn;
}

int dist[MAXN * 2];
int from[MAXN * 2];
set< pii > pq;

pii dkstra() {
    for(int i = 1;i <= N;i++) {
        dist[i] = inf;
        from[i] = -1;
    }
    dist[S] = 0;
    pq.insert(make_pair(dist[S], S));
    while(!pq.empty()) {
        int v = pq.begin()->second;
        pq.erase(pq.begin());
        for(pii iter : g[v]) {
            int to, id;
            tie(to, id) = iter;
            int we = co[id] + phi[v] - phi[to];
            if(fl[id] < cp[id]) {
                if(dist[to] > dist[v] + we) {
                    pq.erase(make_pair(dist[to], to));
                    dist[to] = dist[v] + we;
                    from[to] = id;
                    pq.insert(make_pair(dist[to], to));
                }
            }
        }
    }
    int afl = 0;
    int ale = 0;
    if(dist[T] != inf) {
        int mn = inf;
        for(int u = T;u != S;u = getTo(from[u], u)) {
            mn = min(mn, cp[from[u]] - fl[from[u]]);
        }
        afl = mn;
        for(int u = T;u != S;u = getTo(from[u], u)) {
            ale += mn * co[from[u]];
            fl[from[u]] += mn;
            fl[from[u] ^ 1] -= mn;
        }
        for(int i = 1;i <= N;i++) {
            phi[i] += dist[i];
        }
    }
    return make_pair(afl, ale);
}

void mcmf() {
    phi[S] = 0;
    used[S] = 1;
    dfs(T);
    int res = 0;
    pii add;
    int len = 0;
    while(res < 4) {
        add = dkstra();
        if(add.first == 0) break;
        res += add.first;
        len += add.second;
    }
    printf("%d\n", len >= 0 ? len : -len);
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    N = 2 * n + 2;
    S = 2 * n + 1;
    T = 2 * n + 2;

    for(int i = 1;i <= n;i++) {
        addEdge(S, i, 1, 0);
        addEdge(i, S, 0, 0);
        addEdge(i + n, T, 1, 0);
        addEdge(T, i + n, 0, 0);
        addEdge(i, i + n, 1, -1);
        addEdge(i + n, i, 0, +1);
    }

    for(int i = 1;i <= n;i++) {
        for(int j = i + 1;j <= n;j++) {
            if(abs(a[i] - a[j]) == 1 || a[i] % 7 == a[j] % 7) {
                addEdge(i + n, j, 1, 0);
                addEdge(j, i + n, 0, 0);
            }
        }
    }

    mcmf();

    return 0;
}