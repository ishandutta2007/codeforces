#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5e5 + 10;
const int mod = (int)1e9 + 7;
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
int pw2[62];
ll x[maxN];
int costA[62];
int costB[62];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        pw2[0] = 1;
        for (int i = 1; i <= 60; i++) pw2[i] = mult(2, pw2[i - 1]);
        int n;
        cin >> n;
        for (int i = 0; i < 60; i++) {
            costA[i] = 0;
            costB[i] = 0;
        }
        int tot_s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            tot_s = sum(tot_s, x[i] % mod);
            for (int j = 0; j < 60; j++) {
                if (x[i] & (1LL << j)) {
                    costA[j] = sum(costA[j], pw2[j]);
                }
                else {
                    costB[j] = sum(costB[j], pw2[j]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int le = 0;
            int ri = tot_s;
            for (int j = 0; j < 60; j++) {
                if (x[i] & (1LL << j)) {
                    le = sum(le, costA[j]);
                    ri = sum(ri, costB[j]);
                }
            }
            ans = sum(ans, mult(le, ri));
        }
        cout << ans << '\n';

    }
    return 0;
}