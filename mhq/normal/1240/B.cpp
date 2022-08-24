#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int mx[maxN];
int mn[maxN];
int a[maxN];
int tst;
int n;
bool hs[maxN];
int id[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) {
        cin >> n;
        for (int i = 0; i <= n; i++) {
            mx[i] = -1;
            mn[i] = n + 1;
            hs[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            hs[a[i]] = true;
        }
        int sz = 1;
        for (int i = 1; i <= n; i++) {
            if (hs[i]) {
                id[i] = sz;
                sz++;
            }
        }
        sz--;
        for (int i = 1; i <= n; i++) {
            a[i] = id[a[i]];
            mx[a[i]] = max(mx[a[i]], i);
            mn[a[i]] = min(mn[a[i]], i);
        }
        n = sz;
        int best = n + 10;
        int r = 1;
        for (int i = 1; i <= n; i++) {
            r = max(r, i);
            while (r + 1 <= n && mx[r] <= mn[r + 1]) {
                r++;
            }
            best = min(best, n - (r - i + 1));
        }
        cout << best << '\n';
    }
    return 0;
}