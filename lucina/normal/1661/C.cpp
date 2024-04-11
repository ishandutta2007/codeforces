#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

int64_t min_day(int tar) {
    int need_one = 0;
    int64_t sum = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        int x = tar - a[i];
        sum += x;
        need_one += x % 2;
    }
    int64_t res = sum - need_one;

    int64_t l = 2 * (sum / 3);
    while (true) {
        int64_t twos = l;
        int64_t ones = l / 2;
        int64_t has = max(int64_t(0), res - twos);
        if (ones >= has + need_one) return l;
        if (ones + 1 >= has + need_one) return l + 1;
        l += 2;
    }
    throw;
}

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    int mx = *max_element(a + 1, a + 1 + n);
    int64_t ans = LLONG_MAX;
    for (int tar = mx ; tar < mx + 3 ; ++ tar)
        ans = min(ans, min_day(tar));
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}