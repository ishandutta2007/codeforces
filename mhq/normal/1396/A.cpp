#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e5 + 10;
ll a[maxN];
ll val[3][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= -1;
    }
    if (n == 1) {
        for (int c = 0; c < 3; c++) {
            cout << 1 << " " << 1 << '\n';
            if (c == 2) cout << a[1] << '\n';
            else cout << 0 << '\n';
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        ll his_val = (-a[i]) % n;
        ll other_val = (a[i] + his_val);
        assert(other_val % n == 0);
        other_val /= n;
        other_val -= his_val;
        assert(n * other_val + (n - 1) * his_val == a[i]);
        val[0][i] = other_val;
        if (i < n) val[1][i] = his_val;
        else val[2][i] = his_val;
    }
    for (int c = 0; c < 3; c++) {
        int l, r;
        if (c == 0) l = 1, r = n;
        else if (c == 1) l = 1, r = n - 1;
        else l = 2, r = n;
        cout << l << " " << r << '\n';
        for (int i = l; i <= r; i++) {
            cout << val[c][i] * (r - l + 1) << " ";
        }
        cout << '\n';
    }
    return 0;
}