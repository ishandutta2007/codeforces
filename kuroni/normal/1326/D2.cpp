#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int n, t, len[2 * N];
char s[N], tmp[2 * N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> (s + 1);
        n = strlen(s + 1);
        pair<int, int> ans = {-1, -1};
        int pre = 0;
        for (int i = 1; i <= n / 2; i++) {
            if (s[i] == s[n + 1 - i]) {
                pre = i;
            } else {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            tmp[2 * i - 1] = s[i];
        }
        for (int i = 1, l = 1, r = 0; i <= 2 * n - 1; i++) {
            if (r < i) {
                len[i] = 1;
                l = r = i;
            } else {
                len[i] = min(2 * (r - i) + 1, len[r + l - i]);
            }
            if (i + len[i] / 2 >= r) {
                l = i - len[i] / 2, r = i + len[i] / 2;
                while (l > 1 && r < 2 * n - 1 && tmp[l - 1] == tmp[r + 1]) {
                    l--; r++;
                    len[i] += 2;
                }
            }
            if (i <= n && i - len[i] / 2 - 1 <= max(0, 2 * pre - 1)) {
                ans = max(ans, {i, i});
            } else if (i > n && i + len[i] / 2 + 1 >= min(2 * n, 2 * (n - pre) + 1)) {
                ans = max(ans, {2 * n - i, i});
            }
        }
        for (int i = 1; i <= pre; i++) {
            cout << s[i];
        }
        if (ans.second > n) {
            reverse(tmp + 1, tmp + 2 * n);
            ans.second = 2 * n - ans.second;
        }
        for (int fi = 2 * (pre + 1) - 1, i = fi; i <= 2 * ans.second - fi; i += 2) {
            cout << tmp[i];
        }
        for (int i = pre; i >= 1; i--) {
            cout << s[i];
        }
        cout << '\n';
    }
}