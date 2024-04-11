#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N(1111);
int mod(1e9 + 7);

long long rp(long long now, int k) {
    long long will = 1;
    for (; k; k >>= 1, now *= now, now %= mod)
        if (k & 1)
            will *= now, will %= mod;
    return will;
}

long long a, b, f[N][N];

int main() {
    int k, pa, pb;
    cin >> k >> pa >> pb;
    a = pa * rp((pa + pb), mod - 2) % mod;
    b = pb * rp((pa + pb), mod - 2) % mod;
    long long ans = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            f[i][j] = 0;
    f[0][0] = rp((1 - b + mod) % mod, mod - 2);
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= k; j++) {
            if (j != k)
                f[i][j + 1] += f[i][j] * a,
                f[i][j + 1] %= mod;
            else
                ans += b * f[i][j] % mod *
                 ((a * (i + k) % mod * rp((1 - a + mod) % mod, mod - 2) % mod + 
                    a * rp((1 - a + mod) % mod, mod - 2) % mod * rp((1 - a + mod) % mod, mod - 2) % mod)) % mod,
                ans %= mod;
            if (i + j >= k)
                ans += f[i][j] * b % mod * (i + j) % mod,
                ans %= mod;
            else
                f[i + j][j] += f[i][j] * b,
                f[i + j][j] %= mod;
        }
    cout << ans << endl;
}