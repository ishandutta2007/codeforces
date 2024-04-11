#include <bits/stdc++.h>
using namespace std;

char c[100010];
int a[100010], b[100010];
int a1, b1;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = n;
        a1 = b1 = 0;
        cin >> c;
        for(int i = 0; i < n; i++) {
            a[i] = c[i] - '0';
            a1 += a[i];
        }
        cin >> c;
        for(int i = 0; i < n; i++) {
            b[i] = c[i] - '0';
            b1 += b[i];
        }
        if (a1 != b1 && a1 + b1 != n + 1) {
            cout << -1 << endl;
            continue;
        }
        if (a1 == b1) {
            int k = 0;
            for(int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    k++;
                }
            }
            ans = min(ans, k);
        }
        if (a1 + b1 == n + 1) {
            int k = 0;
            for(int i = 0; i < n; i++) {
                if (a[i] == b[i]) {
                    k++;
                }
            }
            ans = min(ans, k);
        }
        cout << ans << endl;
    }
    return 0;
}