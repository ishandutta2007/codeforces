#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 2 * (int)1e5 + 10;
int mod = (int)1e9 + 7;
int add(int a, int b) {
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
int inv[maxN];
int invfact[maxN];
int fact[maxN];
void calc() {
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) {
        fact[i] = mult(i, fact[i - 1]);
    }
    inv[1] = 1;
    invfact[0] = 1;
    invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult((mod - (mod / i)), inv[mod % i]);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}
int cnk(int n, int k) {
    return mult(fact[n], mult(invfact[n - k], invfact[k]));
}
int b[maxN];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    calc();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[1];
        return 0;
    }
    if (n % 4 == 2 || n % 4 == 0) {
        for (int i = 1; i <= n; i++) b[i] = a[i];
    }
    if (n % 4 == 1 || n % 4 == 3) {
        for (int i = 1; i < n; i++) {
            if (i % 2 == 1) {
                b[i] = add(a[i], a[i + 1]);
            }
            else b[i] = sub(a[i], a[i + 1]);
        }
        n--;
    }
    if (n % 4 == 0) {
        int t = (n / 2) - 1;
        int ans = 0;
        for (int i = 1; i <= n; i += 2) {
            ans = add(ans, mult(cnk(t, i / 2), sub(b[i], b[i + 1])));
        }
        cout << ans;
    }
    else if (n % 4 == 2) {
        int t = (n / 2) - 1;
        int ans = 0;
        for (int i = 1; i <= n; i += 2) {
            ans = add(ans, mult(cnk(t, i / 2), add(b[i], b[i + 1])));
        }
        cout << ans;
    }
    return 0;
}