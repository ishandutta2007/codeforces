#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 700100;
const int mod = 1e6 + 3;

int n, C;
int fact[maxn], invfact[maxn];

int exp(int b, int e) {
    if (!e) return 1;
    if (e & 1) return ll(exp(b, e - 1)) * b % mod;
    int res = exp(b, e >> 1);
    return ll(res) * res % mod;
}

int comb(int a, int b) {
    return ll(fact[a]) * invfact[b] % mod * invfact[a - b] % mod;
}

int main() {
    cin >> n >> C;
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) fact[i] = ll(fact[i - 1]) * i % mod;
    for (int i = 0; i < maxn; i++) invfact[i] = exp(fact[i], mod - 2);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + comb(C + i - 1, C - 1)) % mod;
    cout << ans << '\n';
}