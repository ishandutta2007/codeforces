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

struct input {
    int n, m;
    vector<tuple<int, int, int>> es;

    input() = default;

    void read() {
        cin >> n >> m;
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
        vector<vector<pii>> g(n), gr(n);
        for (auto [u, v, w] : es) {
            g[u].emplace_back(v, w);
            gr[v].emplace_back(u, w);
        }
        vector<ll> d1(n, inf64), d2(n, inf64);
        using pli = pair<long long, int>;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        d1[0] = 0;
        pq.push({d1[0], 0});
        while (!pq.empty()) {
            auto [D, v] = pq.top();
            pq.pop();
            if (D != d1[v]) continue;
            for (auto [to, w] : g[v]) {
                if (d1[to] > d1[v] + w) {
                    d1[to] = d1[v] + w;
                    pq.push({d1[to], to});
                }
            }
        }
        for (int v = 0; v < n; v++) {
            if (d1[v] != inf64) {
                d2[v] = d1[v];
                pq.push({d2[v], v});
            }
        }
        while (!pq.empty()) {
            auto [D, v] = pq.top();
            pq.pop();
            if (D != d2[v]) continue;
            for (auto [fr, w] : gr[v]) {
                if (d2[fr] > d2[v] + w) {
                    d2[fr] = d2[v] + w;
                    pq.push({d2[fr], fr});
                }
            }
        }
        vector<ll> res;
        res.reserve(n - 1);
        for (int v = 1; v < n; v++)
            res.push_back(d2[v] == inf64 ? -1 : d2[v]);
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