#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e6 + 100;
int w;
ll add[maxN];
int a[maxN];
const int LG = 20;
int up[maxN][LG];
int lg[maxN];
int get_mx(int l, int r) {
    int t = lg[r - l + 1];
    return max(up[l][t], up[r - (1 << t) + 1][t]);
}
void upd(int l, int r, ll val) {
    add[l] += val;
    add[r + 1] -= val;
}
void solve() {
    int len;
    cin >> len;
    for (int i = 1; i <= len; i++) {
        cin >> a[i];
        up[i][0] = a[i];
    }
    for (int j = 0; j + 1 < LG; j++) {
        for (int i = 1; i + (1 << (j + 1)) - 1 <= len; i++) {
            up[i][j + 1] = max(up[i][j], up[i + (1 << j)][j]);
        }
    }

    int n = w;

    for (int i = 1; i <= len; i++) {
        int l = max(len + i - n, 1);
        int r = min(i, len);
        int mx = get_mx(l, r);
        if (n - i >= len) mx = max(mx, 0);
        upd(i, i, mx);
    }

    for (int i = n; i >= n - len + 1; i--) {
        if (i <= len) break;
        int l = max(len + i - n, 1);
        int r = min(i, len);
        int mx = get_mx(l, r);
        if (i - 1 >= len) mx = max(mx, 0);
        upd(i, i, mx);
    }

    int mx = max(0, get_mx(1, len));
    if (len + 1 <= n - len) {
        upd(len + 1, n - len, mx);
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    lg[1] = 0;
    for (int i = 2; i < maxN; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        solve();
    }
    for (int i = 1; i <= w; i++) {
        add[i] += add[i - 1];
        cout << add[i] << " ";
    }
    return 0;
}