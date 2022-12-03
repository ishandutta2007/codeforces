#include <bits/stdc++.h>
using namespace std;

int a[1000010], b[1000010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, m, k, l;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        l = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) {
            cin >> k;
            l = __gcd(l, k);
        }
        k = l;
        long long ans = 0, s = 0, t = 0, s1, t1, mx;
        for(int i = 0; i < k; i++) {
            int j;
            s1 = 0;
            for(j = 0; j * k + i < n; j++) {
                b[j] = a[j * k + i];
                s1 += b[j];
            }
            mx= s1;
            sort(b, b + j);
            t1 = s1 - 2 * b[0];
            for(j = 1; j * k + i < n; j += 2) {
                s1 -= 2ll * (b[j] + b[j - 1]);
                mx = max(s1, mx);
            }
            s += mx;
            mx = t1;
            for(j = 2; j * k + i < n; j += 2) {
                t1 -= 2ll * (b[j] + b[j - 1]);
                mx = max(t1, mx);
            }
            t += mx;
        }
        ans = max(s, t);
        cout << ans << endl;
    }
    return 0;
}