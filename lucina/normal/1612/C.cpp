#include<bits/stdc++.h>
using namespace std;
int64_t k, x;

int64_t s(int64_t x) {
    return x * (x + 1) / 2;
}

int64_t calc(int64_t v) {
    if (v > k) {
        int64_t res = 2 * k - 1 - v;
        return k * k - s(res);
    } else {
        return (v) * (v + 1) / 2;
    }
}

void solve() {
    cin >> k >> x;
    int64_t l = 0, r = 2 * k - 1;
    int64_t ans = -1;
    int64_t ff;
    while (l <= r) {
        int64_t mid = l + r >> 1;
        if (calc(mid) <= x) {
            ans = mid;
            ff = calc(mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    if (calc(ans) < x) ++ ans;
    ans = min(ans, 2 * k - 1);

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}