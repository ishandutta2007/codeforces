#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5 * (int)1e5 + 100;
int pref[maxN];
int n;
int a[maxN];
int get(int l, int r) {
    r = min(r, maxN - 1);
    if (l > r) return 0;
    if (l == 0) return pref[r];
    return pref[r] - pref[l - 1];
}
ll cnt = 0;
bool can(int x, int y, ll cnt) {
    if (2 * x > a[1] && x > a[2]) return false;
    ll f = cnt - 2 * (x / y);
    if (f - 2 >= x) return true;
    if (f < x) return false;
    int cnt2 = 0; int cnt1 = 0;
    for (int k = 0; k * y < maxN; k++) {
        int l = k * y;
        int r = min(k * y + y - 1, maxN - 1);
        if (2 * x <= r) {
            cnt2 += get(max(2 * x, l + (2 * x) % y), r);
        }
        if (x <= r) {
            cnt1 += get(max(x, l + (x % y)), r);
        }
    }
    ll g = cnt - (2 * x) / y;
  //  cout << x << " " << cnt1 << " " << cnt2 << " " << cnt << " " << y << " " << g << endl;
    if (a[2] >= x && f - 2 + min(2, cnt1) >= x) return true;
    if (a[1] >= 2 * x && g - 1 + min(1, cnt2) >= x) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int at_most = max(a[1] / 2, a[2]);
    for (int i = 1; i < maxN; i++) pref[i] += pref[i - 1];
    ll best = 0;
    for (int y = 2; y < maxN; y++) {
        cnt = 0;
        for (int k = 1; k * y < maxN; k++) {
            cnt += 1LL * get(k * y, k * y + y - 1) * k;
        }
        int r = at_most + 1;
        int l = 2;
        if (!can(l, y, cnt)) continue;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (can(mid, y, cnt)) l = mid;
            else r = mid;
        }
        best = max(best, 1LL * y * l);
    }
    cout << best << '\n';
    return 0;
}