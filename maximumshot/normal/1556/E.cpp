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

vector<ll> slow(int n, int q, vector<int> a, vector<int> b, vector<pii> lrs) {
    vector<ll> res(q);
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        d[i] = a[i] - b[i];
    for (int it = 0; it < q; it++) {
        auto [l, r] = lrs[it];
        ll S = 0;
        ll mx = 0;
        for (int i = l; i <= r; i++) {
            S += d[i];
            mx = max(mx, ll(abs(d[i])));
        }
        if (S == 0 && d[l] <= 0 && d[r] >= 0) {
            vector<int> dd = d;
            while (1) {
                vector<int> path;
                for (int cur = 0, i = l; i <= r; i++) {
                    if ((cur == 0 && dd[i] < 0) || (cur == 1 && dd[i] > 0)) {
                        path.push_back(i);
                        cur ^= 1;
                    }
                }
                if ((int) path.size() % 2)
                    path.pop_back();
                if (path.empty())
                    break;
                for (int i : path) {
                    if (dd[i] < 0) dd[i]++;
                    else dd[i]--;
                }
                res[it]++;
            }
            for (int i = l; i <= r; i++) {
                if (dd[i] != 0) {
                    res[it] = -1;
                    break;
                }
            }
        } else {
            res[it] = -1;
        }
    }
    return res;
}

inline int sign(int x) {
    return x > 0 ? +1 : x < 0 ? -1 : 0;
}

struct RangeTree {
    struct Node {
        ll s = 0;
        ll mn = inf64;
        ll mx = -inf64;
    };

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.s = l.s + r.s;
        res.mn = min(l.mn, l.s + r.mn);
        res.mx = max(l.mx, l.s + r.mx);
        return res;
    }

    int n = 0; // [1, n]
    vector<Node> t;

    RangeTree(int nn, const vector<int>& d) {
        n = nn;
        t.resize(4 * n);
        build(1, 1, n, d);
    }

    void build(int v, int tl, int tr, const vector<int>& d) {
        if (tl == tr) {
            t[v].s = t[v].mn = t[v].mx = d[tl];
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, d);
            build(v << 1 | 1, tm + 1, tr, d);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1;
            Node res;
            if (l <= tm)
                res = merge(res, query(v << 1, tl, tm, l, r));
            if (r > tm)
                res = merge(res, query(v << 1 | 1, tm + 1, tr, l, r));
            return res;
        }
    }

    Node query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

vector<ll> fast(int n, int q, vector<int> a, vector<int> b, vector<pii> lrs) {
    vector<ll> res(q);
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        d[i] = a[i] - b[i];
    RangeTree rt(n, d);
    for (int it = 0; it < q; it++) {
        auto [l, r] = lrs[it];
//        ll mn = inf64, mx = -inf64;
//        ll S = 0;
//        for (int i = l; i <= r; i++) {
//            S += d[i];
//            mn = min(mn, S);
//            mx = max(mx, S);
//        }
        RangeTree::Node node = rt.query(l, r);
        ll S = node.s;
        ll mn = node.mn;
        ll mx = node.mx;
        if (S != 0 || mx > 0) {
            res[it] = -1;
        } else {
            res[it] = -mn;
        }
    }
    return res;
}

void work() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<pii> lrs(q);
    for (auto& [l, r] : lrs)
        cin >> l >> r;
    vector<ll> res = fast(n, q, a, b, lrs);
    for (auto x : res)
        cout << x << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 8;
    const int MAXX = 5;
    while (1) {
        int n = rnd() % (MAXN - 2) + 2;
//        int q = rnd() % n * n + 1;
        int q = 1;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = rnd() % MAXX;
            b[i] = rnd() % MAXX;
        }
        vector<pii> lrs(q);
        for (auto& [l, r] : lrs) {
            r = rnd() % n + 1;
            l = rnd() % r + 1;
        }
        cout << n << " " << q << "\n";
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";
        cout << "\n";
        for (auto [l, r] : lrs)
            cout << l << " " << r << "\n";
        cout.flush();
        vector<ll> fs = fast(n, q, a, b, lrs);
        vector<ll> sl = slow(n, q, a, b, lrs);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n";
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