#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a[405];
int n;
int ff[405][405];
int check(int x) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (x >= a[i]) {
            ans += x / a[i];
            x %= a[i];
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int c = a[i] - 1;
        for (int j = i; j <= n; j++) {
            if (c >= a[j]) {
                ff[i][j] = c / a[j];
                c %= a[j];
            }
        }
    }
    int best = 2e9 + 1000;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int cc = 0;
            int tot = 0;
            for (int k = 1; k <= j; k++) {
                cc += ff[i - 1][k] * a[k];
                tot += ff[i - 1][k];
            }
            cc += a[j];
            tot++;
            if (check(cc) > tot) best = min(best, cc);
        }
    }
    if (best > 2e9 + 100) best = -1;
    cout << best;
    return 0;
}