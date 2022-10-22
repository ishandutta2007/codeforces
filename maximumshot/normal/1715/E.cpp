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
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct Line {
    ll k, b;
    int type;
    ld x;
    Line() : k(0), b(0), type(0), x(0) {}
    Line(ll _k, ll _b, ld _x = 1e18, int _type = 0)
            : k(_k), b(_b), x(_x), type(_type) {}
    bool operator<(const Line& other) const {
        if (type + other.type > 0) {
            return x < other.x;
        } else {
            return k < other.k;
        }
    }
    ld intersect(const Line& other) const {
        return ld(b - other.b) / ld(other.k - k);
    }
    ll get_func(ll x0) const { return k * x0 + b; }
};
struct CHT {
    set<Line> qs;
    set<Line>::iterator fnd, help;
    bool hasr(const set<Line>::iterator& it) {
        return it != qs.end() && next(it) != qs.end();
    }
    bool hasl(const set<Line>::iterator& it) {
        return it != qs.begin();
    }
    bool check(const set<Line>::iterator& it) {
        if (!hasr(it)) return true;
        if (!hasl(it)) return true;
        return it->intersect(*prev(it)) <
               it->intersect(*next(it));
    }
    void update_intersect(
            const set<Line>::iterator& it) {
        if (it == qs.end()) return;
        if (!hasr(it)) return;
        Line tmp = *it;
        tmp.x = tmp.intersect(*next(it));
        qs.insert(qs.erase(it), tmp);
    }
    void add_line(Line L) {
        if (qs.empty()) {
            qs.insert(L);
            return;
        }
        {
            fnd = qs.lower_bound(L);
            if (fnd != qs.end() && fnd->k == L.k) {
                if (fnd->b >= L.b)
                    return;
                else
                    qs.erase(fnd);
            }
        }
        fnd = qs.insert(L).first;
        if (!check(fnd)) {
            qs.erase(fnd);
            return;
        }
        while (hasr(fnd) &&
               !check(help = next(fnd))) {
            qs.erase(help);
        }
        while (hasl(fnd) &&
               !check(help = prev(fnd))) {
            qs.erase(help);
        }
        if (hasl(fnd)) {
            update_intersect(prev(fnd));
        }
        update_intersect(fnd);
    }
    ll get_max(ld x0) {
        if (qs.empty()) return -inf64;
        fnd = qs.lower_bound(Line(0, 0, x0, 1));
        if (fnd == qs.end()) fnd--;
        ll res = -inf64;
        int i = 0;
        while (i < 2 && fnd != qs.end()) {
            res = max(res, fnd->get_func(x0));
            fnd++;
            i++;
        }
        while (i-- > 0)
            fnd--;
        while (i < 2) {
            res = max(res, fnd->get_func(x0));
            if (hasl(fnd)) {
                fnd--;
                i++;
            } else {
                break;
            }
        }
        return res;
    }
};

struct input {
    int n, m, k;
    vector<tuple<int, int, int>> es;

    input() = default;

    void read() {
        cin >> n >> m >> k;
        es.resize(m);
        for (auto& [u, v, w] : es) {
            cin >> u >> v >> w;
            u--, v--;
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
        vector<vector<pii>> g(n);
        for (auto [u, v, w] : es) {
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        vector<ll> dist(n, inf64);
        dist[0] = 0;
        using pli = pair<long long, int>;
        priority_queue<pli, vector<pli>, greater<>> pq;
        pq.push({dist[0], 0});
        while (!pq.empty()) {
            auto [D, v] = pq.top();
            pq.pop();
            if (dist[v] != D) continue;
            for (auto [to, w] : g[v]) {
                if (dist[to] > dist[v] + w) {
                    dist[to] = dist[v] + w;
                    pq.push({dist[to], to});
                }
            }
        }
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&](int i, int j) {
            return dist[i] < dist[j];
        });
        vector<ll> res = dist;
        for (int it = 0; it <= k; it++) {
            vector<ll> dp(n, inf64);
            if (it < k) {
                CHT cht;
                for (int j = 0; j < n; j++) {
                    int u = perm[j];
                    cht.add_line(Line(2ll * u, -res[u] - 1ll * u * u));
                }
                for (int v = 0; v < n; v++) {
                    ll tmp = -cht.get_max(v) + 1ll * v * v;
                    dp[v] = min(dp[v], tmp);
                }
                for (int v = 0; v < n; v++)
                    res[v] = min(res[v], dp[v]);
            }
            while (!pq.empty()) pq.pop();
            for (int v = 0; v < n; v++) pq.push({res[v], v});
            while (!pq.empty()) {
                auto [D, v] = pq.top();
                pq.pop();
                for (auto [to, w] : g[v]) {
                    if (res[to] > res[v] + w) {
                        res[to] = res[v] + w;
                        pq.push({res[to], to});
                    }
                }
            }
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return output();
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

#ifdef DEBUG
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
#endif

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

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