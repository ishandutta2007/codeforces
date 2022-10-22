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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n;
    vector<int> c, p, d, S;
    vector<vector<int>> g;

    input() = default;

    void read() {
        cin >> n;
        c.resize(n);
        for (auto& x : c)
            cin >> x;
        g.resize(n);
        for (int u, v, i = 0; i < n - 1; i++) {
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    void print() {
        cout << n << "\n";
        for (auto x : c)
            cout << x << " ";
        cout << "\n";
        for (int v = 0; v < n; v++) {
            for (int to : g[v]) {
                if (v < to)
                    cout << v + 1 << " " << to + 1 << "\n";
            }
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 50;
        n = rnd() % MAXN + 2;
        c.assign(n, 0);
        int cnt = min(n, 2 + int(rnd() % n));
        cnt = min(cnt, 3);
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        shuffle(perm.begin(), perm.end(), rnd);
        for (int it = 0; it < cnt; it++)
            c[perm[it]] = 1;
        g.resize(n);
        for (int u, v, i = 0; i < n - 1; i++) {
            v = i + 1;
            u = max(0, i - int(rnd() % 10));
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    void gen_max_test() {

    }

    void dfs(int v, int par = -1) {
        p[v] = par;
        d[v] = c[v];
        if (par != -1)
            d[v] += d[par];
        S[v] = c[v];
        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v);
            S[v] += S[to];
        }
    }

    void go(int v, vector<int>& pu, vector<int>& res) {
        res[v] |= pu[v];
        for (int to : g[v]) {
            if (to == p[v])
                continue;
            pu[to] |= pu[v];
            go(to, pu, res);
        }
    }

    output fast() {
        int root = 0;
        while (!c[root])
            root++;
        p.assign(n, -1);
        d.assign(n, 0);
        S.assign(n, 0);
        dfs(root, -1);
        int all = *max_element(d.begin(), d.end()) >= 3;
        {
            int cnt = 0;
            for (int to : g[root]) {
                if (S[to])
                    cnt++;
            }
            all |= cnt >= 2;
        }
        for (int v = 0; v < n; v++) {
            for (int to : g[v]) {
                if (c[v] && c[to])
                    all = 1;
            }
        }
        for (int v = 0; v < n; v++) {
            int cnt = 0, any = p[v] == root;
            for (int to : g[v]) {
                if (to == p[v])
                    continue;
                if (S[to])
                    cnt++;
                if (c[to])
                    any = 1;
            }
            if (cnt >= 2 && any)
                all = 1;
        }
        if (all) {
            vector<int> res(n, 1);
            return output{res};
        }
        vector<int> res = c, pu(n);
        for (int i = 0; i < n; i++) {
            if (i != root && c[i]) {
                pu[p[i]] = 1;
            }
        }
        for (int to : g[root]) {
            if (S[to]) {
                res[to] = 1;
                for (int toto : g[to]) {
                    if (!S[toto])
                        pu[toto] = 1;
                }
            } else {
                pu[to] = 1;
            }
        }
        go(root, pu, res);
        return output{res};
    }

    bool find(int v, int x, int par = -1) {
        if (v == x)
            return true;
        for (int to : g[v]) {
            if (to == par)
                continue;
            if (find(to, x, v))
                return true;
        }
        return false;
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            vector<vector<int>> used(n, vector<int>(n + 1));
            used[i][n] = 1;
            queue<pii> q;
            q.push({i, n});
            while (!q.empty()) {
                auto [v, last] = q.front();
                q.pop();
                if (c[v]) {
                    res[i] = 1;
                    break;
                }
                for (int x = 0; x < n; x++) {
                    if (!c[x] || x == last)
                        continue;
                    for (int to : g[v]) {
                        if (!used[to][x] && find(to, x, v)) {
                            used[to][x] = 1;
                            q.push({to, x});
                        }
                    }
                }
            }
        }
        return output{res};
    }
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