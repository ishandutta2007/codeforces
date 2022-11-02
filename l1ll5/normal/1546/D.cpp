#include<bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
const int mod = 998244353;
int Qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = 1ll * ret * a % mod;
        }
        b >>= 1;
        a = 1ll * a * a % mod;
    }
    return ret;
}
int n;
int col[N];
int fac[N], inv[N];
int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
    ios::sync_with_stdio(false);
    int T;

    fac[0] = 1;
    for (int i = 1; i <= 200000; i += 1)
        fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[200000] = Qpow(fac[200000], mod - 2);
    for (int i = 200000 - 1; i >= 0; i -= 1)
        inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;

    cin >> T;
    while (T--) {
        cin >> n;
        int a = 0, b = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; i += 1) {
            if (s[i] == '0') b++;
            else {
                if (i && s[i - 1] == '1' && !col[i - 1]) a++, col[i] = 1, col[i - 1] = 1;
            }
        }
        cout << C(a + b, b) << '\n';
        for (int i = 0; i < n; i += 1) col[i] = 0;
    }
}