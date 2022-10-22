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
    int score;
    vector<int> res;

    void print() {
#ifdef DEBUG
        cout << "score = " << score << "\n";
#endif
        for (auto x : res)
            cout << x + 1 << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        return score == o.score;
    }
};

int calc_score(vector<int> p, vector<int> q) {
    int res = 0;
    int n = (int) p.size();
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        res += abs(q[i] - p[q[ni]]);
    }
    return res;
}

vector<int> rev(vector<int> p) {
    int n = (int) p.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[p[i]] = i;
    return res;
}

vector<int> mul(vector<int> a, vector<int> b) {
    int n = (int) a.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = a[b[i]];
    return res;
}

int get_number_of_cycles(vector<int> p) {
    int n = (int) p.size();
    vector<int> used(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;
        for (int j = i; !used[j]; j = p[j])
            used[j] = 1;
        res++;
    }
    return res;
}

struct DSU {
    int n = 0; // [0, n)
    vector<int> p;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        p[y] = x;
    }
};

struct input {
    int n;
    vector<int> p;

    input() = default;

    void read() {
        cin >> n;
        p.resize(n);
        for (auto& x : p)
            cin >> x, x--;
    }

    void print() {
        cout << n << "\n";
        for (auto x : p)
            cout << x + 1 << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 8;
        n = rnd() % MAXN + 1;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin(), p.end(), rnd);
    }

    void gen_max_test() {

    }

    output fast() {
        DSU dsu(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            g[p[i]].push_back(i);
            dsu.merge(i, p[i]);
        }
        for (int i = 0; i + 1 < n; i++) {
            if (dsu.find(i) != dsu.find(i + 1)) {
                dsu.merge(i, i + 1);
                g[i].push_back(i + 1);
                g[i + 1].push_back(i);
            }
        }
        for (int i = 1; i < n; i++)
            assert(dsu.find(i) == dsu.find(0));
        vector<int> euler;
        function<void(int)> dfs = [&](int v) {
            while (!g[v].empty()) {
                int to = g[v].back();
                g[v].pop_back();
                dfs(to);
                euler.push_back(v);
            }
        };
        for (int v = 0; v < n; v++) {
            dfs(v);
        }
        reverse(euler.begin(), euler.end());
        vector<int> q;
        for (int i = 0; i < (int) euler.size(); i++) {
            int v = euler[i];
            int to = euler[(i + 1) % (int) euler.size()];
            if (p[to] == v) q.push_back(to);
        }
        return output{calc_score(p, q), q};
    }

#ifdef DEBUG
    output slow() {
        vector<int> q(n), best_q;
        iota(q.begin(), q.end(), 0);
        int best_score = inf;
        do {
            int tmp_score = calc_score(p, q);
            if (tmp_score < best_score) {
                best_score = tmp_score;
                best_q = q;
            }
        } while (next_permutation(q.begin(), q.end()));
        return output{best_score, best_q};
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
    int t;
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