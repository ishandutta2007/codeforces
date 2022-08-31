#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
const int maxN = 5005;
int a[maxN];
int c[maxN][maxN];
int n, k;
int pref[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
        pref[i] = pref[i - 1] + a[i];
    }
    if (pref[n] < k) {
        cout << 1 << '\n';
        return 0;
    }
    for (int l = 1; l <= n; l++) {
        for (int r = l + 1; r <= n; r++) {
            if (pref[r] - pref[l - 1] <= k) {
                int tot_ones = pref[r] - pref[l - 1];
                int tot_zeroes = (r - l + 1) - tot_ones;
                if (a[l] == 0) {
                    tot_ones--;
                }
                else {
                    tot_zeroes--;
                }
                if (a[r] == 0) {
                    tot_ones--;
                }
                else {
                    tot_zeroes--;
                }
                if (tot_ones < 0 || tot_zeroes < 0) continue;
                ans = sum(ans, c[tot_ones + tot_zeroes][tot_ones]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}