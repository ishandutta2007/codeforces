#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100100;
const int MOD = 1e9 + 7;

int n, k, ar[MAXN];
int fact[MAXN], invfact[MAXN];

int exp(int b, int e) {
    if (!e) return 1;
    if (e&1) return ll(exp(b, e-1)) * b % MOD;
    int res = exp(b, e/2);
    return ll(res) * res % MOD;
}

int C(int a, int b) {
    if (!b) return 1;
    if (a < b) return 0;
    return ll(fact[a]) * invfact[b] % MOD * invfact[a-b] % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        ar[i] = c-'0';
    }

    if (k == 0) {
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = ll(ans) * 10 % MOD;
            ans = (ans + ar[i]) % MOD;
        }
        cout << ans;
        return 0;
    }

    fact[0] = 1;
    for (int i=1; i<=n; i++) fact[i] = ll(fact[i-1]) * i % MOD;
    for (int i=0; i<=n; i++) invfact[i] = exp(fact[i], MOD-2);

    int ans = 0, cur = 0, pw10 = 1;
    for (int i=n-1; i>=0; i--) {
        if (i < n-1) {
            cur = (cur + ll(pw10) * C(i, k-1) % MOD) % MOD;
            pw10 = ll(pw10) * 10 % MOD;
            ans = (ans + ll(cur) * ar[i] % MOD) % MOD;
        }
        ans = (ans + ll(pw10) * ar[i] % MOD * C(i, k) % MOD) % MOD;
    }

    cout << ans;
}