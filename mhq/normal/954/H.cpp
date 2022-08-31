#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int inv(int a) {
    return pw(a, mod - 2);
}
int n;
const int maxN = 5005;
const int inv2 = (mod + 1) / 2;
int a[maxN];
int T[maxN];
int ans[2 * maxN];
int sm[2 * maxN];
int inv_T[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    T[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        T[i] = mult(T[i - 1], a[i]);
    }
    for (int i = 0; i < n; i++) {
        inv_T[i] = inv(T[i]);
    }
    a[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int x = i + 1; x <= n - 1; x++) {
            int val = mult(T[x], T[i + 1]);
            sm[x + i + 1] = sum(sm[x + i + 1], val);
        }
        int coef = mult(mult(T[i], mult(inv_T[i + 1], inv_T[i + 1])), mult(a[i + 1], a[i + 1] - 1));
        int coef2 = mult(coef, inv2);
        for (int sum_now = 2 * i + 2; sum_now <= 2 * n - 2; sum_now++) {
            int add = sm[sum_now];
            if (sum_now % 2 == 0) {
                int ways = mult(T[sum_now / 2], T[sum_now / 2]);
                add = sub(add, ways);
                ans[sum_now - 2 * i] = sum(ans[sum_now - 2 * i], mult(ways, coef2));
            }
            ans[sum_now - 2 * i] = sum(ans[sum_now - 2 * i], mult(coef, add));
        }
        for (int x = i + 1; x <= n - 1; x++) {
            ans[x - i] = sum(ans[x - i], T[x]);
        }
    }
    for (int i = 1; i <= 2 * n - 2; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}