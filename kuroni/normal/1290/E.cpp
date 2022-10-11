#include <bits/stdc++.h>
using namespace std;

const int N = 150005, INF = 1E9 + 7;

int n, u, a[N];

enum operation {
    CHMIN,
    CHMAX,
    ADD
};

struct node {
    int mi, mic, mis;
    int mx, mxc, mxs;
    int lz;
    long long sum;

    node(int _n = 0) {
        mi = mx = _n; mic = mxc = 1;
        mis = INF; mxs = -INF;
        lz = 0;
        sum = _n;
    }

    node operator+(const node &oth) const {
        node ans;
        ans.sum = sum + oth.sum;
        ans.mi = min(mi, oth.mi);
        if (mi == oth.mi) {
            ans.mic = mic + oth.mic;
            ans.mis = min(mis, oth.mis);
        } else if (mi < oth.mi) {
            ans.mic = mic;
            ans.mis = min(mis, oth.mi);
        } else {
            ans.mic = oth.mic;
            ans.mis = min(mi, oth.mis);
        }
        ans.mx = max(mx, oth.mx);
        if (mx == oth.mx) {
            ans.mxc = mxc + oth.mxc;
            ans.mxs = max(mxs, oth.mxs);
        } else if (mx > oth.mx) {
            ans.mxc = mxc;
            ans.mxs = max(mxs, oth.mx);
        } else {
            ans.mxc = oth.mxc;
            ans.mxs = max(mx, oth.mxs);
        }
        return ans;
    }
};

struct segment_tree {
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    node tr[4 * N];

    bool break_condition(int i, int v, operation op) {
        switch (op) {
            case CHMIN:
                return tr[i].mx <= v;
            case CHMAX:
                return tr[i].mi >= v;
            case ADD:
                return false;
        }
    }

    bool tag_condition(int i, int v, operation op) {
        switch (op) {
            case CHMIN:
                return tr[i].mxs < v;
            case CHMAX:
                return tr[i].mis > v;
            case ADD:
                return true;
        }
    }

    void tag(int l, int r, int i, int v, operation op) {
        switch (op) {
            case CHMIN: {
                tr[i].sum -= 1LL * (tr[i].mx - v) * tr[i].mxc;
                if (tr[i].mi == tr[i].mx) {
                    tr[i].mi = v;
                } else if (tr[i].mis == tr[i].mx) {
                    tr[i].mis = v;
                }
                tr[i].mx = v;
                return;
            }
            case CHMAX: {
                tr[i].sum += 1LL * (v - tr[i].mi) * tr[i].mic;
                if (tr[i].mx == tr[i].mi) {
                    tr[i].mx = v;
                } else if (tr[i].mxs == tr[i].mi) {
                    tr[i].mxs = v;
                }
                tr[i].mi = v;
                return;
            }
            case ADD: {
                tr[i].sum += 1LL * (r - l + 1) * v;
                tr[i].lz += v;
                tr[i].mi += v; tr[i].mis += v;
                tr[i].mx += v; tr[i].mxs += v;
                return;
            }
        }
    }

    void push(int l, int r, int i) {
        tag(l, m, lc, tr[i].lz, ADD);
        tag(m + 1, r, rc, tr[i].lz, ADD);
        tr[i].lz = 0;
        for (operation op : {CHMIN, CHMAX}) {
            int v = (op == CHMIN ? tr[i].mx : tr[i].mi);
            if (!break_condition(lc, v, op)) {
                tag(l, m, lc, v, op);
            }
            if (!break_condition(rc, v, op)) {
                tag(m + 1, r, rc, v, op);
            }
        }
    }

    void build(int l, int r, int i, int v) {
        if (l == r) {
            tr[i] = node(v);
        } else {
            build(l, m, lc, v);
            build(m + 1, r, rc, v);
            tr[i] = tr[lc] + tr[rc];
        }
    }

    void update(int l, int r, int i, int L, int R, int v, operation op) {
        if (l > R || r < L || break_condition(i, v, op)) {
            return;
        } else if (L <= l && r <= R && tag_condition(i, v, op)) {
            tag(l, r, i, v, op);
        } else {
            push(l, r, i);
            update(l, m, lc, L, R, v, op);
            update(m + 1, r, rc, L, R, v, op);
            tr[i] = tr[lc] + tr[rc];
        }
    }

    long long query(int l, int r, int i, int L, int R) {
        if (l > R || r < L) {
            return 0;
        } else if (L <= l && r <= R) {
            return tr[i].sum;
        } else {
            push(l, r, i);
            return query(l, m, lc, L, R) + query(m + 1, r, rc, L, R);
        }
    }

#undef m
#undef lc
#undef rc
} le, ri;

struct fenwick_tree {
    int bit[N];

    void update(int u, int v) {
        for (; u <= n; u += u & -u) {
            bit[u] += v;
        }
    }
    
    int query(int u) {
        int ret = 0;
        for (; u > 0; u -= u & -u) {
            ret += bit[u];
        }
        return ret;
    }
} chk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    le.build(1, n, 1, N); ri.build(1, n, 1, -N);
    for (int i = 1; i <= n; i++) {
        cin >> u;
        a[u] = i;
    }
    for (int i = 1; i <= n; i++) {
        int pos = a[i];
        // initialize for the current position
        le.update(1, n, 1, pos, pos, 1, CHMIN);
        ri.update(1, n, 1, pos, pos, i, CHMAX);

        // shift for all right positions
        le.update(1, n, 1, pos + 1, n, 1, ADD);
        ri.update(1, n, 1, pos + 1, n, 1, ADD);

        // bound off left's right children and right's left children
        int cl = chk.query(pos);
        ri.update(1, n, 1, 1, pos - 1, cl, CHMIN);
        le.update(1, n, 1, pos + 1, n, cl + 2, CHMAX);

        // add pos to marked positions
        chk.update(pos, 1);

        cout << ri.query(1, n, 1, 1, n) - le.query(1, n, 1, 1, n) + 2LL * N * (n - i) + i << '\n';
    }
}