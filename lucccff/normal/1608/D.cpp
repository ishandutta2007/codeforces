#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

LL inv[100010], jie[100010], ijie[100010];
char ch[10];
int a[100010], b[100010];
int w1, w2, r1, r2;
LL ans, s;

LL C(LL m, LL n) {
    return ijie[m] * ijie[n - m] % MOD * jie[n] % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    inv[1] = 1;
    jie[0] = jie[1] = 1;
    ijie[0] = ijie[1] = 1;
    for(int i = 2; i <= 1e5; i++) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        jie[i] = jie[i - 1] * i % MOD;
        ijie[i] = ijie[i - 1] * inv[i] % MOD;
    }
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>ch;
        if (ch[0] == 'W') {
            a[i] = 1;
            w1++;
        }
        else if (ch[0] == 'B') {
            a[i] = 2;
            r1++;
        }
        else {
            a[i] = 0;
        }
        if (ch[1] == 'W') {
            b[i] = 1;
            w2++;
        }
        else if (ch[1] == 'B') {
            b[i] = 2;
            r2++;
        }
        else {
            b[i] = 0;
        }
    }
    for(int i = 0; i <= n; i++) {
        if ((i >= w1) && (i <= n - r1) && (i >= r2) && (i <= n - w2)) {
            ans += C(i - w1, n - r1 - w1) * C(i - r2, n - w2 - r2);
            ans %= MOD;
        }
    }
    s = 1;
    for(int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == 0) {
                s = s * 2 % MOD;
            }
            else {
                s = 0;
                break;
            }
        }
    }
    if (r1 + w2 == 0) ans++;
    if (w1 + r2 == 0) ans++;
    ans = (ans + MOD - s) % MOD;
    cout<<ans;
    return 0;
}