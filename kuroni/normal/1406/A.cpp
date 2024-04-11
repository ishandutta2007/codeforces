#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int t, n, u, cnt[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        fill(cnt, cnt + N, 0);
        int ans = 0, cur = 2;
        for (int i = 1; i <= n; i++) {
            cin >> u;
            cnt[u]++;
        }
        for (int i = 0; i < N && cur > 0; i++) {
            ans += max(0, (cur - cnt[i]) * i);
            cur = min(cur, cnt[i]);
        }
        cout << ans << '\n';
    }
}