#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define int long long
const int maxN = 2 * (int)1e5 + 100;
int fenw[2][maxN];
int n;
void upd(int ind, int where, int val) {
    while (where <= n) {
        fenw[ind][where] += val;
        where = (where | (where - 1)) + 1;
    }
}
int get(int ind, int r) {
    int ans = 0;
    while (r > 0) {
        ans += fenw[ind][r];
        r = r & (r - 1);
    }
    return ans;
}
int get(int ind, int l, int r) {
    if (l > r) return 0;
    if (r == 0) return 0;
    return get(ind, r) - get(ind, l - 1);
}
int k, a[2], q;
int val[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> a[1] >> a[0] >> q;
    for (int i = 1; i <= q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int day, by;
            cin >> day >> by;
            for (int j = 0; j < 2; j++) {
                upd(j, day, -min(val[day], a[j]));
            }

            val[day] += by;
            for (int j = 0; j < 2; j++) {
                upd(j, day, min(val[day], a[j]));
            }
        }
        else {
            int p;
            cin >> p;
            cout << get(1, p + k, n) + get(0, 1, p - 1) << '\n';
        }
    }
    return 0;
}