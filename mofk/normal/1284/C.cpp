#include <bits/stdc++.h>

using namespace std;
int n, mod;
int ft[500005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> mod;
    ft[0] = 1;
    for (int i = 1; i <= n; ++i) ft[i] = 1ll * ft[i-1] * i % mod;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int add = n - i + 1;
        add = 1ll * add * ft[n - i + 1] % mod * ft[i] % mod;
        ans = (ans + add) % mod;
    }
    cout << ans << endl;
    return 0;
}