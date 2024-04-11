#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
#define tp tuple
#define pi pair
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
typedef long long ll;
typedef double db;
const int N = 5e5 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int n, q;
int a[3][N];
vector<pi<int, int>> g[N];
ll sum[3][N];
ll tag1[N << 1], tag2[N << 1], mx1[N << 1], mx2[N << 1];
void updata(int p, int l, int r) {
    mx1[p] = max(mx1[ls], mx1[rs]);
    mx2[p] = max(mx2[ls], mx2[rs]);
}
void build(int p, int l, int r) {
    tag1[p] = tag2[p] = -oo;
    if(l == r) {
        mx1[p] = sum[0][l + 1] - sum[1][l];
        mx2[p] = -oo;
        return;
    }
    build(ls, l, mid), build(rs, mid + 1, r);
    updata(p, l, r);
    return;
}
void down(int p, ll v1, ll v2) {
    mx2[p] = max(mx2[p], v1);
    tag1[p] = max(tag1[p], v1);
    tag2[p] = max(tag2[p], v2);
}
void pushdown(int p, int l, int r) {
    down(ls, tag1[p], tag2[p]);
    down(rs, max(max(mx1[ls], mx2[ls]) + tag2[p], tag1[p]), tag2[p]);
    tag1[p] = tag2[p] = -oo;
}
void modify(int p, int l, int r, int L, int R, ll &v1, ll &v2) {
    if(L <= l && r <= R) {
        down(p, v1, v2);
        v1 = max(v1, max(mx1[p], mx2[p]) + v2);
        return;
    }
    pushdown(p, l, r);
    if(L <= mid) modify(ls, l, mid, L, R, v1, v2);
    if(R > mid) modify(rs, mid + 1, r, L, R, v1, v2);
    updata(p, l, r);
}
ll calc(int p, int l, int r) {
    if(l == r) {
        // cout << mx2[p] << endl;
        return mx2[p] + sum[2][n] - sum[2][l - 1] + sum[1][l];
    }
    pushdown(p, l, r);
    return max(calc(ls, l, mid), calc(rs, mid + 1, r));
}
void solveone() {
    cin >> n >> q;
    for(int i = 0; i < 3; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    }
    build(1, 0, n);
    for(int i = 1; i <= q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        g[r].emplace_back(l, k);
    }
    for(int i = 1; i <= n; i++) for(auto [l, k] : g[i]) {
        ll v1 = -oo, v2 = -k;
        modify(1, 0, n, l - 1, i, v1, v2);
    }
    ll ans = calc(1, 0, n);
    cout << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solveone();
    return 0;
}