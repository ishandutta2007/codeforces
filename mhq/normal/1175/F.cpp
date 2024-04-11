#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 3 * (int)1e5 + 100;
int a[maxN];
int mx[maxN];
int frst[maxN];
int lim[maxN];
bool is_ok[maxN];
int solve(int l, int r) {
    if (l > r) return 0;
    if (l == r) return (a[l] == 1);
    int mid = (l + r) / 2;
    int ans = solve(l, mid - 1);
    ans += solve(mid + 1, r);
    mx[mid] = a[mid];
    for (int i = mid - 1; i >= l; i--) {
        mx[i] = max(mx[i + 1], a[i]);
    }
    for (int i = mid + 1; i <= r; i++) {
        mx[i] = max(mx[i - 1], a[i]);
    }
    for (int i = mid + 1; i <= r; i++) {
        if (frst[a[i]] == -1) frst[a[i]] = i;
    }
    lim[mid] = r;
    if (frst[a[mid]] != -1) {
        lim[mid] = frst[a[mid]] - 1;
    }
    for (int i = mid - 1; i >= l; i--) {
        lim[i] = lim[i + 1];
        if (frst[a[i]] != -1) {
            lim[i] = min(lim[i], frst[a[i]] - 1);
        }
    }
    for (int i = l; i <= r; i++) {
        frst[a[i]] = -1;
    }
    is_ok[mid] = true;
    frst[a[mid]] = mid;
    for (int i = mid - 1; i >= l; i--) {
        if (!is_ok[i + 1]) {
            is_ok[i] = false;
            continue;
        }
        is_ok[i] = true;
        if (frst[a[i]] == -1) frst[a[i]] = i;
        else is_ok[i] = false;
    }
    for (int i = l; i <= r; i++) {
        frst[a[i]] = -1;
    }
    for (int i = mid + 1; i <= r; i++) {
        if (!is_ok[i - 1]) {
            is_ok[i] = false;
            continue;
        }
        is_ok[i] = true;
        if (frst[a[i]] == -1) frst[a[i]] = i;
        else is_ok[i] = false;
    }
    for (int i = l; i <= r; i++) {
        frst[a[i]] = -1;
    }
    for (int where = mid; where >= l; where--) {
        if (!is_ok[where]) break;
        int s = mx[where];
        int pos = (s + where - 1);
        if (pos >= mid && pos <= r) {
            if (is_ok[pos] && lim[where] >= pos && mx[pos] <= mx[where]) {
                ans++;
            }
        }
    }
    for (int where = mid; where <= r; where++) {
        if (!is_ok[where]) break;
        int s = mx[where];
        int pos = (where - s + 1);
        if (l <= pos && pos <= mid) {
            if (is_ok[pos] && lim[pos] >= where && mx[pos] < mx[where]) {
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    memset(frst, -1, sizeof frst);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << solve(1, n);
    return 0;
}