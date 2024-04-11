#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int pw(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * a * r % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return r;
}
int ft[100005];
int in[100005];
int comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1ll * ft[n] * in[k] % mod * in[n-k] % mod;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ft[0] = in[0] = 1;
    for (int i = 1; i <= 100000; ++i) {
        ft[i] = 1ll * i * ft[i-1] % mod;
        in[i] = pw(ft[i], mod - 2);
    }

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, k;
        cin >> n >> k; --k;
        int ans = 1;
        for (int i = 1; n >= (i - 1) * k; ++i) {
            int num = comb(n - (i - 1) * k, i);
            int denom = comb(n, i);
            ans = (ans + 1ll * num * pw(denom, mod - 2)) % mod;
        }
        cout << ans << endl;
    }

    return 0;
}