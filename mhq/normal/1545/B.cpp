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
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 1e5 + 10;
int fact[maxN];
int invfact[maxN];
int inv[maxN];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
        fact[i] = mult(fact[i - 1], i);
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int good = 0;
        int ptr = 0;
        int ones = 0;
        while (ptr < s.size()) {
            if (s[ptr] == '0') {
                ptr++;
            }
            else if (s[ptr] == '1') {
                if (ptr + 1 < s.size() && s[ptr + 1] == '1') {
                    good++;
                    ptr += 2;
                }
                else {
                    ones++;
                    ptr++;
                }
            }
        }
        cout << cnk(n - good - ones, good) << '\n';
    }
    return 0;
}