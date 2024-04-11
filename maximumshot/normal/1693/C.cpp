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
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n, m;
    vector<pii> es;

    input() = default;

    void read() {
        cin >> n >> m;
        es.resize(m);
        for (auto& [u, v] : es)
            cin >> u >> v, u--, v--;
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto [u, v] : es)
            cout << u + 1 << " " << v + 1 << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        n = rnd() % MAXN + 2;
        {
            vector<int> perm(n - 2);
            iota(perm.begin(), perm.end(), 1);
            shuffle(perm.begin(), perm.end(), rnd);
            int l = rnd() % ((int) perm.size() + 1);
            perm.resize(l);
            if (l) {
                es.emplace_back(0, perm.front());
                for (int i = 1; i < (int) perm.size(); i++)
                    es.emplace_back(perm[i - 1], perm[i]);
                es.emplace_back(perm.back(), n - 1);
            } else {
                es.emplace_back(0, n - 1);
            }
        }
        int add = rnd() % (3 * n);
        for (int it = 0; it < add; it++) {
            int u = rnd() % (n - 1) + 1;
            int v = rnd() % u;
            if (rnd() % 2) swap(u, v);
            es.emplace_back(u, v);
        }
        m = (int) es.size();
    }

    void gen_max_test() {

    }

    output fast() {
        auto get_to = [&](int eid, int x) -> int {
            auto [u, v] = es[eid];
            return u ^ v ^ x;
        };
        vector<vector<int>> g(n), gr(n);
        for (int i = 0; i < m; i++) {
            auto [u, v] = es[i];
            g[u].push_back(i);
            gr[v].push_back(i);
        }
        vector<int> dist(n, inf);
        vector<set<int>> c(n);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[n - 1] = 0;
        pq.push({dist[n - 1], n - 1});
        for (int v = 0; v < n; v++) {
            for (int eid : g[v]) {
                int to = get_to(eid, v);
                if (dist[to] == inf)
                    c[v].insert(eid);
            }
        }
        while (!pq.empty()) {
            auto [D, v] = pq.top();
            pq.pop();
            if (dist[v] != D)
                continue;
            for (int eid : gr[v]) {
                int fr = get_to(eid, v);
                c[fr].erase(eid);
                int mn = dist[v] + (int) c[fr].size() + 1;
                if (dist[fr] > mn) {
                    dist[fr] = mn;
                    pq.push({dist[fr], fr});
                }
            }
        }
        return output{dist[0]};
    }

#ifdef DEBUG
    output slow() {
        int res = inf;
        for (int mask = 0; mask < (1 << m); mask++) {

        }
        return output{0};
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