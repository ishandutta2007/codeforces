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
int n, k;
const int maxN = 4e5 + 15;
int pos[maxN];
int s[maxN];
int fact[maxN];
int invfact[maxN];
int inv[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        pos[s[i]] = i;
    }
    pos[n] = -1;
    k--;
    for (int i = 0; i + 1 < n; i++) {
        if (pos[s[i] + 1] > pos[s[i + 1] + 1]) k--;
    }
    if (k < 0) {
        cout << 0;
        return 0;
    }
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
        fact[i] = mult(fact[i - 1], i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cout << mult(fact[n + k], mult(invfact[k], invfact[n]));

    return 0;
}