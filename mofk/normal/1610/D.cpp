#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n;
int a[200005];
int b[40];

int lsb(int x) {
    int r = 0;
    while (x % 2 == 0) x /= 2, ++r;
    return r;
}

int pw(int x, int y) {
    int r = 1;
    while (y) {
        if (y & 1) r = 1ll * r * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return r;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) ++b[lsb(a[i])];

    int ans = 0, rem = n;
    ans = (ans + 1ll * (pw(2, b[0]) - 1) * pw(2, rem - b[0])) % mod;
    rem -= b[0];
    for (int i = 1; i <= 30; ++i) if (b[i]) {
        ans = (ans + 1ll * (pw(2, b[i] - 1) - 1) * pw(2, rem - b[i])) % mod;
        rem -= b[i];
    }

    cout << ans << endl;
    return 0;
}