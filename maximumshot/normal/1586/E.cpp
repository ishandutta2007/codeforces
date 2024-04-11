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

struct input {
    int n;
    int m;
    vector<pii> edges;
    int q;
    vector<pii> queries;

    input() = default;

    void read() {
        cin >> n >> m;
        edges.resize(m);
        for (auto& [u, v] : edges)
            cin >> u >> v;
        cin >> q;
        queries.resize(q);
        for (auto& [u, v] : queries)
            cin >> u >> v;
    }

    void print() {

    }

    void gen() {
        // use static
    }
};

struct output {
    int can;
    int need;
    vector<vector<int>> paths;

    output() = default;

    void print() {
        if (can) {
            cout << "YES\n";
            for (auto p : paths) {
                cout << (int) p.size() << "\n";
                for (int v : p)
                    cout << v << " ";
                cout << "\n";
            }
        } else {
            cout << "NO\n";
            cout << need << "\n";
        }
    }

    bool operator == (const output& o) const {
        return true;
    }
};

output slow(input in) {
    return output();
}

output fast(input in) {
    vector<int> parity(in.n + 1);
    for (auto [u, v] : in.queries) {
        parity[u] ^= 1;
        parity[v] ^= 1;
    }
    int cnt = 0;
    for (int v = 1; v <= in.n; v++)
        cnt += parity[v] > 0;
    output res;
    if (cnt > 0) {
        res.can = 0;
        res.need = cnt / 2;
        return res;
    }
    res.can = 1;
    vector<vector<int>> g(in.n + 1), h(in.n + 1);
    vector<int> used(in.n + 1);
    for (auto [u, v] : in.edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(in.n + 1);
    function<void(int)> dfs = [&](int v) {
        used[v] = 1;
        for (int to : g[v]) {
            if (!used[to]) {
                par[to] = v;
                dfs(to);
                h[v].push_back(to);
                h[to].push_back(v);
            }
        }
    };
    dfs(1);
    for (auto [s, t] : in.queries) {
        vector<int> p1, p2;
        for (int x = s; x > 0; x = par[x]) p1.push_back(x);
        for (int x = t; x > 0; x = par[x]) p2.push_back(x);
        reverse(p1.begin(), p1.end());
        reverse(p2.begin(), p2.end());
        int lcp = 0;
        while (lcp < (int) p1.size() && lcp < (int) p2.size() && p1[lcp] == p2[lcp]) lcp++;
        lcp--;
        vector<int> path(p1.begin() + lcp, p1.end());
        reverse(path.begin(), path.end());
        for (int i = lcp + 1; i < (int) p2.size(); i++)
            path.push_back(p2[i]);
//        if (path.front() != s)
//            reverse(path.begin(), path.end());
        res.paths.push_back(path);
    }
    return res;
}

void test_case() {
    input in;
    in.read();
    output res = fast(in);
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

void test() {
    while (1) {
        input in;
        in.gen();
        output fs = fast(in);
        output sl = slow(in);
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA\n";
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}