#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 400111, inf = 1000111222;
const ll mod = 998244353;

int n;
pair<int, int> x[max_n];
pair<int, int> y[max_n];
int on[max_n];

vector<int> comp;

int get_small(int large) {
    return lower_bound(comp.begin(), comp.end(), large) - comp.begin();
}
int get_large(int sm) {
    return comp[sm];
}

template<typename T>
struct segment_tree {
    T sum[4 * max_n] = {0};

    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            sum[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void update(int v, int l, int r, int x, T value) {
        if (l == r) {
            sum[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

ll cost[max_n];


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int mxx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> x[i].S >> y[i].S >> on[i];
        comp.push_back(x[i].S);
        comp.push_back(y[i].S);
        mxx = max(mxx, x[i].S);
    }
    comp.PB(0);
    sort(comp.begin(), comp.end());
    comp.PB(comp.back() + 1);
    for (int i = 0; i < n; ++i) {
        x[i].F = get_small(x[i].S);
        y[i].F = get_small(y[i].S);
    }
    segment_tree<ll> st;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.emplace_back(x[i].F, i);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        int ind = v[i].S;
        cost[ind] = x[ind].S - y[ind].S + st.get_sum(1, 0, max_n - 1, y[ind].F, x[ind].F);
        cost[ind] %= mod;
        st.update(1, 0, max_n - 1, x[i].F, cost[ind]);
    }
    ll ans = mxx + 1;
    for (int i = 0; i < v.size(); ++i) {
        int ind = v[i].S;
        if (on[ind]) {
            ans += cost[ind];
            ans %= mod;
        }
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}