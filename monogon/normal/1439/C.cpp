
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

const int N = 2e5 + 5;
ll a[N], sum[4 * N], mn[4 * N], lazy[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        sum[i] = mn[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
    mn[i] = mn[2 * i + 2];
}

void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    sum[i] = lazy[i] * (r - l + 1);
    mn[i] = lazy[i];
    if(l < r) {
        lazy[2 * i + 1] = lazy[i];
        lazy[2 * i + 2] = lazy[i];
    }
    lazy[i] = 0;
}

ll ughsum(int i, int l, int r) {
    return lazy[i] == 0 ? sum[i] : lazy[i] * (r - l + 1);
}
ll ughmn(int i) {
    return lazy[i] == 0 ? mn[i] : lazy[i];
}

// first index <= y
int get(int i, int l, int r, ll y) {
    prop(i, l, r);
    if(l == r) {
        return l + (mn[i] > y);
    }
    int m = (l + r) / 2;
    if(ughmn(2 * i + 1) <= y) return get(2 * i + 1, l, m, y);
    return get(2 * i + 2, m + 1, r, y);
}
// sum of elements in [L, ...] exceeding y
int getsumidx(int i, int l, int r, ll y) {
    prop(i, l, r);
    if(l == r) {
        return l + (sum[i] <= y);
    }
    int m = (l + r) / 2;
    ll s = ughsum(2 * i + 1, l, m);
    if(s <= y) {
        return getsumidx(2 * i + 2, m + 1, r, y - s);
    }else {
        return getsumidx(2 * i + 1, l, m, y);
    }
}
ll query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    prop(i, l, r);
    if(L <= l && r <= R) return sum[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
void upd(int i, int l, int r, int L, int R, ll y) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] = y;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, y);
    upd(2 * i + 2, m + 1, r, L, R, y);
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
    mn[i] = mn[2 * i + 2];
}

// void pront(int n) {
//     rep(i, 1, n + 1) {
//         cerr << query(0, 1, n, i, i) << ' ';
//     }
//     cerr << '\n';
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    build(0, 1, n);
    while(q--) {
        int ty, x;
        ll y;
        cin >> ty >> x >> y;
        if(ty == 1) {
            // update
            int idx = get(0, 1, n, y);
            if(idx <= x) {
                upd(0, 1, n, idx, x, y);
            }
            // pront(n);
        }else {
            // query
            int ans = 0;
            while(true) {
                int idx = max(x, get(0, 1, n, y));
                if(idx == n + 1) break;
                ll s = (idx == 1 ? 0 : query(0, 1, n, 1, idx - 1));
                int jdx = getsumidx(0, 1, n, s + y);
                assert(idx != jdx);
                ans += jdx - idx;
                y -= query(0, 1, n, idx, jdx - 1);
                x = jdx;
            }
            cout << ans << '\n';
        }
    }
}