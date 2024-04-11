#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
#define SET(p,n) memset(p, n, sizeof (p))

const int INF = INT_MAX;
const int MN = 205, ME = 205*205;

int src, snk, nno, ned;
int q[MN], fin[MN], pro[MN], dist[MN];
int flow[2*ME], cap[2*ME];
int sig[2*ME], to[2*ME];

inline void init (int _src, int _snk, int _n) {
    src = _src, snk = _snk, nno = _n, ned = 0;
    SET(fin, -1);
}

inline void add (int u, int v, int c) {
    to[ned] = v, cap[ned] = c, flow[ned] = 0, sig[ned] = fin[u], fin[u] = ned++;
    to[ned] = u, cap[ned] = 0, flow[ned] = 0, sig[ned] = fin[v], fin[v] = ned++;
}

inline void reset (int _src, int _snk) {
    src = _src, snk = _snk;
    for (int i = 0; i < ned; i++)
        flow[i] = 0;
}

bool bfs () {
    int st, en, u, v;
    SET(dist, -1);

    dist[src] = st = en = 0;
    q[en++] = src;

    while (st < en) {
        u = q[st++];

        for (int e = fin[u]; e >= 0; e = sig[e]) {
            v = to[e];

            if (flow[e] < cap[e] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q[en++] = v;
            }
        }
    }

    return dist[snk] != -1;
}

int dfs (int u, int mn) {
    if (u == snk)
        return mn;

    int au, v;
    for (int &e = pro[u]; e >= 0; e = sig[e]) {
        v = to[e];

        if (flow[e] < cap[e] && dist[v] == dist[u]+1)
            if (au = dfs(v, min(mn, cap[e] - flow[e]))) {
                flow[e] += au;
                flow[e^1] -= au;
                return au;
            }
    }

    return 0;
}

int dinitz () {
    int f = 0;
    int au;

    while (bfs()) {
        for (int i = 0; i <= nno; i++)
            pro[i] = fin[i];

        while (au = dfs(src, INF))
            f += au;
    }

    return f;
}

const int MX = 200005;
bitset<MX> bs;

void criba () {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MX; i++)
        if (bs[i])
            for (ll j = i * i; j < MX; j += i)
                bs[j] = 0;
}

int n, k, p[105], c[105], l[105];
vii par, imp;

int obtRes (int m) {
    int sum = 0;
    init (0, MN-1, MN-1);
    par.clear(), imp.clear();

    for (int i = 0; i < n; i++) {
        if (c[i] == 1 && l[i] <= m) {
            if (imp.empty())
                imp.emplace_back(1, p[i]);
            else
                imp[0].se = max(imp[0].se, p[i]);
        }
    }

    if (imp.size()) {
        add(0, 1, imp[0].se);
        sum += imp[0].se;
    }

    for (int i = 0; i < n; i++) {
        if (c[i] > 1 && l[i] <= m) {
            if (c[i] % 2) {
                add(0, 1 + imp.size(), p[i]);
                imp.emplace_back(c[i], p[i]);
            } else {
                add(101 + par.size(), MN-1, p[i]);
                par.emplace_back(c[i], p[i]);
            }
            sum += p[i];
        }
    }

    for (int i = 0; i < imp.size(); i++)
        for (int j = 0; j < par.size(); j++)
            if (bs[imp[i].fi + par[j].fi])
                add(1 + i, 101 + j, 1e9);

    return sum - dinitz();
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    criba();

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i] >> c[i] >> l[i];

    for (int i = 1; i <= 100; i++) {
        if (obtRes(i) >= k) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}