#include <bits/stdc++.h>
using namespace std;

int a[200010], n, k, b[200010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = 1;
        }
        sort(a, a + n);
        int j = 0, cnt = n;
        for(int i = 0; i < n; i++) {
            if (b[i] == 0) continue;
            if (1ll * a[i] * k > a[n - 1]) break;
            while (j < n && (a[j] < a[i] * k || b[j] == 0)) j++;
            if (j >= n) break;
            if (a[j] == a[i] * k) {
                b[j] = 0;
                cnt -= 2;
            }
        }
        cout << cnt << endl;
    }
}