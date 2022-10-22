#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e4 + 5;

int n, k;
int s[N];
int t[N];
int c[N];
int sz;
vec< pair< pii, pii > > edge;
vec< int > crd;
int S, T;
vec< int > g[N];
int problem[N];
int dist[N];
int flow[N];
int from[N];

void addEdge(int u, int v, int capacity, int cost) {
    g[u].push_back((int)edge.size());
    edge.push_back(make_pair(make_pair(u, v), make_pair(capacity, cost)));
}

void buildNet() {
    for(int i = 0;i + 1 < sz;i++) {
        addEdge(i, i + 1, k, 0);
        addEdge(i + 1, i, 0, 0);
    }
    for(int l, r, i = 1;i <= n;i++) {
        l = lower_bound(ALL(crd), s[i]) - crd.begin();
        r = lower_bound(ALL(crd), s[i] + t[i]) - crd.begin();
        problem[i] = (int)edge.size();
        addEdge(l, r, 1, -c[i]);
        addEdge(r, l, 0, +c[i]);
    }
    S = sz;
    T = sz + 1;
    addEdge(S, 0, k, 0);
    addEdge(0, S, 0, 0);
    addEdge(sz - 1, T, k, 0);
    addEdge(T, sz - 1, 0, 0);
}

int push() {
    for(int i = 0;i < sz + 2;i++) {
        dist[i] = inf + 5;
        from[i] = -1;
    }
    dist[S] = 0;
    for(int change, iter = 0;iter < sz + 1;iter++) {
        change = 0;
        for(int u, v, it = 0;it < (int)edge.size();it++) {
            if(flow[it] < edge[it].second.first) {
                tie(u, v) = edge[it].first;
                if(dist[v] > dist[u] + edge[it].second.second) {
                    dist[v] = dist[u] + edge[it].second.second;
                    from[v] = it;
                    change = 1;
                }
            }
        }
        if(!change) break;
    }
    if(dist[T] == inf + 5) return 0;
    int mn = inf;
    for(int id, v, u = T;u != S;) {
        id = from[u];
        v = edge[id].first.first == u ? edge[id].first.second : edge[id].first.first;
        mn = min(mn, edge[id].second.first - flow[id]);
        u = v;
    }
    if(mn == 0) return 0;
    for(int id, v, u = T;u != S;) {
        id = from[u];
        v = edge[id].first.first == u ? edge[id].first.second : edge[id].first.first;
        flow[id] += mn;
        flow[id ^ 1] -= mn;
        u = v;
    }
    return 1;
}

void MCMF() {
    while(push());
}

int main() {

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d %d", &s[i], &t[i], &c[i]);
        crd.push_back(s[i]);
        crd.push_back(s[i] + t[i]);
    }

    sort(ALL(crd));
    crd.resize(sz = unique(ALL(crd)) - crd.begin());

    buildNet();
    MCMF();

    for(int i = 1;i <= n;i++) {
        printf("%d ", flow[problem[i]]);
    }
    printf("\n");

    return 0;
}