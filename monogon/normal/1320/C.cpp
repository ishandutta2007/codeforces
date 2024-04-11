
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, p;
ll a[N], ca[N], b[N], cb[N], x[N], y[N], z[N];
vector<pair<ll, int>> v;
vector<pair<ll, ll>> vb;

ll seg[4 * N], lazy[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        seg[i] = -vb[l - 1].second;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
}
void prop(int i, int l, int r) {
    seg[i] += lazy[i];
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
ll query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return INT_MIN;
    prop(i, l, r);
    if(L <= l && r <= R) return seg[i];
    int m = (l + r) / 2;
    return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int L, int R, int x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> ca[i];
        v.emplace_back(a[i], -i);
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i] >> cb[i];
        vb.emplace_back(b[i], cb[i]);
    }
    sort(vb.begin(), vb.end());
    sort(b + 1, b + m + 1);
    for(int i = 1; i <= p; i++) {
        cin >> x[i] >> y[i] >> z[i];
        v.emplace_back(x[i], i);
    }
    sort(v.begin(), v.end());
    build(0, 1, m);
    ll ans = INT_MIN;
    for(auto p : v) {
        int i = p.second;
        if(i < 0) {
            ans = max(ans, query(0, 1, m, 1, m) - ca[-i]);
        }else {
            int idx = upper_bound(b + 1, b + m + 1, y[i]) - b;
            upd(0, 1, m, idx, m, z[i]);
        }
    }
    cout << ans << endl;
}