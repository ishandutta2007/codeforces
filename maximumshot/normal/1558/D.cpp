#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}

int slow(int n, int m, vector<pii> a) {
    int res = 0;
    vector<int> p(n + 1);
    auto check = [&]() -> int {
        vector<int> pp = p;
        vector<pii> b;
        for (int i = 2; i <= n; i++) {
            if (p[i] >= p[i - 1])
                continue;
            int j = i - 1;
            while (j > 1 && p[j - 1] > p[i]) j--;
            int value = p[i];
            for (int q = i; q > j; q--) p[q] = p[q - 1];
            p[j] = value;
            b.emplace_back(i, j);
        }
        p = pp;
        return int(a == b);
    };
    function<void(int)> rec = [&](int i) {
        if (i > n) {
            _inc(res, check());
            return;
        }
        for (int x = 1; x <= n; x++) {
            p[i] = x;
            rec(i + 1);
        }
    };
    rec(1);
    return res;
}

mt19937 gen(42);

struct Treap {

    struct Node {
        int prior = gen();
        Node* l = nullptr;
        Node* r = nullptr;
        int value = 0;
        int pu = 0;

        Node(int x) {
            value = x;
        }
    };

    void upd(Node* v, int x) {
        if (!v) return;
        v->value += x;
        v->pu += x;
    }

    void push(Node* v) {
        if (!v) return;
        upd(v->l, v->pu);
        upd(v->r, v->pu);
        v->pu = 0;
    }

    void merge(Node*& v, Node* l, Node* r) {
        if (!l || !r) {
            v = l ? l : r;
            return;
        }
        push(l);
        push(r);
        if (l->prior < r->prior) {
            merge(l->r, l->r, r);
            v = l;
        } else {
            merge(r->l, l, r->l);
            v = r;
        }
    }

    void split_by_value(Node* v, Node*& l, Node*& r, int x) {
        if (!v) {
            l = r = nullptr;
            return;
        }
        push(v);
        if (v->value >= x) {
            split_by_value(v->l, l, v->l, x);
            r = v;
        } else {
            split_by_value(v->r, v->r, r, x);
            l = v;
        }
    }

//    set<int> ones;
    Node* root = nullptr;
    Node* nl, *nm, *nr;

    Treap() = default;

    void insert(int x) {
//        ones.insert(x);
        nl = nm = nr = nullptr;
        split_by_value(root, nl, nr, x);
        split_by_value(nr, nm, nr, x + 1);
        if (!nm) nm = new Node(x);
        merge(nl, nl, nm);
        merge(root, nl, nr);
    }

    void erase(int x) {
//        ones.erase(x);
        nl = nm = nr = nullptr;
        split_by_value(root, nl, nr, x);
        split_by_value(nr, nm, nr, x + 1);
        merge(root, nl, nr);
    }

    void inc(int x) {
//        set<int> tmp;
//        for (auto v : ones) {
//            if (v >= x)
//                tmp.insert(v + 1);
//            else
//                tmp.insert(v);
//        }
//        ones = tmp;
        nl = nr = nullptr;
        split_by_value(root, nl, nr, x);
        upd(nr, +1);
        merge(root, nl, nr);
    }

    int dfs(Node* v) {
        if (!v) return 0;
        return dfs(v->l) + dfs(v->r) + 1;
    }

    int size() {
//        return (int) ones.size();
        return dfs(root);
    }
};

const int N = 4e5 + 100;
int fact[N];
int rfact[N];

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = _mul(fact[i - 1], i);
    rfact[N - 1] = _binpow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        rfact[i] = _mul(rfact[i + 1], i + 1);
}

int CNK(int n, int k) {
    if (n < k)
        return 0;
    return _mul(fact[n], _mul(rfact[k], rfact[n - k]));
}

int fast(int n, int m, vector<pii> a) {
//    vector<int> p(n + 1);
//    int sm = 0;
    Treap tr;
    for (auto [x, y] : a) {
//        if (p[y]) sm++;
//        for (int i = x; i > y; i--)
//            p[i] = p[i - 1];
//        if (p[y]) sm--;
//        if (p[y - 1]) sm--;
//        p[y] = 1;
//        p[y - 1] = 0;
//        sm++;

        tr.inc(y);
        tr.insert(y);
        tr.erase(y - 1);
    }
//    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
//    for (int last = 1; last <= n; last++)
//        dp[1][last] = 1;
//    for (int i = 2; i <= n; i++) {
//        int dx = p[i - 1];
//        for (int last = 1; last <= n; last++) {
//            for (int nxt = last + dx; nxt <= n; nxt++)
//                _inc(dp[i][nxt], dp[i - 1][last]);
//        }
//    }
//    int res = 0;
//    for (int last = 1; last <= n; last++)
//        _inc(res, dp[n][last]);

//    for (int i = 1; i <= n; i++)
//        cout << p[i] << " ";
//    cout << "\n";
//    cout << "sm = " << sm << "\n";

    int sm = tr.size();
    int ub = n - 1 - sm;
    if (ub < 0)
        return 0;

//    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
//    dp[0][0] = 1;
//    for (int i = 1; i <= n; i++) {
//        for (int was = 0; was <= n; was++) {
//            for (int add = 0; was + add <= n; add++) {
//                _inc(dp[i][was + add], dp[i - 1][was]);
//            }
//        }
//    }
//    int res = 0;
//    for (int i = 0; i <= ub; i++)
//        _inc(res, dp[n][i]);
//    return res;

    return CNK(ub + n, n);
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 6;
    while (1) {
        int n = rnd() % MAXN + 2;
        int m = rnd() % n;
        vector<int> a(n - 1);
        for (int i = 0; i < n - 1; i++)
            a[i] = i + 2;
        shuffle(a.begin(), a.end(), rnd);
        a.resize(m);
        sort(a.begin(), a.end());
        vector<pii> b(m);
        for (int i = 0; i < m; i++)
            b[i].first = a[i], b[i].second = rnd() % (a[i] - 1) + 1;
        int fs = fast(n, m, b);
        int sl = slow(n, m, b);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << " " << m << "\n";
            for (auto [x, y] : b)
                cout << x << " " << y << "\n";
            break;
        }
    }
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pii> a(m);
        for (auto& [x, y] : a)
            cin >> x >> y;
        int res = fast(n, m, a);
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    work();
//    test();

    return 0;
}