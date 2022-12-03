#include <bits/stdc++.h>
using namespace std;

int a[200010], n, k, b[200010], c[200010], d[200010], f[200010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        if (n & 1) {
            cout << -1 << endl;
            continue;
        }
        sort(b, b + n);
        int flag = 1;
        for(int i = 0; i < n; i += 2) {
            if (b[i] != b[i + 1]) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0, p = 0;
        for(int i = 0; i < n; i += 2) {
            int k;
            for(k = i + 1; a[k] != a[i]; k++);
            for(int j = i + 1; j < k; j++) {
                c[p] = cnt + k + j - i;
                d[p] = a[j];
                p++;
            }
            for(int j = i + 1; j < k; j++) {
                b[k - j + i + 1] = a[j];
            }
            for(int j = i + 2; j <= k; j++) {
                a[j] = b[j];
            }
            cnt += 2 * (k - i - 1);
            f[i / 2] = 2 * (k - i);
        }
        cout << p << endl;
        for(int i = 0; i < p; i++) {
            cout << c[i] << ' ' << d[i] << endl;
        }
        cout << n / 2 << endl;
        for(int i = 0; i < n / 2; i++) {
            cout << f[i] << ' ';
        }
        cout << endl;
    }
}