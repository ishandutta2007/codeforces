#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

struct MCMF {
    struct Edge { int fr, to, cp, fl, cs, id; };
    int n, S, T;
    vec< Edge > es;
    vec< vec< int > > g;
    vec< ll > dist, phi;
    vec< int > from;
    MCMF(int _n, int _S, int _T): n(_n), S(_S), T(_T)
    { g.resize(n); }
    void add_edge(int fr, int to, int cp, int cs, int id) {
//        cout << fr << " " << to << " " << cp << " " << cs << "\n";
        g[fr].push_back((int)es.size());
        es.push_back({fr, to, cp, 0, cs, id});
        g[to].push_back((int)es.size());
        es.push_back({to, fr, 0, 0, -cs, -1});
    }
    void init_phi() {
        dist.assign(n, LLONG_MAX);
        dist[S] = 0;
        for(int any, iter = 0;iter < n - 1;iter++) { // Ford Bellman
            any = 0;
            for(Edge e : es) {
                if(e.fl == e.cp) continue;
                if(dist[e.to] - dist[e.fr] > e.cs) {
                    dist[e.to] = dist[e.fr] + e.cs;
                    any = 1;
                }
            }
            if(!any) break;
        }
        phi = dist;
    }
    bool Dijkstra() {
        dist.assign(n, LLONG_MAX);
        from.assign(n, -1);
        dist[S] = 0;
        priority_queue< pair< ll, int >, vec< pair< ll, int > >,
                greater< pair< ll, int > > > pq;
        pq.push({dist[S], S});
        while(!pq.empty()) {
            int v;
            ll di;
            tie(di, v) = pq.top();
            pq.pop();
            if(di != dist[v]) continue;
            for(int ps : g[v]) {
                Edge &e = es[ps];
                if(e.fl == e.cp) continue;
                if(dist[e.to] - dist[e.fr] > e.cs + phi[e.fr] - phi[e.to]) {
                    dist[e.to] = dist[e.fr] + e.cs + phi[e.fr] - phi[e.to];
                    from[e.to] = ps;
                    pq.push({dist[e.to], e.to});
                }
            }
        }
        for(int v = 0;v < n;v++) {
            phi[v] += dist[v];
        }
        return dist[T] < LLONG_MAX;
    }
    pll find_mcmf() {
        init_phi();
        ll flow = 0, cost = 0;
        while(Dijkstra()) {
            int mn = INT_MAX;
            for(int v = T;v != S;v = es[ from[v] ].fr) {
                mn = min(mn, es[from[v]].cp - es[from[v]].fl);
            }
            flow += mn;
            for(int v = T;v != S;v = es[ from[v] ].fr) {
                es[ from[v] ].fl += mn;
                es[ from[v] ^ 1 ].fl -= mn;
            }
        }
        for(Edge &e : es) {
            if(e.fl >= 0) {
                cost += 1ll * e.fl * e.cs;
//                cout << e.fr << " -> " << e.to << " fl = " << e.fl << "\n";
            }
        }
        return make_pair(flow, cost);
    }
    bool go(int v, vec< int > &F, vec< int > &path, vec< int > &used) {
        if(used[v]) return 0;
        used[v] = 1;
        if(v == T) return 1;
        for(int ps : g[v]) {
            if(F[ps] <= 0) continue;
            if(go(es[ps].to, F, path, used)) {
                path.push_back(ps);
                return 1;
            }
        }
        return 0;
    }
    vec< pair< int, vec< int > > > decomposition(ll &_flow, ll &_cost) {
        tie(_flow, _cost) = find_mcmf();
        vec< int > F((int)es.size()), path, add, used(n);
        vec< pair< int, vec< int > > > dcmp;
        for(int i = 0;i < (int)es.size();i++) F[i] = es[i].fl;
        while(go(S, F, path, used)) {
            used.assign(n, 0);
            int mn = INT_MAX;
            for(int ps : path) mn = min(mn, F[ps]);
            for(int ps : path) F[ps] -= mn;
            for(int ps : path) add.push_back(es[ps].id);
            reverse(ALL(add));
            dcmp.emplace_back(mn, add);
            add.clear();
            path.clear();
        }
        return dcmp;
    }
};

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<pii, pii>> rec(m);
    vector<int> cx, cy;

    cx.push_back(0);
    cx.push_back(n + 1);
    cy.push_back(0);
    cy.push_back(n + 1);

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cx.push_back(x1);
        cx.push_back(x2 + 1);
        cy.push_back(y1);
        cy.push_back(y2 + 1);
        rec[i] = {{x1, y1}, {x2, y2}};
    }

    sort(cx.begin(), cx.end());
    cx.resize(unique(cx.begin(), cx.end()) - cx.begin());
    sort(cy.begin(), cy.end());
    cy.resize(unique(cy.begin(), cy.end()) - cy.begin());

    int sx = (int) cx.size();
    int sy = (int) cy.size();

    int sz = sx - 1 + sy - 1 + 2;
    int S = sz - 1;
    int T = sz - 2;

    MCMF mcmf(sz, S, T);

    for (int i = 0; i + 1 < sx; i++) {
        mcmf.add_edge(S, i, cx[i + 1] - cx[i], 0, 0);
    }

    for (int i = 0; i + 1 < sy; i++) {
        mcmf.add_edge(sx - 1 + i, T, cy[i + 1] - cy[i], 0, 0);
    }

    for (int it = 0; it < m; it++) {
        int x1, y1, x2, y2;
        tie(x1, y1) = rec[it].first;
        tie(x2, y2) = rec[it].second;

        int lx = lower_bound(cx.begin(), cx.end(), x1) - cx.begin();
        int rx = lower_bound(cx.begin(), cx.end(), x2 + 1) - cx.begin();
        int ly = lower_bound(cy.begin(), cy.end(), y1) - cy.begin();
        int ry = lower_bound(cy.begin(), cy.end(), y2 + 1) - cy.begin();

        for (int i = lx; i < rx; i++) {
            for (int j = ly; j < ry; j++) {
                mcmf.add_edge(i, sx - 1 + j, inf, 0, 0);
            }
        }
    }

    pll hlp = mcmf.find_mcmf();

    cout << hlp.first << "\n";
//    cout << hlp.second << "\n";

    return 0;
}