/**
 * @author Macesuted (macesuted@outlook.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define maxn 200005
#define mod 998244353

typedef pair<int, int> pii;

int a[maxn], fac[maxn], ifac[maxn];

int Pow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) ans = ans * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ans;
}

inline int C(int n, int m) { return fac[n] * ifac[n - m] % mod * ifac[m] % mod; }

void work(void) {
    int n;
    cin >> n;
    for (register int i = 1; i <= n; i++) cin >> a[i];
    int max1 = 0, max2 = 0;
    for (register int i = 1; i <= n; i++)
        if (a[i] > max1)
            max2 = max1, max1 = a[i];
        else if (a[i] > max2)
            max2 = a[i];
    int cnt = 0;
    for (register int i = 1; i <= n; i++)
        if (a[i] == max2) cnt++;
    if (max1 - max2 > 1)
        cout << 0 << endl;
    else if (max1 == max2)
        cout << fac[n] << endl;
    else
        cout << fac[n - cnt - 1] * C(n, cnt + 1) % mod * fac[cnt] % mod * cnt % mod << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    int _ = 1;
    cout << setprecision(11);
    fac[0] = ifac[0] = 1;
    for (register int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    ifac[maxn - 1] = Pow(fac[maxn - 1], mod - 2);
    for (register int i = maxn - 2; i; i--) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    cin >> _;
    while (_--) work();
    return 0;
}