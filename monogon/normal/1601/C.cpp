
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

ll inversions(vector<ll> &a, int l, int r) {
    if(l >= r) return 0;
    int m = (l + r) / 2;
    ll ans = inversions(a, l, m) + inversions(a, m + 1, r);
    int i = l;
    rep(j, m + 1, r + 1) {
        while(a[i] <= a[j] && i <= m) i++;
        ans += m - i + 1;
    }
    inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1);
    return ans;
}

// point increase, range minimum

const int N = 1e6 + 5;
ll tree[4 * N], lazy[4 * N];

void build(int i, int l, int r) {
    lazy[i] = 0;
    if(l == r) {
        tree[i] = l;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

ll get(int i) {
    return tree[i] + lazy[i];
}

void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    tree[i] = get(i);
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}

// ll query(int i, int l, int r, int L, int R) {
//     if(r < L || R < l) return LLONG_MAX;
//     if(L <= l && r <= R) return get(i);
//     prop(i, l, r);
//     int m = (l + r) / 2;
//     return min(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
// }

void upd(int i, int l, int r, int L, int R, ll x) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        return;
    }
    int m = (l + r) / 2;
    prop(i, l, r);
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = min(get(2 * i + 1), get(2 * i + 2));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    vector<pii> veA;
    rep(i, 0, n) {
        cin >> a[i];
        veA.push_back({a[i], i});
    }
    rep(i, 0, m) {
        cin >> b[i];
    }
    sort(all(veA));
    sort(all(b));
    ll ans = inversions(a, 0, n - 1);
    int aidx = 0;
    int bidx = 0;
    build(0, 0, n);
    while(bidx < m) {
        int right = bidx;
        ll x = b[bidx];
        while(right < m && b[right] == x) right++;
        while(aidx < n && veA[aidx].first < x) {
            // insert number < x
            int pos = veA[aidx].second + 1;
            upd(0, 0, n, pos, n, -2);
            aidx++;
        }
        int A = aidx;
        while(aidx < n && veA[aidx].first <= x) {
            // insert number = x
            int pos = veA[aidx].second + 1;
            upd(0, 0, n, pos, n, -1);
            aidx++;
        }
        ans += 1LL * (right - bidx) * (A + tree[0] + lazy[0]);
        for(int i = aidx - 1; i >= A; i--) {
            upd(0, 0, n, veA[i].second + 1, n, -1);
        }
        bidx = right;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}