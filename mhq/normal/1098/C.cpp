#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll s;
int n;
const int maxN = (int)1e5 + 10;
int p[maxN];
int d[maxN];
bool go(int deg) {
    int he = 2;
    // i, i + 1, .. n
    ll curs = s;
    ll can = deg;
    ll already = 0;
    d[1] = 1;
    curs--;
    for (int i = 2; i <= n; i++) {
        if (already == can) {
            he++;
            already = 0;
            can *= deg;
        }
        ll mx = ((1LL * he + 1 + he + 1 - i - 1 + n) * (n - i)) / 2;
        if (curs <= he + mx) {
            already++;
            d[i] = he;
            curs -= he;
        }
        else {
            he++;
            d[i] = he;
            curs -= he;
        }
        // he + 1 + .. +
        // he + .. + he - i + n
        // (n - i + 1) * (2 * he - i + n)
    }
    return (curs == 0);
}
int can[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> s;
    if ((2 * s > 1LL * n * (n + 1)) || (s < 2 * n - 1)) {
        cout << "No";
        return 0;
    }
    int l = 0;
    int r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (go(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    go(r);
    cout << "Yes" << '\n';
    int le = 1;
    for (int i = 1; i <= n; i++) {
        can[i] = r;
    }
    for (int i = 2; i <= n; i++) {
        if (can[le] == 0) le++;
        while (d[le] + 1 < d[i]) le++;
        p[i] = le;
        can[le]--;
        cout << p[i] << " ";
    }
    return 0;
}