#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000 + 1;

int N;
int ds[maxn];
bool l[maxn];

struct edge
{
    int u, v, w;

    bool operator <(const edge &e) const{
        return w > e.w;
    }
};

init_ds(){
    memset(ds, -1, sizeof ds);
    memset(l, 0, sizeof l);
}

pair<int,bool> root(int a){
    bool p = 0;

    while (ds[a] >= 0){
        p ^= l[a];
        a = ds[a];
    }

    return {a, p};
}

int join(int u, int v){
    auto pu = root(u);
    auto pv = root(v);

    if (pu.first == pv.first) return pu.second == pv.second ? 2 : 1;

    if (ds[pu.first] > ds[pv.first]) swap(pu, pv);

    ds[pu.first] += ds[pv.first];
    ds[pv.first] = pu.first;

    if (pu.second == pv.second)
        l[pv.first] ^= 1;

    return 0;
}

bool valuable(vector<edge> &E){
    int pnt = 0, v = 0;

    init_ds();

    for (int i = 0; i < (int)E.size(); ++i){
        edge e = E[i];
        v = join(e.u, e.v);

        if (v == 1) continue;

        E[pnt++] = e;
        if (v == 2) break;
    }

    E.resize(pnt);

    return v < 2;
}

void merge(vector<edge> &E, vector<edge> &NEW, bool _sort=true){
    for (auto e : NEW) E.push_back(e);
    if (_sort) sort(E.begin(), E.end());
}

struct segment_tree{
    int n;
    vector<vector<edge>> st;

    segment_tree(vector<edge> E) : n(E.size()){
        st = vector<vector<edge>>(4 * n);
        build(1, 0, n, E);
    }

    void build(int p, int b, int e, vector<edge> &E){
        if (b + 1 == e) st[p] = {E[b]};
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;

            build(l, b, m, E);
            build(r, m, e, E);

            st[p] = st[l];
            merge(st[p], st[r]);

            valuable(st[p]);
        }
    }

    void query(int p, int b, int e, int x, int y, vector<edge> &E){
        if (x <= b && e <= y){
            merge(E, st[p], false);
        }
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            if (x < m) query(l, b, m, x, y, E);
            if (m < y) query(r, m, e, x, y, E);
        }
    }

    int query(int x, int y){
        vector<edge> E;

        query(1, 0, n, x, y, E);

        sort(E.begin(), E.end());

        bool bipartite = valuable(E);

        if (bipartite) return -1;
        else return E.back().w;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    N = n + 1;

    vector<edge> E(m);
    for (int i = 0; i < m; ++i)
        cin >> E[i].u >> E[i].v >> E[i].w;

    segment_tree st(E);

    for (int i = 0; i < q; ++i){
        int u, v; cin >> u >> v;
        cout << st.query(u - 1, v) << endl;
    }

    return 0;
}