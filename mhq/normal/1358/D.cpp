#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 4e5 + 10;
ll x;
ll d[maxN];
ll pref_days[maxN];
ll sum_pref[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        sum_pref[i] = sum_pref[i - 1] + (d[i] * (d[i] + 1)) / 2;
        pref_days[i] = pref_days[i - 1] + d[i];
    }
    int r = 0;
    ll best = 0;
    for (int l = 1; l <= n; l++) {
        r = max(r, l - 1);
        while (r + 1 <= 2 * n && pref_days[r + 1] - pref_days[l - 1] <= x) {
            r++;
        }
        ll lft = x - (pref_days[r] - pref_days[l - 1]);
        best = max(best, (lft * (lft + 1)) / 2 + sum_pref[r] - sum_pref[l - 1]);
    }
    r = 2 * n + 1;
    for (int l = 2 * n; l >= n + 1; l--) {
        r = min(r, l + 1);
        while (r > 1 && pref_days[l] - pref_days[r - 2] <= x) r--;
        ll lft = x - (pref_days[l] - pref_days[r - 1]);
        best = max(best, (lft * (d[r - 1] + (d[r - 1] - lft + 1))) / 2 + sum_pref[l] - sum_pref[r - 1]);
    }
    cout << best;

    return 0;
}