#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        tuple<int, int, int, int> ans = {1, 0, 0, -1};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0, l = -1, cnt = 0, cur = 1; i < n; i++) {
            if (a[i] == 0) {
                l = -1;
            } else {
                if (l == -1) {
                    l = i;
                    cnt = 0;
                    cur = 1;
                }
                if (abs(a[i]) == 2) {
                    cnt++;
                }
                if (a[i] < 0) {
                    cur = !cur;
                }
                ans = max(ans, {cur, cnt, l, i});
            }
        }
        for (int i = n - 1, r = -1, cnt = 0, cur = 1; i >= 0; i--) {
            if (a[i] == 0) {
                r = -1;
            } else {
                if (r == -1) {
                    r = i;
                    cnt = 0;
                    cur = 1;
                }
                if (abs(a[i]) == 2) {
                    cnt++;
                }
                if (a[i] < 0) {
                    cur = !cur;
                }
                ans = max(ans, {cur, cnt, i, r});
            }
        }
        auto [_, __, l, r] = ans;
        cout << l << " " << n - 1 - r << '\n';
    }
}