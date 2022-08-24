#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, q;
const int maxN = 4e5 + 10;
int x[maxN], y[maxN];
int parx[maxN], pary[maxN];
int mn[maxN];
int mx[maxN];
bool can(int p) {
    for (int i = 0; i <= n; i++) {
        mn[i] = m + 1;
        mx[i] = -1;
    }
    map < pair < int, int >, bool > mp;
    for (int i = 1; i <= p; i++) {
        if (x[i] % 2 == 1 && y[i] % 2 == 1) {
            parx[i] = x[i] + 1;
            pary[i] = y[i] + 1;
            if (mp.count(make_pair(parx[i], pary[i]))) return false;
            mp[{x[i], y[i]}] = 1;
            mx[parx[i]] = max(mx[parx[i]], pary[i]);
        }
        else {
            parx[i] = x[i] - 1;
            pary[i] = y[i] - 1;
            mn[parx[i]] = min(mn[parx[i]], pary[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        mn[i] = min(mn[i], mn[i - 1]);
    }
    for (int i = n - 1; i >= 1; i--) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    for (int i = 1; i <= p; i++) {
        if (x[i] % 2 == 1) {
            if (mn[x[i]] <= y[i]) {
                return false;
            }
        }
        else {
            if (mx[x[i]] >= y[i]) return false;
        }
    }
//    cout << " C " << endl;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    n *= 2;
    m *= 2;
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];
        if (x[i] % 2 == 1) {
            x[i]++;
            y[i]++;
        }
        else {
            x[i]--;
            y[i]--;
        }
    }
//    can(3);
//    exit(0);
    int l = 0;
    int r = q + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (can(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    for (int i = 1; i <= l; i++) cout << "YES\n";
    for (int i = 1; i <= q - l; i++) cout << "NO\n";
    return 0;
}