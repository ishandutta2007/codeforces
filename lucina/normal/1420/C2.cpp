#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int64_t INF = 1e12;
int n, q;
int a[nax];
inline void upd_max(int64_t &a, int64_t b) {
    a = max(a, b);
}
inline void upd_min(int64_t &a, int64_t b) {
    a = min(a, b);
}

struct node {
    int64_t m00;
    int64_t m01;
    int64_t m10;
    int64_t m11;

    node(int64_t m00 = -INF, int64_t m01 = -INF, int64_t m10 = -INF, int64_t m11 = -INF ) : m00(m00), m01(m01), m10(m10), m11(m11) {}

    friend node operator +(node l, node r) {
        node res;
        auto &[m00, m01, m10, m11] = res;
        upd_max(m00, max(l.m00, r.m00));
        upd_max(m01, max(l.m01, r.m01));
        upd_max(m10, max(l.m10, r.m10));
        upd_max(m11, max(l.m11, r.m11));
        upd_max(m00, l.m00 + r.m10);
        upd_max(m00, l.m01 + r.m00);
        upd_max(m01, l.m00 + r.m11);
        upd_max(m01, l.m01 + r.m01);
        upd_max(m10, l.m10 + r.m10);
        upd_max(m10, l.m11 + r.m00);
        upd_max(m11, l.m10 + r.m11);
        upd_max(m11, l.m11 + r.m01);

        return res;
    }
};
node sg[nax << 2];

void update(int v, int x, int y, int pos, int64_t val) {
    if (x == y) {
        sg[v] = {val, -INF, -INF, -val};
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(v << 1, x, mid, pos, val);
        else update(v << 1 | 1, mid + 1, y, pos, val);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}


void solve() {
    cin >> n >> q;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }

    cout << sg[1].m00 << '\n';

    for (int i = 1 ; i <= q ; ++ i) {
        int l, r;
        cin >> l >> r;
        swap(a[l], a[r]);
        update(1, 1, n, l, a[l]);
        update(1, 1, n, r, a[r]);
        cout << sg[1].m00 << '\n';
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}