#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
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
const int maxN = (int)1e6 + 100;
int inv[maxN];
int f[maxN];
int n;
int cnt[maxN];
vector < int > g[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }
    cin >> n;
    int invn = inv[n];
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        for (int j = 1; j <= cnt[i]; j++) {
            int x;
            cin >> x;
            f[x]++;
            g[i].push_back(x);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            ans = sum(ans, mult(f[v], inv[cnt[i]]));
        }
    }
    ans = mult(ans, mult(invn, invn));
    cout << ans;
    return 0;
}