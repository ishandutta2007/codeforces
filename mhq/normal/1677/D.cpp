#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 1e6 + 10;
int v[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        rotate(v, v + (n - k) % n, v + n);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (v[i] == -1) {
                ans = mult(ans, (i + 1));
            }
            else {
                if (v[i] == 0) {
                    ans = mult(ans, min(k + 1, i + 1));
                }
                else if (v[i] + k > i) {
                    ans = 0;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}