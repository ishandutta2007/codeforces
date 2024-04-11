#include <bits/stdc++.h>
using namespace std;
int n, k, q;
const int maxN =(int)1e6 + 10;
int lp[maxN];
int phi[maxN];
int c[2 * (int)1e5 + 15];
int fact[2 * (int)1e5 + 15];
int invfact[2 * (int)1e5 + 15];
int inv[2 * (int)1e5 + 15];
int d[maxN];
vector < int > pr;
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
void calc() {
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i < maxN; j++) {
            lp[i * pr[j]] = pr[j];
        }
     }
     phi[1] = 1;
     for (int i = 2; i < maxN; i++) {
        int p = lp[i];
        if ((i / p) % p == 0) {
            phi[i] = p * phi[i / p];
        }
        else phi[i] = (p - 1) * phi[i / p];
     }
     inv[1] = 1;
     invfact[0] = 1;
     fact[0] = 1;
     fact[1] = 1;
     invfact[1] = 1;
     for (int i = 2; i < 2 * (int)1e5 + 10; i++) {
        inv[i] = mult(mod - (mod / i), inv[mod % i]);
        fact[i] = mult(i, fact[i - 1]);
        invfact[i] = mult(invfact[i - 1], inv[i]);
     }
     for (int i = k; i < 2 * int(1e5) + 10; i++) {
        c[i] = mult(fact[i], mult(invfact[i - k], invfact[k]));
     }
}
void add(int t) {
    for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            if (i == (t / i)) d[i]++;
            else {
                d[i]++;
                d[t / i]++;
            }
        }
    }
    //cout << d[2] << '\n';
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> q;
    calc();
    int ans = 0;
    int t;
    //cout << lp[6] << '\n';
    for (int i = 1; i <= n; i++) {
        cin >> t;
        add(t);
    }
    for (int i = 1; i < maxN; i++) {
        if (d[i] == 0) continue;
        ans = sum(ans, mult(phi[i], c[d[i]]));
    }
    int x;
    for (int i = 1; i <= q; i++) {
        cin >> x;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                //cout << j << '\n';
                if (j == (x / j)) {
                    ans = sum(ans, mult(phi[j], sub(c[d[j] + 1], c[d[j]])));
                    d[j]++;
                }
                else {
                    ans = sum(ans, mult(phi[j], sub(c[d[j] + 1], c[d[j]])));
                    ans = sum(ans, mult(phi[x / j], sub(c[d[x / j] + 1], c[d[x / j]])));
                    d[j]++;
                    d[x / j]++;
                }
            }
        }
        //cout << d[2] << '\n';
        cout << ans << '\n';
    }
    return 0;
}