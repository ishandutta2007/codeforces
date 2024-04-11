#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int par[maxN];
int n, k;
bool isPower(int n) {
    int dd = (n + 1);
    return ((dd & (dd - 1)) == 0);
}
bool can[105][105];
bool ok(int n, int k) {
    if (n < 100) {
        if (!can[n][k]) {
            return false;
        }
    }
    else {
        if (k == 0) {
            if (!isPower(n)) {
                return false;
            }
        }
        if (k == 1) {
            if (isPower(n)) {
                return false;
            }
        }
        if (k > (n - 3) / 2) {
            return false;
        }
    }
    return true;
}
void solve(int l, int r, int k) {
    int n = (r - l + 1);
    if (n == 1) {
        assert(k == 0);
        return;
    }
    assert((n - 3) / 2 >= k && k >= 0);
    if (n <= 40) {
        for (int c1 = 1; c1 < n; c1 += 2) {
            int c2 = n - 1 - c1;
            int fl = max(c1, c2) >= 2 * min(c1, c2);
            for (int p = 0; p + fl <= k && p <= c1; p++) {
                if (can[c1][p] && can[c2][k - fl - p]) {
                    par[l + 1] = l;
                    par[l + c1 + 1] = l;
                    solve(l + 1, l + c1, p);
                    solve(l + c1 + 1, r, k - fl - p);
                    return;
                }
            }
        }
        assert(false);
    }
    if (k == 0) {
        assert(isPower(n));
        int c1 = (n - 1) / 2;
        par[l + 1] = l;
        par[l + c1 + 1] = l;
        solve(l + 1, l + c1, 0);
        solve(l + c1 + 1, r, 0);
        return;
    }
    else {
        for (int c1 = 1; c1 < n; c1 += 2) {
            int c2 = n - 1 - c1;
            int fl = max(c1, c2) >= 2 * min(c1, c2);
            for (int p = 0; p + fl <= k && p <= c1; p++) {
                if (ok(c1, p) && ok(c2, k - fl - p)) {
                    par[l + 1] = l;
                    par[l + c1 + 1] = l;
                    solve(l + 1, l + c1, p);
                    solve(l + c1 + 1, r, k - fl - p);
                    return;
                }
            }
        }
        assert(false);
    }

}
void go() {
    can[1][0] = true;
    for (int i = 3; i < 100; i += 2) {
        for (int c1 = 1; c1 < (i - 1); c1 += 2) {
            int c2 = i - 1 - c1;
            int fl = (max(c1, c2) >= 2 * min(c1, c2));
            for (int d = 0; d <= c1; d++) {
                for (int p = 0; p <= c2; p++) {
                    if (can[c1][d] && can[c2][p]) {
                        can[i][d + p + fl] = true;
                    }
                }
            }
        }
    }
   /* for (int i = 1; i <= 100; i += 2) {
        if (can[i][0]) {
            cout << i << " HI " << endl;
        }
        for (int j = 2; j <= (i - 3) / 2; j++) {
            assert(can[i][j]);
        }
    }
    exit(0);*/
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    go();
    cin >> n >> k;
    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }
    if (!ok(n, k)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    solve(1, n, k);
    for (int i = 1; i <= n; i++) cout << par[i] << " ";
    return 0;
}