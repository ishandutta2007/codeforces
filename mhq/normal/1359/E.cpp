#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
const int maxN = 5e5 + 10;
const int maxK = 21;
int fact[maxN], invfact[maxN], inv[maxN];
int n, k;
int cnk(int n, int k) {
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> n >> k;
    int ans = 0;
    for (int d = 1; d <= n; d++) {
        int lft = n / d - 1;
        if (lft < (k - 1)) continue;
        ans = sum(ans, cnk(lft, k - 1));
    }
    cout << ans;
    return 0;
}