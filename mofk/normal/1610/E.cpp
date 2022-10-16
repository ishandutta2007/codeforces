#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = 1, last = -1;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && a[i] == a[i+1]) {
                continue;
            }
            int cur = i - last, id = i + 1, tar = a[i];
            while (id < n && tar <= a.back()) {
                ++cur;
                id = lower_bound(a.begin() + id, a.end(), tar) - a.begin();
                tar = 2 * a[id] - a[i];
                ++id;
            }
            ans = max(ans, cur);
            last = i;
        }
        cout << n - ans << '\n';
    }
    return 0;
}