#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t, k, r, a[N], dl[N], dr[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> r;
        }
        sort(a + 1, a + n + 1);
        dl[0] = dr[n + 1] = 0;
        for (int pl = 1, i = 1; i <= n; i++) {
            while (a[i] - a[pl] > k) {
                pl++;
            }
            dl[i] = max(i - pl + 1, dl[i - 1]);
        }
        for (int pr = n, i = n; i >= 1; i--) {
            while (a[pr] - a[i] > k) {
                pr--;
            }
            dr[i] = max(pr - i + 1, dr[i + 1]);
        }
        int ans = 0;
        for (int i = 1; i <= n + 1; i++) {
            ans = max(ans, dl[i - 1] + dr[i]);
        }
        cout << ans << '\n';
    }
}