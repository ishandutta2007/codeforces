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
    int n, m, k;
    vector<string> a;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
        cin >> k;
        qs.resize(k);
        for (auto& [l, r] : qs)
            cin >> l >> r;
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto x : a)
            cout << x << "\n";
        cout << k << "\n";
        for (auto [l, r] : qs)
            cout << l << " " << r << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 100;
        n = rnd() % MAXN + 1;
        m = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a) {
            x.resize(m);
            for (auto& y : x)
                y = rnd() % 10 ? '.' : 'X';
        }
        k = rnd() % MAXN + 1;
        qs.resize(k);
        for (auto& [l, r] : qs) {
            r = rnd() % m + 1;
            l = rnd() % r + 1;
        }
    }
};

struct output {
    vector<int> res;

    output() = default;

    void print() {
        for (auto x : res)
            cout << (x ? "YES" : "NO") << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

bool check(vector<string> mat) {
    int n = (int) mat.size(), m = (int) mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'X') continue;
            dp[i][j] = (i == 0 || j == 0 || dp[i - 1][j] || dp[i][j - 1]);
            if (!dp[i][j])
                return false;
        }
    };
    return true;
};

output slow(input in) {
    output res;
    for (auto [l, r] : in.qs) {
        vector<string> mat(in.n);
        for (int i = 0; i < in.n; i++)
            mat[i] = in.a[i].substr(l - 1, r - l + 1);
        res.res.push_back(check(mat));
    }
    return res;
}

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> t;

    RangeTree(const vector<int>& a) {
        n = (int) a.size();
        t.resize(2 * n, -inf);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i >= 0; i--)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    int get(int l, int r) {
        int res = -inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
};

output fast(input in) {
    vector<int> f(in.m + 1);
    for (int i = 1; i < in.n; i++) {
        for (int j = 1; j < in.m; j++) {
            if (in.a[i - 1][j] == 'X' && in.a[i][j - 1] == 'X') {
                f[j + 1]++;
            }
        }
    }
    for (int j = 1; j <= in.m; j++)
        f[j] += f[j - 1];
    output res;
    for (auto [l, r] : in.qs) {
        if (f[r] - f[l] > 0) res.res.push_back(0);
        else res.res.push_back(1);
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