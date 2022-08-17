#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_lev = 18, inf = 1000111222;
ll a[max_n];
ll b[max_n];
ll c[max_n];
ll pa[max_n];
ll pb[max_n];
ll pc[max_n];

ll get_sum(ll a[], int from, int to) {
    ll ans = a[to];
    if (from) {
        ans -= a[from - 1];
    }
    return ans;
}

template<typename T, int z = 1> // z = -1 for maximum
struct sparse_table {
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = z * a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return z * inf;
        }
        const int lev = 31 - __builtin_clz(r - l + 1);
        return z * min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

sparse_table<ll> st_min;
sparse_table<ll, -1> st_max;


int n, q;

ll solve(int l, int r) {
    if (get_sum(pa, l, r) != get_sum(pb, l, r)) {
        return -1;
    }
    ll ps_min = st_min.get_min(l, r);
    ll ps_max = st_max.get_min(l, r);
    if (l) {
        ps_min -= pc[l - 1];
        ps_max -= pc[l - 1];
    }
    if (ps_min < 0) {
        return -1;
    }
    return ps_max;

}


vector<ll> bl;
int b_ind[max_n];


int main() {
    //freopen("input.txt", "r", stdin)
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pa[i] = a[i];
        if (i) pa[i] += pa[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        pb[i] = b[i];
        if (i) pb[i] += pb[i - 1];
        c[i] = b[i] - a[i];
        pc[i] = c[i];
        if (i) pc[i] += pc[i - 1];
    }
    st_min.init(n, pc);
    st_max.init(n, pc);

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << solve(l, r) << "\n";
    }

    return 0;
}