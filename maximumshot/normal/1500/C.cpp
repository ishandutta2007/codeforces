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
    int can;
    vector<int> res;

    void print() {
        if (can) {
            cout << (int) res.size() << "\n";
            for (auto x : res)
                cout << x + 1 << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    bool operator == (const output& o) const {
        return can == o.can;
    }
};

struct input {
    int n, m;
    vector<vector<int>> a, b;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n, vector<int>(m));
        b.resize(n, vector<int>(m));
        for (auto& row : a) for (auto& x : row) cin >> x;
        for (auto& row : b) for (auto& x : row) cin >> x;
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto row : a) {
            for (auto x : row) cout << x << " ";
            cout << "\n";
        }
        cout << "\n";
        for (auto row : b) {
            for (auto x : row) cout << x << " ";
            cout << "\n";
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 4;
        n = rnd() % MAXN + 1;
        m = rnd() % MAXN + 1;
        a.resize(n, vector<int>(m));
        b.resize(n, vector<int>(m));
        for (auto& row : a) for (auto& x : row) x = rnd() % n + 1;
        b = a;
        shuffle(b.begin(), b.end(), rnd);
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> f(m);
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] > b[i + 1][j])
                    f[j]++;
            }
        }
        queue<int> q;
        for (int j = 0; j < m; j++) {
            if (f[j] == 0)
                q.push(j);
        }
        vector<int> perm, cut(n);
        while (!q.empty()) {
            int j = q.front();
            perm.push_back(j);
            q.pop();
            for (int i = 0; i + 1 < n; i++) {
                if (!cut[i] && b[i][j] != b[i + 1][j]) {
                    cut[i] = 1;
                    for (int t = 0; t < m; t++) {
                        if (b[i][t] > b[i + 1][t]) {
                            f[t]--;
                            if (f[t] == 0)
                                q.push(t);
                        }
                    }
                }
            }
        }
        reverse(perm.begin(), perm.end());

        vector<int> ar(n);
        iota(ar.begin(), ar.end(), 0);
        for (int j : perm) {
            stable_sort(ar.begin(), ar.end(), [&](int r1, int r2) {
                return a[r1][j] < a[r2][j];
            });
        }
        for (int i = 0; i < n; i++) {
            if (a[ar[i]] != b[i])
                return output{0, {}};
        }

        return output{1, perm};
    }

#ifdef DEBUG
    output slow() {
        return fast();
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
        in.print();
        cout.flush();
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