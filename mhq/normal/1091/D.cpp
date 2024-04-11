#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = (int)1e6  + 10;
int fact[maxN], invfact[maxN], inv[maxN];
int main() {
    srand(239);
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    fact[1] = 1;
    invfact[0] = 1;
    invfact[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], (mod - mod / i));
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    int n;
    cin >> n;
    int ans = 0;
    for (int k = 1; k < n; k++) {
        int ck = mult(fact[n], mult(invfact[k], invfact[n - k]));
        ans = sum(ans, mult(ck, mult(fact[n - k], sub(fact[k], 1))));
    }
    ans = sum(ans, fact[n]);
    cout << ans;
    return 0;

}