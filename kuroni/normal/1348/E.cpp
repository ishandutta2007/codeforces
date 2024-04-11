#include <bits/stdc++.h>
using namespace std;

const int K = 505;

int n, k, a, b;
bool chk[K], tmp[K];
long long ta = 0, tb = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    chk[0] = true;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        ta += a; tb += b;
        for (int rem = 1; rem < k; rem++) {
            if (rem <= a && k - rem <= b) {
                for (int j = 0; j < k; j++) {
                    tmp[(j + rem) % k] |= chk[j];
                }
            }
        }
        for (int j = 0; j < k; j++) {
            chk[j] |= tmp[j];
            tmp[j] = false;
        }
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        if (chk[i]) {
            int fi = (ta - i) % k;
            int se = (tb + i) % k;
            ans = max(ans, (ta + tb - fi - se) / k);
        }
    }
    cout << ans;
}