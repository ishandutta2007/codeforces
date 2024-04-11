#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Event {
    char op;
    int t, d, i;

    void read() {
        cin >> op;
        if (op == '+') {
            cin >> t >> d;
        } else if (op == '-') {
            cin >> i;
        } else if (op == '?') {
            cin >> t;
        }
    }
};

struct Node {
    ll rightest_group_last = 0;
    ll total_sum_len = 0;
    ll count = 0;
};

Node merge(Node l, Node r) {

    if (l.count == 0) {
        return r;
    } else if (r.count == 0) {
        return l;
    }

    Node res;

    res.total_sum_len = l.total_sum_len + r.total_sum_len;
    res.count = l.count + r.count;

    if (l.rightest_group_last + r.total_sum_len <= r.rightest_group_last) {
        res.rightest_group_last = r.rightest_group_last;
    } else {
        res.rightest_group_last = l.rightest_group_last + r.total_sum_len;
    }

    return res;
}

const int N = 3e5 + 5;

int n;
Event events[N];
int crd[N], sz;
Node tree[4 * N];

Node query(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
        return tree[v];
    } else {
        int tm = (tl + tr) >> 1;
        if (l <= tm) {
            if (r > tm) {
                return merge(
                    query(v << 1, tl, tm, l, r),
                    query(v << 1 | 1, tm + 1, tr, l, r)
                );
            } else {
                return query(v << 1, tl, tm, l, r);
            }
        } else {
            return query(v << 1 | 1, tm + 1, tr, l, r);
        }
    }
}

void update(int v, int tl, int tr, int pos, Node x) {
    if (tl == tr) {
        tree[v] = x;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            update(v << 1, tl, tm, pos, x);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos, x);
        }
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        events[i].read();
        crd[sz++] = events[i].t;
    }

    sort(crd, crd + sz);
    sz = unique(crd, crd + sz) - crd;

    for (int i = 1; i <= n; i++) {
        Event e = events[i];
        if (e.op == '+') {
            int pos = lower_bound(crd, crd + sz, e.t) - crd;
            Node x;
            x.total_sum_len = e.d;
            x.rightest_group_last = e.t + e.d;
            x.count = 1;
            update(1, 0, sz - 1, pos, x);
        } else if (e.op == '-') {
            e = events[e.i];
            int pos = lower_bound(crd, crd + sz, e.t) - crd;
            Node x;
            x.total_sum_len = 0;
            x.rightest_group_last = 0;
            x.count = 0;
            update(1, 0, sz - 1, pos, x);
        } else if (e.op == '?') {
            int pos = lower_bound(crd, crd + sz, e.t) - crd;
            Node x = query(1, 0, sz - 1, 0, pos);
            cout << max(0ll, x.rightest_group_last - e.t) << "\n";
        }
    }

    return 0;
}