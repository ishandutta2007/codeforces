#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n;

int pw(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * r * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return r;
}
int inv(int a) { return pw(a, mod - 2); }
void add(int &a, int b) { a = (a + b) % mod; }
void sub(int &a, int b) { a = (a - b + mod) % mod; }

int ft[1000006];
int comb(int n, int k) {
    return 1ll * ft[n] * inv(ft[k]) % mod * inv(ft[n-k]) % mod;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    ft[0] = 1; for (int i = 1; i <= n; ++i) ft[i] = 1ll * ft[i-1] * i % mod;
    int all = pw(pw(3, n), n);
    for (int i = 0; i <= n; ++i) {
        int choose = comb(n, i);
        int conf = pw(3, n - i);
        int f = 0;
        int total = pw(3, i);
        add(f, 1ll * pw(conf, n) * (total + mod - 3) % mod);
        add(f, 1ll * pw(conf + mod - 1, n) * 3 % mod);
        f = 1ll * f * choose % mod;
        if (i == 0) f = pw(conf + mod - 3, n);
        if (i & 1) add(all, f);
        else sub(all, f);
    }
    cout << all << endl;
    return 0;
}