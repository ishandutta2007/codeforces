#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n;
long long ft[1000006];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    ft[1] = n;
    for (int i = 2; i <= n; ++i) ft[i] = 1ll * (n + 1 - i) * ft[i-1] % mod;
    long long ans = 1ll * ft[n] * n % mod;
    for (int i = 1; i < n; ++i) ans = (ans + mod - ft[i]) % mod;
    cout << ans << endl;
    return 0;
}