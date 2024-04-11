#include <bits/stdc++.h>
using namespace std;
int n, k;
const int maxN = (int)1e6 + 10;
const int MOD = (int)1e9 + 7;
int inv[maxN];
int invfact[maxN];
int fact[maxN];
int g[maxN];
int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}
int add(int a, int b) {
    int s = (a + b);
    if (s >= MOD) s = s - MOD;
    return s;
}
int sub(int a, int b) {
    int s = (a - b);
    if (s < 0) s = s + MOD;
    return s;
}
void calc() {
    inv[1] = 1;
    invfact[0] = 1;
    fact[0] = 1;
    invfact[1] = 1;
    fact[1] = 1;
    for (int i = 2; i <= (int)1e6 + 2; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult((MOD - inv[MOD % i]), (MOD / i));
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    //cout << mult(100000, 100000);
    calc();
    cin >> n >> k;
    int sum = 0;
    for (int i = k; i <= n; i++) {
        g[i] = add(sum, mult(fact[i - 1], i - k));
        sum = mult(i, sum);
        sum = add(g[i], sum);
        sum = sub(sum, mult(g[i - k], mult(fact[i], invfact[i - k])));
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = add(ans, mult(g[i], mult(fact[n - 1], invfact[i])));
    }
    /*for (int i = 1; i <= n; i++) {
        cout << g[i] << " ";
    }*/
    cout << ans;
    return 0;
}