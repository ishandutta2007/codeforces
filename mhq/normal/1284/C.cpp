#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int mod;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b)  {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 3e5 + 10;
int fact[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n >> mod;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mult(i, fact[i - 1]);
    int ans = 0;
    for (int len = 1; len <= n; len++) {
        ans = sum(ans, mult(mult(n - len + 1, n - len + 1), mult(fact[len], fact[n - len])));
    }
    cout << ans;
    return 0;
}