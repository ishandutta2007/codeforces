#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct DSU {
    int n = 0; // [0, n)
    vector<int> p, sz;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.resize(n); iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }
};

struct Query {
    int t = 0; // 0 = block, 1 = ask
    ll x = 0;
    ll y = 0;
};

vector<int> slow(int n, int m, vector<Query> queries) {
    vector<int> res;
    vector<int> blocked(1 << n);
    for (auto query : queries) {
        if (query.t == 0) {
            for (int i = query.x; i <= query.y; i++)
                blocked[i] = 1;
        } else {
            vector<int> vis(1 << n);
            vis[query.x] = 1;
            queue<int> q;
            q.push(query.x);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {
                    int to = v ^ (1 << i);
                    if (blocked[to] || vis[to])
                        continue;
                    vis[to] = 1;
                    q.push(to);
                }
            }
            res.push_back(vis[query.y]);
        }
    }
    return res;
}

const int MAXN = int(5e4 + 5) * int(55);

vector<int> fast(int n, int m, vector<Query> queries) {
    vector<ll> cuts = {0ll, 1ll << n};
    for (auto query : queries) {
        if (query.t == 0) {
            cuts.push_back(query.x);
            cuts.push_back(query.y + 1);
        }
    }
    sort(cuts.begin(), cuts.end());
    cuts.erase(unique(cuts.begin(), cuts.end()), cuts.end());
//    vector<pll> V;
//    vector<vector<int>> g;
    pll V[MAXN];
    vector<int> g[MAXN];
    int Vsz = 0;
    function<void(ll, ll, vector<pll>)> build = [&](ll l, ll r, vector<pll> segs) {
        if (segs.empty()) {
            return;
        }
        for (auto [ql, qr] : segs) {
            if (ql == l && qr == r) {
                V[Vsz++] = {l, r};
                return;
            }
        }
        vector<pll> lsegs, rsegs;
        ll mid = (l + r) >> 1;
        for (auto [ql, qr] : segs) {
            if (qr <= mid) lsegs.emplace_back(ql, qr);
            else if (ql > mid) rsegs.emplace_back(ql, qr);
            else {
                lsegs.emplace_back(ql, mid);
                rsegs.emplace_back(mid + 1, qr);
            }
        }
        int sz = Vsz;
        build(l, mid, lsegs);
        int ls = Vsz - sz;
        build(mid + 1, r, rsegs);
        int rs = Vsz - sz - ls;
        ll k = (r - l + 1) / 2;
        for (int tl = 0, tr = 0, i = 0; i < ls; i++) {
            while (tr < rs && V[sz + ls + tr].first - k <= V[sz + i].second) tr++;
            while (tl < rs && V[sz + ls + tl].second - k < V[sz + i].first) tl++;
            for (int j = tl; j < tr; j++) {
                int u = sz + i;
                int v = sz + ls + j;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    };
    vector<pll> segs;
    for (int i = 0; i + 1 < (int) cuts.size(); i++)
        segs.emplace_back(cuts[i], cuts[i + 1] - 1);
    build(0, (1ll << n) - 1, segs);
    vector<vector<int>> to_del(m);
    {
        set<pair<ll, int>> Q;
        for (int i = 0; i < Vsz; i++)
            Q.insert({V[i].first, i});
        for (int i = 0; i < m; i++) {
            auto query = queries[i];
            if (query.t == 0) {
                for (auto it = Q.lower_bound({query.x, -1}); it != Q.end() && it->first <= query.y;) {
                    to_del[i].push_back(it->second);
                    it = Q.erase(it);
                }
            }
        }
    }
    vector<int> blocked(Vsz);
    vector<int> res;
    for (int i = 0; i < m; i++) {
        auto query = queries[i];
        if (query.t == 0) {
            for (int v : to_del[i])
                blocked[v] = 1;
        }
    }
    DSU dsu(Vsz);
    auto add_vertex = [&](int v) {
        for (int to : g[v]) {
            if (!blocked[to])
                dsu.merge(v, to);
        }
    };
    for (int v = 0; v < Vsz; v++) {
        if (blocked[v])
            continue;
        add_vertex(v);
    }
    for (int i = m - 1; i >= 0; i--) {
        auto query = queries[i];
        if (query.t == 0) {
            for (int v : to_del[i]) blocked[v] = 0;
            for (int v : to_del[i]) add_vertex(v);
        } else {
            int vx = upper_bound(V, V + Vsz, make_pair(query.x, inf64)) - V - 1;
            int vy = upper_bound(V, V + Vsz, make_pair(query.y, inf64)) - V - 1;
            res.push_back(dsu.find(vx) == dsu.find(vy));
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 13;
    const int MAXM = 1e3;
    while (1) {
        int n = rnd() % MAXN + 1;
        int m = rnd() % MAXM + 1;
        vector<Query> queries(m);
        vector<int> blocked(1 << n);
        for (auto& query : queries) {
            vector<int> free;
            for (int v = 0; v < (1 << n); v++) {
                if (!blocked[v])
                    free.push_back(v);
            }
            if (free.empty()) {
                query.t = 0;
            } else {
                query.t = rnd() % 2;
            }
            if (query.t == 0) {
                query.x = rnd() % (1 << n);
                query.y = rnd() % (1 << n);
                if (query.x > query.y)
                    swap(query.x, query.y);
                for (int i = query.x; i <= query.y; i++)
                    blocked[i] = 1;
            } else {
                query.x = free[rnd() % (int) free.size()];
                query.y = free[rnd() % (int) free.size()];
            }
        }
        vector<int> fs = fast(n, m, queries);
        vector<int> sl = slow(n, m, queries);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n";
            cout << n << " " << m << "\n";
            vector<string> types = {"block", "ask"};
            for (auto query : queries)
                cout << types[query.t] << " " << query.x << " " << query.y << "\n";
            cout.flush();
            break;
        }
    }
}

struct Node {
    Node* l = nullptr;
    Node* r = nullptr;
    int pu = 0;
};

void zero(Node*& v) {
    if (!v) v = new Node();
    v->pu = 1;
}

void push(Node* v) {
    if (!v) return;
    if (v->pu) {
        zero(v->l);
        zero(v->r);
        v->pu = 0;
    }
}

void update(Node*& v, ll tl, ll tr, ll l, ll r) {
    if (!v) v = new Node();
    if (l <= tl && tr <= r) {
        zero(v);
    } else {
        ll tm = (tl + tr) >> 1;
        push(v);
        if (l <= tm) update(v->l, tl, tm, l, r);
        if (r > tm) update(v->r, tm + 1, tr, l, r);
    }
}

int get(Node* v, ll tl, ll tr, ll pos) {
    if (!v) return 0;
    if (v->pu) return 1;
    if (tl == tr) {
        return 0;
    } else {
        ll tm = (tl + tr) >> 1;
        push(v);
        if (pos <= tm) return get(v->l, tl, tm, pos);
        else return get(v->r, tm + 1, tr, pos);
    }
}

void max_test() {
    mt19937_64 rnd(42);
    int n = 50;
    int m = 5e4;
    vector<Query> queries(m);
    Node* root = nullptr;
    for (auto& query : queries) {
        query.t = rnd() % 2;
        if (query.t == 1) {
            for (int it = 0; it < 100; it++) {
                query.x = rnd() % (1ll << n);
                if (!get(root, 0ll, (1ll << n) - 1, query.x)) break;
                else query.x = -1;
            }
            for (int it = 0; it < 100; it++) {
                query.y = rnd() % (1ll << n);
                if (!get(root, 0ll, (1ll << n) - 1, query.y)) break;
                else query.y = -1;
            }
            if (query.x == -1 || query.y == -1) query.t = 0;
        }
        if (query.t == 0) {
            query.x = rnd() % (1ll << n);
            ll len = min(ll(1e6), (1ll << n) - query.x);
            query.y = query.x + rnd() % len;
            if (query.x > query.y) swap(query.x, query.y);
            update(root, 0ll, (1ll << n) - 1, query.x, query.y);
        }
    }
    cout << n << " " << m << "\n";
    vector<string> types = {"block", "ask"};
    for (auto query : queries)
        cout << types[query.t] << " " << query.x << " " << query.y << "\n";
}

void work() {
    int n, m;
    cin >> n >> m;
    vector<Query> queries(m);
    for (auto& query : queries) {
        string s;
        cin >> s;
        if (s == "ask") query.t = 1;
        else query.t = 0;
        cin >> query.x >> query.y;
    }
    vector<int> res = fast(n, m, queries);
    for (auto x : res)
        cout << x << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

#ifdef MAX_TEST
    max_test();
#else
    work();
//    test();
#endif

    return 0;
}