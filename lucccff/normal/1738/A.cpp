#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int P = 998244353;

int a[N], n, b[N], c[N], d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if (a[i]) {
                c[cnt1++] = b[i];
            }
            else {
                d[cnt2++] = b[i];
            }
        }
        sort(c, c + cnt1);
        sort(d, d + cnt2);
        sort(b, b + n);
        long long ans = 0;
        if (cnt1 > cnt2) {
            for(int i = 0; i < cnt2; i++) {
                ans += 2 * d[i];
            }
            for(int i = 0; i < cnt1 - cnt2; i++) {
                ans += c[i];
            }
            for(int i = cnt1 - cnt2; i < cnt1; i++) {
                ans += 2 * c[i];
            }
        }
        else if (cnt1 < cnt2) {
            for(int i = 0; i < cnt1; i++) {
                ans += 2 * c[i];
            }
            for(int i = 0; i < cnt2 - cnt1; i++) {
                ans += d[i];
            }
            for(int i = cnt2 - cnt1; i < cnt2; i++) {
                ans += 2 * d[i];
            }
        }
        else {
            for(int i = 1; i < n; i++) {
                ans += b[i] * 2;
            }
            ans += b[0];
        }
        cout << ans << endl;
    }
    return 0;
}