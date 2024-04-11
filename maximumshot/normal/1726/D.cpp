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
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;

    struct Edge {
        int u, v;

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
            cin >> e.u >> e.v;
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
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            auto e = es[i];
            g[e.u].push_back(i);
            g[e.v].push_back(i);
        }
        vector<int> used(n), used_e(m);
        function<void(int)> dfs = [&](int v) {
            used[v] = 1;
            for (int eid : g[v]) {
                auto e = es[eid];
                int to = e.get_to(v);
                if (used[to]) continue;
                dfs(to);
                used_e[eid] = 1;
            }
        };
        dfs(0);
        int rem = -1;
        {
            set<int> Q;
            int cnt = 0, last = -1;
            for (int i = 0; i < m; i++) {
                if (used_e[i]) continue;
                auto e = es[i];
                cnt++;
                Q.insert(e.u);
                Q.insert(e.v);
                last = i;
            }
            if (cnt == 3 && (int) Q.size() == 3)
                rem = last;
        }
        if (rem != -1) {
            auto get_any_edge_on_path = [&](int s, int t) -> int {
                assert(s != t);
                vector<int> dist(n, inf), from(n, -1);
                dist[s] = 0;
                queue<int> q;
                q.push(s);
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int eid : g[v]) {
                        if (!used_e[eid]) continue;
                        auto e = es[eid];
                        int to = e.get_to(v);
                        if (dist[to] > dist[v] + 1) {
                            dist[to] = dist[v] + 1;
                            from[to] = eid;
                            q.push(to);
                        }
                    }
                }
                return from[t];
            };
            int rem2 = get_any_edge_on_path(es[rem].u, es[rem].v);
            used_e[rem] ^= 1;
            used_e[rem2] ^= 1;
        }
        string res(m, '?');
        for (int i = 0; i < m; i++)
            res[i] = used_e[i] + '0';
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
    cin >> t;
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