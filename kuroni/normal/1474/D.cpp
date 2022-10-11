#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t, a[N];
long long b[N], mi[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        int pos = n + 2;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i] - b[i - 1];
        }
        a[n + 1] = 0; b[n + 1] = a[n + 1] - b[n];
        for (int i = 1; i <= n + 1; i++) {
            if (b[i] < 0) {
                pos = i;
                break;
            }
        }
        mi[n + 1] = b[n + 1]; mi[n] = b[n];
        for (int i = n - 1; i >= 1; i--) {
            mi[i] = min(b[i], mi[i + 2]);
        }
        bool chk = (pos == n + 2 && b[n + 1] == 0);
        for (int i = 1; i < n && i <= pos && !chk; i++) {
            int dif = a[i] - a[i + 1];
            if (a[i + 1] < b[i - 1]) {
                continue;
            }
            if (mi[i + 1] + 2 * dif < 0 || mi[i + 2] - 2 * dif < 0) {
                continue;
            }
            if (i % 2 == n % 2) {
                if (b[n + 1] + 2 * dif != 0) {
                    continue;
                }
            } else {
                if (b[n + 1] - 2 * dif != 0) {
                    continue;
                }
            }
            chk = true;
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}