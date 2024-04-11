#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e7 + 10;
int mob[maxN], lp[maxN];
int f[maxN];
int n;
int pw2[maxN];
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
void init() {
    vector < int > pr;
    mob[1] = 1;
    pw2[0] = 1;
    pw2[1] = 2;
    for (int i = 2; i < maxN; i++) {
        pw2[i] = mult(pw2[i - 1], 2);
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && 1LL * i * pr[j] < maxN; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
    for (int i = 2; i < maxN; i++) {
        int p = lp[i];
        if (1LL * p * p <= i && (i % (p * p) == 0)) {
            mob[i] = 0;
        }
        else {
            mob[i] = -mob[i / p];
        }
        if (mob[i] != 0) {
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector < int > all_primes;
        int x;
        cin >> x;
        while (x > 1) {
            int p = lp[x];
            all_primes.push_back(p);
            while (x % p == 0) {
                x /= p;
            }
        }
        int m = all_primes.size();
        for (int mask = 0; mask < (1 << m); mask++) {
            int val = 1;
            for (int bit = 0; bit < m; bit++) {
                if (mask & (1 << bit)) {
                    val *= all_primes[bit];
                }
            }
            f[val]++;
        }
    }
    int all = 0;
    for (int i = 2; i < maxN; i++) {
        if (f[i] == 0 || mob[i] == 0) continue;
        if (mob[i] == -1) {
            all = sum(all, mult(pw2[f[i]] - 1, n - f[i]));
        }
        else {
            all = sub(all, mult(pw2[f[i]] - 1, n - f[i]));
        }
    }
    cout << all;
    return 0;
}