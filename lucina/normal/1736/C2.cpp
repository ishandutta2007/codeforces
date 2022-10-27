#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int INF = 1e9;


int a[nax];
int n, nq;
int good[nax];
int good_l_pre[nax];
int f[nax];
int64_t sum_good[nax];
int64_t sum_f[nax];


struct node {
    int x;
    node(int x = INF) : x(x) {}
};

node operator +(const node &a, const node &b) {
    return node(min(a.x, b.x));
}

template <typename T>
struct fast_segtree {

    int n;
    T t[nax << 2];
    fast_segtree(int n) : n(n) {}
    void pull (int v) {
        t[v >> 1] = t[v] + t[v ^ 1];
    }

    void update(int v, T val) {
        -- v;
        for (t[v += n] = val ; v > 1 ; v >>= 1) {
            pull(v);
        }
    }

    T query(int l, int r) {
        -- l, r;
        T res = t[l + n];
        for (l += n, r += n ; l < r ; l >>= 1, r >>= 1) {
            if (l & 1) res = res + t[l ++];
            if (r & 1) res = res + t[-- r];
        }
        return res;
    }
};


bool good_range(int l, int r, fast_segtree <node> &sg) {
    return sg.query(l, r).x >= 1 - l;
}

void solve() {
    cin >> n;

    fast_segtree <node> sg(n);
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        a[i] -= i;
        sg.update(i, node(a[i]));
    }

    auto good_r = [&](int l) -> int {
        int L = l, R = n, ans = l;
        while (L <= R) {
            int mid = L + R >> 1;
            if (good_range(l, mid, sg)) {
                ans = mid;
                L = mid + 1;
            } else R = mid - 1;
        }
        return ans;
    };

    auto good_l = [&](int r) -> int {
        int L = 1, R = r, ans = r;
        while (L <= R) {
            int mid = L + R >> 1;
            if (good_range(mid, r, sg)) {
                ans = mid;
                R = mid - 1;
            } else L = mid + 1;
        }
        return ans;
    };

    int64_t ans = 0;

    for (int l = 1, r = 1 ; l <= n ; ++ l) {
        good[l] = f[l] = good_r(l);
        good_l_pre[l] = good_l(l);
        sum_good[l] = sum_good[l - 1] + good[l];
        ans += good[l] - l + 1;
    }

    for (int l = 1 ; l <= n ; ++ l) {
        int to = good[l] + 1;
        if (to <= n) {
            int s = a[to];
            a[to] = 3 * n;
            sg.update(to, a[to]);
            f[l] = good_r(l);
            a[to] = s;
            sg.update(to, a[to]);
        }
        sum_f[l] = sum_f[l - 1] + f[l];
    }

    cin >> nq;
    while (nq --) {
        int x, v;
        cin >> x >> v;
        int lx1 = good_l_pre[x - 1];
        int lx = good_l_pre[x];
        v -= x;
        swap(a[x], v);
        sg.update(x, a[x]);
        int64_t cur = ans;

        int lx_now = good_l(x);
        if (lx_now > lx) {
            cur -= sum_good[lx_now - 1] - sum_good[lx - 1] - 1ll * (x - 1) * (lx_now - lx);
        }
        if (lx1 && lx1 < lx) {
            if (lx_now <= lx - 1) {
                cur += sum_f[lx - 1] - sum_f[lx_now - 1] - 1ll * (x - 1) *(lx - lx_now);
            }
        }
        cout << cur << '\n';

        swap(a[x], v);
        sg.update(x, a[x]);
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (T = 1 ; T -- ;) {
        solve();
    }
}