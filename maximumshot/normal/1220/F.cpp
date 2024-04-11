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

struct RMQ {
    vector<int> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<pii>> rmq;

    RMQ(const vector<int>& aa) {
        a = aa;
        n = (int) a.size();
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        _log.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            _log[i] = _log[i - 1] + 1;
            if ((1 << _log[i]) > i) _log[i]--;
        }
        rmq.resize(LOG, vector<pii>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = {a[i], i};
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    pii get_min(int l, int r) const {
        int lg = _log[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> mx, pu;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        mx.resize(4 * n);
        pu.resize(4 * n);
    }

    void do_inc(int v, int x) {
        mx[v] += x;
        pu[v] += x;
    }

    void push(int v) {
        do_inc(v << 1, pu[v]);
        do_inc(v << 1 | 1, pu[v]);
        pu[v] = 0;
    }

    void merge(int v) {
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }

    void inc(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            do_inc(v, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm) {
                inc(v << 1, tl, tm, l, r, x);
            }
            if (r > tm ){
                inc(v << 1 | 1, tm + 1, tr, l, r, x);
            }
            merge(v);
        }
    }

    void inc(int l, int r, int x) {
        if (l > r) return;
        inc(1, 0, n - 1, l, r, x);
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return mx[v];
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            int res = 0;
            if (l <= tm) {
                res = max(res, get(v << 1, tl, tm, l, r));
            }
            if (r > tm) {
                res = max(res, get(v << 1 | 1, tm + 1, tr, l, r));
            }
            merge(v);
            return res;
        }
    }

    int get(int l, int r) {
        if (l > r) return 0;
        return get(1, 0, n - 1, l, r);
    }

    void put(int v, int tl, int tr, int p, int x) {
        if (tl == tr) {
            mx[v] = x;
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (p <= tm) {
                put(v << 1, tl, tm, p, x);
            } else {
                put(v << 1 | 1, tm + 1, tr, p, x);
            }
            merge(v);
        }
    }

    void put(int p, int x) {
        put(1, 0, n - 1, p, x);
    }
};

struct Node {
    int l, r;
};

void build(const RMQ& rmq, int l, int r, RangeTree& rt) {
    if (l > r) return;
    rt.inc(l, r, 1);
    if (l == r) {
        return;
    }
    int m, x;
    tie(x, m) = rmq.get_min(l, r);
    build(rmq, l, m - 1, rt);
    build(rmq, m + 1, r, rt);
}

pii fast(vector<int> a) {
    int n = (int) a.size();
    RangeTree rt(2 * n);
    a.resize(2 * n);
    for (int i = 0; i < n; i++) {
        a[i + n] = a[i];
    }

    RMQ rmq(a);
    build(rmq, 0, n - 1, rt);

    vector<int> right_path;
    for (int l = 0, r = n - 1; l <= r; ) {
        int x, m;
        tie(x, m) = rmq.get_min(l, r);
        right_path.push_back(m);
        l = m + 1;
    }

    int best_shift = -1;
    int min_depth = inf;
    for (int k = 0; k < n; k++) {
        int tmp_depth = rt.get(k, k + n - 1);
        if (tmp_depth < min_depth) {
            min_depth = tmp_depth;
            best_shift = k;
        }
        if (k + 1 == n) break;
        int kk = k + n;
        if (a[k] == 0) {
            right_path = {kk};
            rt.put(kk, 1);
            continue;
        }

        int qr = kk, ql;

        {
            int bl = k;
            int br = kk;
            int bm;
            while (br - bl > 1) {
                bm = (bl + br) >> 1;
                if (rmq.get_min(bm, qr).first == a[kk]) {
                    br = bm;
                } else {
                    bl = bm;
                }
            }
            ql = br;
        }

        rt.inc(ql, qr, +1);

        ql = k;

        {
            int bl = k;
            int br = kk;
            int bm;
            while (br - bl > 1) {
                bm = (bl + br) >> 1;
                if (rmq.get_min(ql, bm).first == a[k]) {
                    bl = bm;
                } else {
                    br = bm;
                }
            }
            qr = bl;
        }

        rt.inc(ql, qr, -1);

        while (!right_path.empty() && a[k] < a[right_path.back()]) {
            right_path.pop_back();
        }
        right_path.push_back(kk);

        rt.put(kk, (int) right_path.size());
    }
    return {min_depth, best_shift};
}

void read(vector<int>& a) {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
}

void WORK() {
    vector<int> a;
    read(a);
    pii res = fast(a);
    cout << res.first << " " << res.second << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    WORK();

    return 0;
}