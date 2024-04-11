#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200100;
const int mod = 1e9 + 7;

int fact[2 * maxn], invfact[2 * maxn];

int exp(int b, int e) {
    if (!e) return 1;
    if (e & 1) return ll(exp(b, e - 1)) * b % mod;
    int res = exp(b, e >> 1);
    return ll(res) * res % mod;
}

int C(int n, int k) {
    return ll(fact[n]) * invfact[k] % mod * invfact[n - k] % mod;
}

int n;
char s[maxn];
int numl[maxn], numr[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> s; n = strlen(s);

    fact[0] = 1;
    for (int i = 1; i < 2 * maxn; i++)
        fact[i] = ll(fact[i - 1]) * i % mod;

    for (int i = 0; i < 2 * maxn; i++)
        invfact[i] = exp(fact[i], mod - 2);

    for (int i = 0, cur = 0; i < n; i++) {
        if (s[i] == '(') cur++;
        numl[i] = cur;
    }

    for (int i = n - 1, cur = 0; i >= 0; i--) {
        if (s[i] == ')') cur++;
        numr[i] = cur;
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
        if (s[i] == ')' && numl[i] > 0) {
            ans = (ans + C(numl[i] + numr[i] - 1, numl[i] - 1)) % mod;
        }

    cout << ans << '\n';
}