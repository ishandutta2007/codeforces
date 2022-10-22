#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Fen {
    int n = 0; // [0, n)
    vector<int> f;

    Fen() = default;

    Fen(int nn) {
        n = nn;
        f.resize(n);
    }

    void add(int i, int x) {
        for (int cur = i; cur < n; cur |= (cur + 1))
            f[cur] += x;
    }

    int get(int i) {
        int res = 0;
        for (int cur = i; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += f[cur];
        return res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> pu, mn;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        pu.resize(4 * n, 0);
        mn.resize(4 * n, 0);
    }

    void inc(int v, int dx) {
        pu[v] += dx;
        mn[v] += dx;
    }

    void push(int v) {
        inc(v << 1, pu[v]);
        inc(v << 1 | 1, pu[v]);
        pu[v] = 0;
    }

    void merge(int v) {
        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
    }

    void update(int v, int tl, int tr, int l, int r, int dx) {
        if (l <= tl && tr <= r) {
            inc(v, dx);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm) update(v << 1, tl, tm, l, r, dx);
            if (r > tm) update(v << 1 | 1, tm + 1, tr, l, r, dx);
            merge(v);
        }
    }

    void update(int l, int r, int dx) {
        update(1, 0, n - 1, l, r, dx);
    }

    int query() const {
        return mn[1];
    }
};

ll fast(int n, int m, vector<int> a, vector<int> b) {
    vector<int> crd;
    crd.reserve(n + m);
    for (int i = 0; i < n; i++) crd.push_back(a[i]);
    for (int i = 0; i < m; i++) crd.push_back(b[i]);
    sort(crd.begin(), crd.end());
    crd.erase(unique(crd.begin(), crd.end()), crd.end());
    int sz = (int) crd.size();
    for (auto& x : a) x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
    for (auto& x : b) x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
    ll inva = 0;
    Fen fena(sz);
    for (int i = n - 1; i >= 0; i--) {
        inva += fena.get(a[i] - 1);
        fena.add(a[i], +1);
    }
    sort(b.begin(), b.end());
    vector<int> posa(n); iota(posa.begin(), posa.end(), 0);
    sort(posa.begin(), posa.end(), [&](int i, int j) { return a[i] < a[j]; });
    //        vector<int> value(n + 1);
    RangeTree rt(n + 1);
    for (int j = 0; j < n; j++) {
        //            for (int q = j + 1; q <= n; q++) value[q]++;
        rt.update(j + 1, n, +1);
    }
    ll total = inva;
    for (int le = 0, lt = 0, i = 0; i < m; i++) {
        while (lt < n && a[posa[lt]] < b[i]) {
            int j = posa[lt];
            //                for (int q = 0; q <= j; q++) value[q]++;
            rt.update(0, j, +1);
            lt++;
        }
        while (le < n && a[posa[le]] <= b[i]) {
            int j = posa[le];
            //                for (int q = j + 1; q <= n; q++) value[q]--;
            rt.update(j + 1, n, -1);
            le++;
        }
        //            int mn = *min_element(value.begin(), value.end());
        int mn = rt.query();
        total += mn;
    }
    return total;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        ll res = fast(n, m, a, b);
        cout << res << "\n";
    }
}

void run_test(int n, int m) {
    mt19937 rnd(42);
    const int MAXX = 1e9;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) a[i] = rnd() % MAXX + 1;
    for (int i = 0; i < m; i++) b[i] = rnd() % MAXX + 1;
    ll res = fast(n, m, a, b);
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    work();
//    max_test();

    return 0;
}