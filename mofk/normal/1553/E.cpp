#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> fr(n, 0);
        for (int i = 1; i <= n; ++i) {
            int dis = (i - a[i] + n) % n;
            ++fr[dis];
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (fr[i] >= n - 2 * m) {
            vector<int> b(n + 1);
            int cur = 1 + i;
            for (int j = 1; j <= n; ++j) {
                b[j] = a[cur];
                ++cur;
                if (cur > n) cur -= n;
            }
            int cc = 0;
            vector<bool> seen(n + 1, false);
            for (int j = 1; j <= n; ++j) if (!seen[j]) {
                ++cc;
                cur = b[j];
                seen[j] = true;
                while (cur != j) {
                    seen[cur] = true;
                    cur = b[cur];
                }
            }
            if (cc >= n - m) ans.push_back(i);
        }
        cout << ans.size();
        for (auto x: ans) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}