#include <bits/stdc++.h>
using namespace std;

int a[200010], b[200010], c[200010], d[200010], e[200010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            d[a[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            e[b[i]] = i;
        }
        for(int i = 0; i < n; i++) c[i] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (c[i] == 0) {
                int k = d[b[i]], l = 1;
                c[i] = 1;
                while (k != i) {
                    c[k] = 1;
                    l++;
                    k = d[b[k]];
                }
                ans += l / 2;
            }
        }
        ans = n / 2 - ans;
        if (n & 1) {
            cout << 1ll * (n / 2) * (n / 2 + 1) * 2 - 1ll * ans * (ans + 1) * 2 << endl;
        }
        else {
            cout << 1ll * n * n / 2 - 1ll * ans * ans * 2 << endl;
        }
    }
    return 0;
}