#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = inf + 10;

struct RangeTree {
    int n = 0;
    vector<int> ds;
    vector<pii> mn;
    vector<vector<pii>> st;

    RangeTree() = default;

    RangeTree(vector<tuple<int, int, int>> a) {
        for (auto [d, x, y] : a)
            ds.push_back(d);

        sort(ds.begin(), ds.end());
        ds.erase(unique(ds.begin(), ds.end()), ds.end());
        n = (int) ds.size();

        st.resize(n, {{X, X}});

        for (auto [d, x, y] : a) {
            int pos = lower_bound(ds.begin(), ds.end(), d) - ds.begin();
            st[pos].emplace_back(x, y);
        }

        for (int i = 0; i < n; i++)
            sort(st[i].rbegin(), st[i].rend());

        mn.resize(4 * n, {X, X});

        build(1, 0, n - 1);
    }

    void merge(int v) {
        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            mn[v] = st[tl].back();
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
            merge(v);
        }
    }

    pii query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return {X, X};
        if (l <= tl && tr <= r) {
            return mn[v];
        } else {
            int tm = (tl + tr) >> 1;
            pii res = {X, X};
            if (l <= tm)
                res = min(res, query(v << 1, tl, tm, l, r));
            if (r > tm)
                res = min(res, query(v << 1 | 1, tm + 1, tr, l, r));
            merge(v);
            return res;
        }
    }

    pii query(int d) {
        int pos = lower_bound(ds.begin(), ds.end(), d) - ds.begin();
        return query(1, 0, n - 1, 0, pos - 1);
    }

    void pop(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            st[tl].pop_back();
            mn[v] = st[tl].back();
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                pop(v << 1, tl, tm, pos);
            else
                pop(v << 1 | 1, tm + 1, tr, pos);
            merge(v);
        }
    }

    void pop(int d) {
        int pos = lower_bound(ds.begin(), ds.end(), d) - ds.begin();
        pop(1, 0, n - 1, pos);
    }
};

void read(int& n, int& m, vector<pii>& a, vector<pii>& b) {
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i++)
        cin >> b[i].first >> b[i].second;
}

void gen(int& n, int& m, vector<pii>& a, vector<pii>& b, mt19937& rnd) {
    const int MAXN = 50;
    const int MAXX = 150;
    n = rnd() % MAXN + 1;
    m = rnd() % MAXN + 1;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++)
        a[i] = {rnd() % MAXX, rnd() % MAXX};
    for (int i = 0; i < m; i++)
        b[i] = {rnd() % MAXX, rnd() % MAXX};
}

vector<int> fast(int n, int m, vector<pii> a, vector<pii> b) {
    set<pii> P(a.begin(), a.end());

    vector<tuple<int, int, int>> dxy, dyx;
    for (auto [x, y] : a) {
        dxy.emplace_back(y - x, x, y);
        dyx.emplace_back(x - y, y, x);
    }

    RangeTree rtx(dxy), rty(dyx);
    int x0 = 0, y0 = 0;

    vector<tuple<int, int, int>> segs;

    while (1) {
        auto [mx1, my1] = rtx.query(y0 - x0);
        if (mx1 < x0) {
            rtx.pop(my1 - mx1);
            continue;
        }
        auto [my2, mx2] = rty.query(x0 - y0);
        if (my2 < y0) {
            rty.pop(mx2 - my2);
            continue;
        }
        if (mx1 == X && my2 == X) {
            segs.emplace_back(x0 - y0, x0, X);
            break;
        }
        int x1, y1;
        if (my2 < y0 + mx1 - x0) {
            if (my2 > y0)
                segs.emplace_back(x0 - y0, x0, x0 + my2 - y0 - 1);
            x1 = x0 + my2 - y0;
            y1 = my2 + 1;
        } else {
            if (mx1 > x0)
                segs.emplace_back(x0 - y0, x0, mx1 - 1);
            x1 = mx1 + 1;
            y1 = y0 + mx1 - x0;
        }
        x0 = x1;
        y0 = y1;
    }

    unordered_map<int, vector<int>> ar;
    for (auto [d, lx, rx] : segs) {
        ar[d].push_back(lx);
        ar[d].push_back(rx + 1);
    }

//    for (auto [d, lx, rx] : segs) {
//        cout << "(" << lx << "," << lx - d << ") -> (" << rx << "," << rx - d << ")\n";
//    }
    vector<int> res(m);

    for (int i = 0; i < m; i++) {
        auto [x, y] = b[i];
        if (P.count({x, y})) {
            res[i] = 0;
            continue;
        }
        int d = x - y;
        if (!ar.count(d)) {
            res[i] = 1;
            continue;
        }
        auto& hlp = ar[d];
        int pos = upper_bound(hlp.begin(), hlp.end(), x) - hlp.begin() - 1;
        if (pos % 2 == 0) {
            res[i] = 0;
        } else {
            res[i] = 1;
        }
    }

    return res;
}

vector<int> slow(int n, int m, vector<pii> a, vector<pii> b) {
    const int MAXX = 200;
    vector<vector<int>> f(MAXX, vector<int>(MAXX, -1)), g(MAXX, vector<int>(MAXX));
    f[0][0] = 0;
    for (auto [x, y] : a)
        f[x][y] = 0, g[x][y] = 1;
    for (int i = 0; i < MAXX; i++) {
        for (int j = 0; j < MAXX; j++) {
            if (f[i][j] != -1)
                continue;
            f[i][j] = 0;
            for (int x = 1; x <= i; x++)
                if (f[i - x][j] == 0)
                    f[i][j] = 1;
            for (int x = 1; x <= j; x++)
                if (f[i][j - x] == 0)
                    f[i][j] = 1;
        }
    }
    for (int y = MAXX - 1; y >= 0; y--) {
        for (int x = 0; x < MAXX; x++) {
            if (g[x][y])
                cout << "*";
            else
                cout << f[x][y];
        }
        cout << "\n";
    }
    cout << "\n";
    vector<int> res(b.size());
    for (int i = 0; i < (int) b.size(); i++) {
        auto [x, y] = b[i];
        res[i] = f[x][y];
    }
    return res;
}

void work() {
    int n, m;
    vector<pii> a, b;
    read(n, m, a, b);
    vector<int> fs = fast(n, m, a, b);
    for (int x : fs)
        cout << (x ? "WIN" : "LOSE") << "\n";
}

void test() {
    mt19937 rnd(time(NULL));
    while (1) {
        int n, m;
        vector<pii> a, b;
        gen(n, m, a, b, rnd);
        vector<int> sl = slow(n, m, a, b);
        vector<int> fs = fast(n, m, a, b);

        cout << n << " " << m << endl;
        for (auto [x, y] : a)
            cout << x << " " << y << endl;
        cout << endl;
        for (auto [x, y] : b)
            cout << x << " " << y << endl;

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