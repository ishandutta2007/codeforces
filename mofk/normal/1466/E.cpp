#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int p2[60];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 60; ++i) p2[i] = (1LL << i) % mod;
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> c(60, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 60; ++j) c[j] += (a[i] >> j & 1);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int mul = 0;
            for (int j = 0; j < 60; ++j) {
                if (a[i] >> j & 1) mul = (mul + 1ll * n * p2[j]) % mod;
                else mul = (mul + 1ll * c[j] * p2[j]) % mod;
            }
            int mul2 = 0;
            for (int j = 0; j < 60; ++j) if (a[i] >> j & 1) {
                mul2 = (mul2 + 1ll * c[j] * p2[j]) % mod;
            }
            ans = (ans + 1ll * mul * mul2) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}