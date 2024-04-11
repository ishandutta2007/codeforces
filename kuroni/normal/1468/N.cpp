#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, msk[5] = {1, 2, 4, 5, 6}, c[3], a[5];
    cin >> t;
    while (t--) {
        cin >> c[0] >> c[1] >> c[2];
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        bool chk = true;
        for (int cur = 0; cur < 32; cur++) {
            int sum = 0, mat = 0, oth = 0;
            for (int i = 0; i < 5; i++) {
                if (cur >> i & 1) {
                    sum += a[i];
                    mat |= msk[i];
                }
            }
            for (int i = 0; i < 3; i++) {
                if (mat >> i & 1) {
                    oth += c[i];
                }
            }
            chk &= (oth >= sum);
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}