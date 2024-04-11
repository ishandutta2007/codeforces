#include <bits/stdc++.h>
using namespace std;
const int maxN = 5 * (int)1e6 + 10;
int lp[maxN];
int f[maxN];
vector < int > pr;
int l, r, t;
const int mod = (int)1e9 + 7;
const int inv2 = (mod + 1) / 2;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
void calc() {
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            pr.push_back(i);
            lp[i] = i;
            f[i] = mult(inv2, mult(i, i - 1));
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < maxN; j++) {
            lp[i * pr[j]] = pr[j];
            f[i * pr[j]] = sum(mult(i, f[pr[j]]), f[i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> t >> l >> r;
    calc();
    int curt = 1;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans = sum(ans, mult(curt, f[i]));
        curt = mult(curt, t);
    }
    cout << ans;
    return 0;
}