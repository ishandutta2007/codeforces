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

const int MAXX = 3e5 + 5;

struct output {
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> mn, mx, pu;

    RangeTree() = default;

    RangeTree(const vector<int>& a) {
        n = (int) a.size();
        mn.assign(4 * n, +inf);
        mx.assign(4 * n, -inf);
        pu.assign(4 * n, -1);
        build(1, 0, n - 1, a);
    }

    void set(int v, int x) {
        mn[v] = mx[v] = pu[v] = x;
    }

    void push(int v) {
        if (pu[v] != -1) {
            set(v << 1, pu[v]);
            set(v << 1 | 1, pu[v]);
            pu[v] = -1;
        }
    }

    void merge(int v) {
        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            mn[v] = mx[v] = a[tl];
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            merge(v);
        }
    }

    void set(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            set(v, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm) set(v << 1, tl, tm, l, r, x);
            if (r > tm) set(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void set(int l, int r, int x) {
        set(1, 0, n - 1, l, r, x);
    }

    int find_first(int v, int tl, int tr, int i, int t) {
        if (tl == tr) {
            return mn[v] == t ? tl : -1;
        } else if (i <= tl && ((t == 1 && mx[v] == 0) || (t == 0 && mn[v] == 1))) {
            return -1;
        } else {
            int tm = (tl + tr) >> 1, res = -1;
            push(v);
            if (i <= tm) res = find_first(v << 1, tl, tm, i, t);
            if (res == -1) res = find_first(v << 1 | 1, tm + 1, tr, i, t);
            merge(v);
            return res;
        }
    }

    int find_first(int i, int t) {
        return find_first(1, 0, n - 1, i, t);
    }

    int query(int v, int tl, int tr) {
        if (tl == tr) {
            return tl;
        } else {
            int tm = (tl + tr) >> 1, res = -1;
            push(v);
            if (mx[v << 1 | 1]) res = query(v << 1 | 1, tm + 1, tr);
            else res = query(v << 1, tl, tm);
            merge(v);
            return res;
        }
    }

    int query() {
        return query(1, 0, n - 1);
    }
};

struct input {
    int n, q;
    vector<int> a;
    vector<pii> ops;

    input() = default;

    void read() {
        cin >> n >> q;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
        ops.resize(q);
        for (auto& [k, l] : ops)
            cin >> k >> l, k--;
    }

    void print() {
        cout << n << " " << q << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        for (auto [k, l] : ops)
            cout << k + 1 << " " << l << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int N = 5;
        const int X = 10;
        n = rnd() % N + 2;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % X + 1;
        q = rnd() % N + 1;
        ops.resize(q);
        for (auto& [k, l] : ops) {
            k = rnd() % n;
            l = rnd() % X + 1;
        }
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> cnt(MAXX);
        for (auto x : a) cnt[x]++;
        for (int i = 0; i < MAXX; i++) {
            if (cnt[i]) {
                cnt[i + 1] += cnt[i] / 2;
                cnt[i] %= 2;
            }
        }
        RangeTree rt(cnt);
        auto query = [&]() -> int {
            return rt.query();
        };
        auto add_bit = [&](int i) {
            int pos = rt.find_first(i, 0);
            if (i < pos) rt.set(i, pos - 1, 0);
            rt.set(pos, pos, 1);
        };
        auto rem_bit = [&](int i) {
            int pos = rt.find_first(i, 1);
            if (i < pos) rt.set(i, pos - 1, 1);
            rt.set(pos, pos, 0);
        };
        vector<int> res;
        for (auto [k, l] : ops) {
            rem_bit(a[k]);
            a[k] = l;
            add_bit(a[k]);
            int x = query();
            res.push_back(x);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<int> cnt(MAXX);
        for (auto x : a) cnt[x]++;
        auto query = [&]() -> int {
            int cur = 0;
            int mx = 0;
            for (int i = 1; i < MAXX; i++) {
                cur += cnt[i];
                if (cur) mx = i;
                cur /= 2;
            }
            return mx;
        };
        vector<int> res;
        for (auto [k, l] : ops) {
            cnt[a[k]]--;
            a[k] = l;
            cnt[a[k]]++;
            int x = query();
            res.push_back(x);
        }
        return output{res};
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