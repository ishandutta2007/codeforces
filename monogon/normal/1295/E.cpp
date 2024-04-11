
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, p[N], invp[N];
ll a[N], tree[4 * N], lazy[4 * N], f[N], g;

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = f[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

void update(int i, int l, int r, int idx, ll x) {
    if(r <= idx) lazy[i] += x;
    if(l < r && lazy[i] != 0) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    tree[i] += lazy[i];
    lazy[i] = 0;
    if(r <= idx || l > idx) return;
    int m = (l + r) / 2;
    update(2 * i + 1, l, m, idx, x);
    update(2 * i + 2, m + 1, r, idx, x);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        invp[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[invp[i]];
    }
    build(0, 0, n);
    ll best = LLONG_MAX;
    for(int i = 1; i < n; i++) {
        update(0, 0, n, p[i] - 1, 2 * a[i]);
        g -= a[i];
        best = min(best, g + tree[0] + lazy[0]);
    }
    cout << best << endl;
}