#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    int can = 0;
    ll res;

    void print() {
        if (can) {
            cout << res << "\n";
        } else {
            cout << "NO ESCAPE\n";
        }
    }

    bool operator == (const output& o) const {
        return can == o.can && res == o.res;
    }
};

void upd(ll& x, ll y) {
    if (x > y)
        x = y;
}

struct input {
    int n, m, k;
    vector<int> xs;
    vector<tuple<pii, pii, int>> edges;

    input() = default;

    void read() {
        cin >> n >> m >> k;
        xs.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> xs[i];
        edges.resize(k);
        for (auto& [u, v, w] : edges) {
            cin >> u.first >> u.second >> v.first >> v.second >> w;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<pii> crd = {{1, 1}, {n, m}};
        for (auto [u, v, w] : edges) {
            crd.push_back(u);
            crd.push_back(v);
        }
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        int V = (int) crd.size();
        vector<vector<pair<int, ll>>> g(V);
        for (auto [u, v, w] : edges) {
            int x = lower_bound(crd.begin(), crd.end(), u) - crd.begin();
            int y = lower_bound(crd.begin(), crd.end(), v) - crd.begin();
            g[x].emplace_back(y, -w);
        }
        int st = 0, fn = V - 1;
        vector<ll> dist(V, inf64), hlp(V, inf64);
        dist[st] = 0;
        for (int i = 0; i < V; i++) {
            int j = i;
            while (j < V && crd[i].first == crd[j].first) j++; j--;
            // [i, j]
            ll best = inf64;
            for (int q = i; q <= j; q++) {
                upd(best, dist[q] - 1ll * xs[crd[i].first] * crd[q].second);
                upd(hlp[q], 1ll * xs[crd[i].first] * crd[q].second + best);
//                for (int p = i; p <= q; p++) {
//                    upd(hlp[q], dist[p] + 1ll * xs[crd[i].first] * (crd[q].second - crd[p].second));
//                }
            }
            best = inf64;
            for (int q = j; q >= i; q--) {
                upd(best, dist[q] + 1ll * xs[crd[i].first] * crd[q].second);
                upd(hlp[q], 1ll * xs[crd[i].first] * -crd[q].second + best);
//                for (int p = q; p <= j; p++) {
//                    upd(hlp[q], dist[p] + 1ll * xs[crd[i].first] * (crd[p].second - crd[q].second));
//                }
            }
            for (int q = i; q <= j; q++) {
                upd(dist[q], hlp[q]);
                for (auto [to, w] : g[q]) {
                    upd(dist[to], dist[q] + w);
                }
            }
            i = j;
        }
        if (dist[fn] > inf64 / 2)
            return output{0, 0};
        else
            return output{1, dist[fn]};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        return output();
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}