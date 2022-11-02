#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 200000 + 5;
const int mod = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i += 1)
        cin >> a[i];
    a[n + 1] = -1;
    int ans = 2;
    int sv = 0;
    for (int i = 1; i < n; i += 1) {
        if (a[i + 1] == a[i] && i != n - 1) {
            sv++;
            continue;
        }
        int cur = i + 1, len = 2;
        while (cur <= n) {
            int l = cur + 1, r = n, ret = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[mid] - a[i] >= 2 * (a[cur] - a[i])) {
                    r = mid - 1;
                    ret = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            if (ret == 0) {
                break;
            }
            cur = ret;
            len++;
        }
        len += sv;
        sv = 0;
        ans = max(ans, len);
    }
    cout << max(0, n - ans) << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}