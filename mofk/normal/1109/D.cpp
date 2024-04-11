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
int n, m, a, b;
int ft[1000006], in[1000006];

int comb(int x, int y) {
    if (y < 0 || y > x) return 0;
    return 1ll * ft[x] * in[y] % mod * in[x-y] % mod;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> a >> b;
    ft[0] = 1;
    for (int i = 1; i <= 1000000; ++i) ft[i] = 1ll * i * ft[i-1] % mod;
    in[1000000] = pw(ft[1000000], mod - 2);
    for (int i = 1000000; i >= 1; --i) in[i-1] = 1ll * in[i] * i % mod;
    int ans = 0;
    for (int k = 1; k < n && k <= m; ++k) {
        int add = 1;
        add = 1ll * add * comb(m - 1, k - 1) % mod;
        add = 1ll * add * pw(m, n - k - 1) % mod;
        add = 1ll * add * ft[n-2] % mod;
        add = 1ll * add * in[n-1-k] % mod;
        if (k < n - 1) {
            add = 1ll * add * (k + 1) % mod;
            add = 1ll * add * pw(n, n - k - 2) % mod;
        }
        ans = (ans + add) % mod;
    }
    cout << ans << endl;
    return 0;
}