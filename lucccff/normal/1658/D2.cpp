#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int a[200010], b[200010], c[20], d[20];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> l >> r;
        n = r - l + 1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        sort(a, a + n);
        for(int i = l; i <= r; i++) {
            int x = i, y = a[i - l];
            for(int j = 0; j < 17; j++) {
                c[j] += x & 1;
                d[j] += y & 1;
                x >>= 1;
                y >>= 1;
            }
        }
        int x = 0, i;
        for(i = 16; i >= 0; i--) {
            if (c[i] * 2 == n) {
                break;
            }
            else if (c[i] != d[i]) {
                x += (1 << i);
            }
        }
        for(; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                b[j] = (a[j] ^ x) >> i;
            }
            sort(b, b + n);
            int flag = 0;
            for(int j = 0; j < n; j++) {
                if (b[j] != ((j + l) >> i)) flag = 1;
            }
            x += flag * (1 << i);
        }
        cout << x << endl;
    }
    return 0;
}