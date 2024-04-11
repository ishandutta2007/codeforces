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
    int n; // [1, n]
    vector<int> mn, mx, pu;

    RangeTree(int nn) {
        n = nn;
        mn.resize(4 * n, -1);
        mx.resize(4 * n, -1);
        pu.resize(4 * n, X);
    }

    void put(int v, int x) {
        mn[v] = mx[v] = pu[v] = x;
    }

    void push(int v) {
        if (pu[v] != X) {
            put(v << 1, pu[v]);
            put(v << 1 | 1, pu[v]);
            pu[v] = X;
        }
    }

    void merge(int v) {
        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            put(v, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                update(v << 1, tl, tm, l, r, x);
            if (r > tm)
                update(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    int lower_bound(int v, int tl, int tr, int x) {
        if (tl == tr) {
            return mx[v] >= x ? tl : n + 1;
        } else {
            int tm = (tl + tr) >> 1, res;
            push(v);
            if (mx[v << 1] >= x)
                res = lower_bound(v << 1, tl, tm, x);
            else
                res = lower_bound(v << 1 | 1, tm + 1, tr, x);
            merge(v);
            return res;
        }
    }

    int lower_bound(int x) {
        return lower_bound(1, 1, n, x);
    }

    void update(int l, int r, int lx, int rx, int x) {
        l = max(l, lower_bound(lx));
        r = min(r, lower_bound(rx + 1) - 1);
        if (l > r)
            return;
        update(1, 1, n, l, r, x);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return mx[v];
        } else {
            int tm = (tl + tr) >> 1, res = -inf;
            push(v);
            if (l <= tm)
                res = max(res, query(v << 1, tl, tm, l, r));
            if (r > tm)
                res = max(res, query(v << 1 | 1, tm + 1, tr, l, r));
            merge(v);
            return res;
        }
    }

    int query(int l, int r) {
        if (l > r)
            return -inf;
        return query(1, 1, n, l, r);
    }
};

void read(int& n, vector<int>& a) {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

int fast(int n, vector<int> a) {
    vector<vector<int>> poses(n + 2);
    for (int i = 1; i <= n; i++)
        poses[a[i]].push_back(i);

    if ((int) poses[1].size() == n)
        return 1;

    if (poses[1].empty())
        return 2;

//    vector<int> prv(n + 1, -1);
    RangeTree rt(n);

    for (int x = 1; x <= n + 1; x++) {
        poses[x].insert(poses[x].begin(), 0);
        poses[x].push_back(n + 1);

        int any = 0;

        for (int iter = 1; iter < (int) poses[x].size(); iter++) {
            int fr = poses[x][iter - 1];
            int to = poses[x][iter];

//            int mx = 0;
//            for (int i = fr + 1; i < to; i++)
//                    mx = max(mx, prv[i]);
            int mx = max(0, rt.query(fr + 1, to - 1));
            if (mx > fr)
                any = 1;
        }

        for (int iter = (int) poses[x].size() - 1; iter >= 1; iter--) {
            int fr = poses[x][iter - 1];
            int to = poses[x][iter];

//            int mx = -inf;
//            for (int i = 1; i < to; i++)
//                mx = max(mx, prv[i]);
            int mx = max(-inf, rt.query(1, to - 1));

            if (iter == 1) {
                rt.update(1, to - 1, -X, X, -inf);
//                for (int i = 1; i < to; i++)
//                    prv[i] = -inf;
            } else {
                if (x > 1) {
//                    for (int i = 1; i <= n; i++) {
//                        if (fr < prv[i] && prv[i] < to && i < to)
//                            prv[i] = fr;
//                    }
                    rt.update(1, to - 1, fr + 1, to - 1, fr);
                } else
//                    for (int i = fr + 1; i < to; i++)
//                        prv[i] = fr;
                rt.update(fr + 1, to - 1, -X, X, fr);
            }

//            if (to <= n)
//                prv[to] = x > 1 ? mx : to;

            rt.update(to, to, -X, X, x > 1 ? mx : to);
        }

//        for (int i = 1; i <= n; i++)
//            cout << prv[i] << " ";
//        cout << "\n";

//        for (int i = 1; i < n; i++)
//            assert(prv[i] <= prv[i + 1]);

        if (x > 1 && !any)
            return x;
    }

    return n + 2;
}

void work() {
    int n;
    vector<int> a;
    read(n, a);
    cout << fast(n, a) << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}