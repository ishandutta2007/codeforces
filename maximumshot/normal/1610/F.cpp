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
    string s;

    void print() {
        cout << res << "\n" << s << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;

    struct Edge {
        int u, v, w;

        int get_to(int x) const {
            return u ^ v ^ x;
        }
    };

    vector<Edge> es;

    input() = default;

    void read() {
        cin >> n >> m;
        es.resize(m);
        for (auto& e : es) {
            cin >> e.u >> e.v >> e.w;
            e.u--, e.v--;
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
        vector<int> rev(m), par(m, -1);
        vector<set<int>> g[3];
        for (int w = 1; w <= 2; w++)
            g[w].resize(n);
        for (int i = 0; i < m; i++) {
            auto e = es[i];
            g[e.w][e.u].insert(i);
            g[e.w][e.v].insert(i);
        }
        queue<pii> q;
        for (int v = 0; v < n; v++) {
            for (int w = 1; w <= 2; w++) {
                if ((int) g[w][v].size() >= 2)
                    q.push({v, w});
            }
        }
        int mm = m;
        while (!q.empty()) {
            auto [v, w] = q.front();
            q.pop();
            if ((int) g[w][v].size() <= 1)
                continue;
            int e1 = *g[w][v].begin();
            int e2 = *next(g[w][v].begin());
            g[w][es[e1].u].erase(e1);
            g[w][es[e1].v].erase(e1);
            g[w][es[e2].u].erase(e2);
            g[w][es[e2].v].erase(e2);
            int ne = (int) es.size();
            rev.emplace_back(0);
            par.emplace_back(-1);
            int x = es[e1].get_to(v);
            int y = es[e2].get_to(v);
            es.push_back(Edge{x, y, w});
            m++;
            g[w][x].insert(ne);
            g[w][y].insert(ne);
            par[e1] = par[e2] = ne;
            rev[e1] = es[e1].u != x;
            rev[e2] = es[e2].v != y;
//            cout << "add " << x << " " << y << " " << w << "\n";
            for (int u : {v, x, y}) {
                if ((int) g[w][u].size() >= 2) {
                    q.push({u, w});
                }
            }
        }
        vector<int> res(m, -1);
        queue<int> que;
        vector<int> used(n);
        function<void(int)> dfs = [&](int v) {
            used[v] = 1;
            for (int w = 1; w <= 2; w++) {
                for (int eid: g[w][v]) {
                    auto e = es[eid];
                    int to = e.get_to(v);
                    if (!used[to]) {
                        res[eid] = e.u == v ? 0 : 1;
                        dfs(to);
                    } else if (res[eid] == -1) {
                        res[eid] = e.u == v ? 0 : 1;
                    }
                }
            }
        };
        used.assign(n, 0);
        for (int v = 0; v < n; v++) {
            if ((int) g[1][v].size() + (int) g[2][v].size() <= 1 && !used[v])
                dfs(v);
        }
        for (int v = 0; v < n; v++) {
            if (!used[v])
                dfs(v);
        }
        for (int i = m - 1; i >= 0; i--) {
            if (res[i] == -1)
                res[i] = res[par[i]] ^ rev[i];
        }
//        for (int i = 0; i < m; i++) {
//            auto e = es[i];
//            if (res[i]) swap(e.u, e.v);
//            cout << e.u + 1 << " -- " << e.w << " --> " << e.v + 1 << "\n";
//        }
        string s(mm, '?');
        for (int i = 0; i < mm; i++) {
            s[i] = res[i] ? '2' : '1';
        }
        vector<int> f(n);
        for (int i = 0; i < mm; i++) {
            auto e = es[i];
            if (s[i] == '2') swap(e.u, e.v);
            f[e.u] += e.w;
            f[e.v] -= e.w;
        }
        int tmp = 0;
        for (int v = 0; v < n; v++)
            tmp += abs(f[v]) == 1;
        return output{tmp, s};
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