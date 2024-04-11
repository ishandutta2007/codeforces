#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long inv[5010], jie[5010], ijie[5010];
int a[5010];
char c[5010];

long long C(long long n, long long m) {
    return (ijie[n - m] * ijie[m] % MOD) * jie[n] % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    inv[1] = 1;
    jie[0] = jie[1] = 1;
    ijie[0] = ijie[1] = 1;
    for(int i = 2; i < 5010; i++) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        jie[i] = jie[i - 1] * i % MOD;
        ijie[i] = ijie[i - 1] * inv[i] % MOD;
    }
    int n, k;
    cin >> n >> k;
    cin >> c;
    int j = 0, l = 0, i = 0, m;
    while(l < n && i < k) {
        if (c[l++] == '1') i++;
    }
    if (i < k || k == 0) {
        cout << 1;
        return 0;
    }
    long long ans = 0;
    while(l <= n) {
        m = j;
        while(m < n && c[m++] == '0');
        while(l < n && c[l] == '0') l++;
        if (l < n) ans += C(l - j, k) - C(l - m, k - 1);
        else ans += C(l - j, k);
        ans %= MOD;
        j = m;
        l++;
    }
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}