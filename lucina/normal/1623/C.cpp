#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t h[nax];
int64_t a[nax];
int64_t lb[nax];
bool ok(int x) {
    for (int i = 1 ; i <= n ; ++ i)
        a[i] = h[i], lb[i] = x;
    for (int i = n ; i >= 3 ; -- i) {
        int64_t can_give = a[i] - lb[i];
        if (can_give < 0) return false;
        can_give /= 3;
        lb[i - 2] -= 2 * can_give;
        lb[i - 1] -= can_give;
        lb[i - 2] = max(lb[i - 2], 0LL);
        lb[i - 1] = max(lb[i - 1], 0LL);
    }
    if (a[1] < lb[1] || a[2] < lb[2]) return false;
    return true;
}

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> h[i];
    int L = 0, R = 1e9, ans = -1;
    while (L <= R) {
        int mid = L + R >> 1;
        if (ok(mid)) {
            ans = mid;
            L = mid + 1;
        } else R = mid - 1;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T-- ;) {
        solve();
    }
}