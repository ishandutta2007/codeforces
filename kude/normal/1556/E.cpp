#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

template <class S, S (*op)(S, S), S (*e)()> struct SparseTable {
    int n;
    std::vector<int> floor_lg;
    std::vector<std::vector<S>> d;
    explicit SparseTable(std::vector<S>&& a): n(a.size()), floor_lg(n + 1) {
        if (n == 0) return;
        int frog = 0;
        for(int i = 1; i <= n; frog++) {
            int j = std::min(n + 1, 2 * i);
            for(; i < j; i++) floor_lg[i] = frog;
        }
        d.resize(frog);
        d[0] = std::move(a);
        for(int p = 0, w = 1; p < frog - 1; p++, w *= 2) {
            int last = n - 2 * w;
            d[p + 1].resize(last + 1);
            for(int i = 0; i <= last; i++) d[p + 1][i] = op(d[p][i], d[p][i + w]);
        }
    }
    explicit SparseTable(const std::vector<S>& a): SparseTable(std::vector<S>(a)) {}

    S query(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        if (l >= r) return e();
        int w = r - l;
        int p = floor_lg[w];
        return op(d[p][l], d[p][r - (1 << p)]);
    }
};

ll op_min(ll x, ll y) {
    return min(x, y);
}
ll e_min() { return 1e18; }
ll op_max(ll x, ll y) {
    return max(x, y);
}
ll e_max() { return -1e18; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    VL a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        ll x;
        cin >> x;
        a[i] = x - a[i];
    }
    VL s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];
    SparseTable<ll, op_min, e_min> st_min(s);
    SparseTable<ll, op_max, e_max> st_max(s);
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (s[l] != s[r] || st_min.query(l, r) < s[l]) {
            cout << -1 << '\n';
        } else {
            cout << st_max.query(l, r) - s[l] << '\n';
        }
    }
}