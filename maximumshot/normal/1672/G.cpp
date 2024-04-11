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

const int mod = 998244353;

inline int sum_(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int mul_(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sub_(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void inc_(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void dec_(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int binpow_(int x, int pw) {
    if (x == 0)
        return 0;
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = mul_(res, tmp);
        }
        tmp = mul_(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int div_(int a, int b) {
    return mul_(a, binpow_(b, mod - 2));
}

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
    vector<string> a;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {
        cout << n << " " << m << "\n";
    }

    void gen() {

    }

    void gen_max_test() {

    }

    output fast() {
        if (n % 2 == 1 && m % 2 == 0) {
            vector<string> b(m, string(n, '?'));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    b[j][i] = a[i][j];
                }
            }
            swap(a, b);
            swap(n, m);
        }
        vector<int> R(n), C(m), cr(n), cc(m);
        vector<int> pw2(n * m + 1);
        pw2[0] = 1;
        for (int i = 1; i <= n * m; i++)
            pw2[i] = mul_(pw2[i - 1], 2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '?') {
                    cr[i]++;
                    cc[j]++;
                } else if (a[i][j] == '1') {
                    R[i] ^= 1;
                    C[j] ^= 1;
                }
            }
        }
        // n <= m
        if (n % 2 == 0 && m % 2 == 0) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '?')
                        cnt++;
                }
            }
            return output{pw2[cnt]};
        } else if (n % 2 == 1 && m % 2 == 1) {
            vector<vector<int>> g(n + m);
            vector<int> w(n + m);
            for (int i = 0; i < n; i++) w[i] = R[i];
            for (int j = 0; j < m; j++) w[n + j] = C[j];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '?') {
                        g[i].push_back(n + j);
                        g[n + j].push_back(i);
                    }
                }
            }
            int res = 0;
            for (int want = 0; want < 2; want++) {
                vector<int> used(n + m);
                int add = 1;
                for (int s = 0; s < n + m; s++) {
                    if (used[s]) continue;
                    vector<int> comp = {s};
                    used[s] = 1;
                    queue<int> q;
                    q.push(s);
                    while (!q.empty()) {
                        int v = q.front();
                        q.pop();
                        for (int to: g[v]) {
                            if (!used[to]) {
                                used[to] = 1;
                                q.push(to);
                                comp.push_back(to);
                            }
                        }
                    }
                    int x = 0;
                    for (int v: comp) x ^= w[v];
                    int N = (int) comp.size();
                    int M = 0;
                    for (int v: comp) M += (int) g[v].size();
                    M /= 2;
                    int cur = 0;
                    if (N % 2 == 0) {
                        if (x == 0) cur = pw2[M - N + 1];
                    } else {
                        if (x == want) cur = pw2[M - N + 1];
                    }
                    add = mul_(add, cur);
                }
                inc_(res, add);
            }
            return output{res};
        } else if (n % 2 == 0) {
            int h0 = 0, h1 = 0;
            for (int i = 0; i < n; i++) {
                if (cr[i] == 0 && R[i] == 0) h0 = 1;
                if (cr[i] == 0 && R[i] == 1) h1 = 1;
            }
            if (h0 && h1) return output{0};
            int res = 0;
            int ml = 1;
            for (int i = 0; i < n; i++) {
                if (cr[i] == 0) continue;
                ml = mul_(ml, pw2[cr[i] - 1]);
            }
            if (!h0) inc_(res, ml);
            if (!h1) inc_(res, ml);
            return output{res};
        }
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

void help(int n, int m) {
    auto encode = [&](vector<vector<int>> a) -> int {
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) res |= 1 << (i * m + j);
            }
        }
        return res;
    };
    auto decode = [&](int mask) -> vector<vector<int>> {
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((1 << (i * m + j)) & mask)
                    res[i][j] = 1;
            }
        }
        return res;
    };
    unordered_set<int> used;
    function<void(int)> dfs = [&](int v) {
        if (used.count(v)) return;
        used.insert(v);
        vector<vector<int>> a = decode(v);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto b = a;
                for (int q = 0; q < n; q++) b[q][j] ^= 1;
                for (int q = 0; q < m; q++) b[i][q] ^= 1;
                b[i][j] ^= 1;
                int to = encode(b);
                dfs(to);
            }
        }
    };
    dfs(0);
    cout << (int) used.size() << "\n";
//    for (int mask : used) {
//        auto b = decode(mask);
//        for (auto row : b) {
//            for (auto x : row) cout << x;
//            cout << "\n";
//        }
//        cout << "\n";
//    }
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

//    const int MAX_AREA = 18;
//    for (int n = 1; n <= MAX_AREA; n++) {
//        for (int m = 1; n * m <= MAX_AREA; m++) {
//            cout << "n = " << n << ", m = " << m << "\n";
//            help(n, m);
//            cout << "\n\n" << endl;
//        }
//    }

    return 0;
}