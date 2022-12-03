#include <iostream>
#include <cstring>
#include <cstdio>
 
const int N = 5e3 + 7;
const int mod = 998244353;
 
using namespace std;
 
int a[N], fac[N];
int f[N][N / 2];
int s[N][N / 2];
 
int ksm(int a, int n) {
    int ans = 1, b = a;
    while (n) {
        if (n & 1) ans = 1ll * ans * b % mod;
        b = 1ll * b * b % mod;
        n >>= 1;
    }
    return ans;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, y, x, ans = 1;
        cin >> n;
        y = 0;
        fac[0] = 1;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n / 2; j++)
                f[i][j] = s[i][j] = 0;
        for (int i = 1; i <= n; i++) {
            fac[i] = 1ll * fac[i - 1] * i % mod;
            cin >> x;
            if (x == y) a[i] = a[i - 1];
            else a[i] = i - 1;
            ans = 1ll * ans * (i - a[i]) % mod;
            y = x;
            for (int j = 1; 2 * j - 1 <= a[i]; j++) {
                if (j == 1) f[i][j] = a[i];
                else f[i][j] = s[a[i]][j - 1];
                s[i][j] = (s[i - 1][j] + 1ll * (a[i] - 2 * j + 1) * f[i][j]) % mod;
            }
        }
        cout << 1ll * f[n][n / 2] * ksm(ans, mod - 2) % mod << endl;
    }
    return 0;
}