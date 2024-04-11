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
        throw;
    }
};

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
        return x == p[x] ? x : find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        p[y] = x;
    }

    void reset(int x) {
        p[x] = x;
    }
};

struct input {
    int n;

    struct Query {
        int t, x, y;
    };

    vector<Query> qs;

    input() = default;

    void read() {
        cin >> n;
        qs.resize(n);
        for (auto& q : qs) {
            cin >> q.t >> q.x;
            if (q.t == 2) cin >> q.y;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        int X = 0;
        for (auto q : qs)
            X = max({X, q.x, q.y});
        X++;

        vector<int> p;
        vector<vector<int>> poses(X);

        for (auto q : qs) {
            if (q.t == 1) {
                int sz = (int) p.size();
                poses[q.x].push_back(sz);
                p.push_back(sz);
            } else if (q.x != q.y) {
                if (poses[q.y].empty()) {
                    swap(poses[q.x], poses[q.y]);
                } else {
                    int j = poses[q.y].front();
                    for (auto i : poses[q.x]) {
                        p[i] = j;
                    }
                    poses[q.x].clear();
                }
            }
        }

        int sz = (int) p.size();
        vector<int> res(sz, -1);
        for (int x = 0; x < X; x++) {
            for (auto i : poses[x])
                res[i] = x;
        }
        vector<vector<int>> g(sz);
        for (int i = 0; i < sz; i++) {
            if (p[i] != i)
                g[p[i]].push_back(i);
        }

        queue<int> q;
        for (int i = 0; i < sz; i++) {
            if (res[i] != -1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (res[to] == -1) {
                    res[to] = res[v];
                    q.push(to);
                }
            }
        }

        return output{res};
    }

    output slow() {
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