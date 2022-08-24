#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int a[maxN];
int n, m;
int upd(int l, int r, int a) {
    if (a > r) return m + 10000;
    if (a < l) return l;
    return a;
}
bool check(int x) {
    if (x >= m) return true;
    int mn_before = 0;
    for (int i = 1; i <= n; i++) {
        int fr = a[i];
        int to = (a[i] + x);
        if (to < m) {
            if (to < mn_before) return false;
            if (fr > mn_before) mn_before = fr;
        }
        else {
            int cc = min(upd(fr, m - 1, mn_before), upd(0, to - m, mn_before));
            if (cc >= m) return false;
            mn_before = cc;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0;
    int r = m + 10;
    if (check(l)) {
        cout << 0;
        return 0;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}