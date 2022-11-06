#include <iostream>
#define int long long
using namespace std;

const int N = 3e5 + 5;
const int M = 998244353;

int n, m, a[N], f[N];

int rev(int x) {
    int res = 1, b = M - 2;
    while (b > 0)
        if (b & 1)
            b--, res *= x, res %= M;
        else
            b /= 2, x *= x, x %= M;
    return res;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], m += a[i];
    f[0] = f[1] = 0;
    for (int i = 1; i < m; i++) {
        int val = f[i] - i * rev(m) % M * (f[i - 1] + 1) % M - (m - i) * rev(m) % M * (n - 2) % M * rev(n - 1) % M * f[i] % M;
        f[i + 1] = val * m % M * (n - 1) % M * rev(m - i) % M;
        f[i + 1] = (f[i + 1] + M) % M;
    }
    int v1 = 0, v2 = f[0] * (n - 1) + f[m];
    for (int i = 1; i <= n; i++)
        v1 += f[a[i]], v1 %= M;
    cout << (v1 - v2 + 2 * M) % M;
    return 0;
}