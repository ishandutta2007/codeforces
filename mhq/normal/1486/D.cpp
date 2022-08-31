#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int n, k;
int a[maxN];
int b[maxN];
int pref[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int r = n + 1;
    int l = 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= mid) b[i] = 1;
            else b[i] = -1;
        }
        bool ok = false;
        int mn = 1e9;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + b[i];
            if (i - k >= 0) mn = min(mn, pref[i - k]);
            if (pref[i] > mn) ok = true;
        }
        if (ok) l = mid;
        else r = mid;
    }
    cout << l << '\n';
    return 0;
}