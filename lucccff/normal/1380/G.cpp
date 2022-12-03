#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int n, a[300010];
long long pre[300010];

int qp(int n, int m) {
    long long k = 1, t = n;
    while(m) {
        if (m & 1) k = k * t % MOD;
        t = t * t % MOD;
        m >>= 1;
    }
    return k;
}

int main() {
    cin >> n;
    int invn = qp(n, MOD - 2);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        pre[i + 1] = (pre[i] + a[i]) % MOD;
    }
    for(int i = 1; i <= n; i++) {
        long long ans = 0;
        for(int j = n - i; j > 0; j -= i) {
            ans += pre[j];
        }
        ans %= MOD;
        cout << ans * invn % MOD << ' ';
    }
    return 0;
}