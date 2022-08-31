#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 2 * (int)1e6 + 100;
int pwN[maxN], pwM[maxN];
int inv[maxN], fact[maxN], invfact[maxN];
int cnk(int a, int b) {
    if (a < 0 || a < b || b < 0) return 0;
    return mult(fact[a], mult(invfact[a - b], invfact[b]));
}
int n, m, a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> a >> b;
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    pwN[0] = 1;
    pwM[0] = 1;
    for (int i = 1; i < maxN; i++) {
        pwN[i] = mult(n, pwN[i - 1]);
        pwM[i] = mult(m, pwM[i - 1]);
    }
    int ans = 0;
    for (int edges = 1; edges <= min(m, n - 1); edges++) {
        int num = cnk(m - 1, edges - 1);
        int d = edges + 1;
        int coef = mult(cnk(n - 2, edges - 1), fact[edges - 1]);
        int num_v = n - d + 1;
        num = mult(num, pwM[n - edges - 1]);
        int total_coef = mult(coef, mult(num, d));
        if (num_v >= 2) {
            ans = sum(ans, mult(total_coef, pwN[num_v - 2]));
        }
        else {
            ans = sum(ans, mult(num, coef));
        }
    }
    cout << ans;
}