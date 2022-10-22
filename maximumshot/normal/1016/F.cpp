#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 3e5 + 5;

int n, m;
vec< int > g[N];
int we[N];
pii edge[N];
int mark[N];

inline int get_to(int id, int v) {
    return edge[id].first == v ? edge[id].second : edge[id].first;
}

pair< vec< int >, vec< int > > get_shortest_path() {
    vec< int > dist(n + 1, inf), from(n + 1);
    queue< int > q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int id : g[v]) {
            int to = get_to(id, v);
            if(dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = id;
                q.push(to);
            }
        }
    }
    vec< int > vs;
    for(int v = n;v > 1;v = get_to(from[v], v)) vs.push_back(v), mark[v] = 1;
    vs.push_back(1);
    mark[1] = 1;
    vec< int > eds;
    for(int v = n;v > 1;v = get_to(from[v], v)) eds.push_back(from[v]);
    reverse(ALL(vs));
    reverse(ALL(eds));
    return make_pair(vs, eds);
}

int go(int v, int par = -1) {
    int res = 1;
    for(int id : g[v]) {
        int to = get_to(id, v);
        if(mark[to] || to == par) continue;
        res += go(to, v);
    }
    return res;
}

int get_we(int v) {
    for(int id : g[v]) {
        int to = get_to(id, v);
        if(!mark[to]) {
            return we[id];
        }
    }
    return inf;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i < n;i++) {
        scanf("%d %d %d", &edge[i].first, &edge[i].second, &we[i]);
        g[edge[i].first].push_back(i);
        g[edge[i].second].push_back(i);
    }

    vec< int > vs, eds;
    tie(vs, eds) = get_shortest_path();

    ll LEN = 0;

    for(int ed : eds) LEN += we[ed];

    for(int v : vs) {
        if(go(v) > 2) {
            for(int it = 0;it < m;it++) {
                printf("%lld\n", LEN);
            }
            return 0;
        }
    }

    vec< ll > pref((int)vs.size()), suff((int)vs.size());

    {
        ll acc = 0;
        for(int i = 0;i < (int)vs.size();i++) {
            pref[i] = acc;
            if(i < (int)eds.size()) acc += we[eds[i]];
        }
    }

    {
        ll acc = 0;
        for(int i = (int)vs.size() - 1;i >= 0;i--) {
            suff[i] = acc;
            if(i) acc += we[eds[i - 1]];
        }
    }

    int last = -1;

    ll mn = LLONG_MAX;
    ll mx = LLONG_MIN;

    for(int i = 0;i < (int)vs.size();i++) {
        int v = vs[i];
        if(go(v) > 1) {
            if(last != -1) {
                int u = vs[last];
                mn = min(mn, pref[i] - pref[last] - get_we(u) - get_we(v));
                mx = max(mx, pref[last] + get_we(v) + get_we(u) + suff[i]);
            }
            if(i > 0) {
                int W1 = we[eds[i - 1]];
                int W2 = get_we(v);
                mn = min(mn, 0ll + W1 - W2);
                mx = max(mx, pref[i - 1] + W2 + suff[i]);
            }
            if(i + 1 < (int)vs.size()) {
                int W1 = we[eds[i]];
                int W2 = get_we(v);
                mn = min(mn, 0ll + W1 - W2);
                mx = max(mx, pref[i] + W2 + suff[i + 1]);
            }
            last = i;
        }
        if(0 < i && i + 1 < (int)vs.size()) {
            int W = we[eds[i - 1]] + we[eds[i]];
            mn = min(mn, 0ll + W);
            mx = max(mx, pref[i - 1] + suff[i + 1]);
        }
    }

    for(int i = 0;i < m;i++) {
        int x;
        scanf("%d", &x);
        if(x < mn) {
            printf("%lld\n", mx + x);
        }else {
            printf("%lld\n", LEN);
        }
    }

    return 0;
}