
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
const int maxN = (int)1e5 + 10;
int fact[maxN], invfact[maxN], inv[maxN];
int cnk(int n, int k) {
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
void init() {
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}
vector < pair < ll, int > > factorize(ll n) {
    vector < pair < ll, int > > cur;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            int exp = 0;
            while (n % i == 0){
                exp++;
                n /= i;
            }
            cur.emplace_back(i, exp);
        }
    }
    if (n > 1) cur.emplace_back(n, 1);
    return cur;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(pw(a, b - 1), a);
    else {
        int res = pw(a, b / 2);
        return mult(res, res);
    }
}
ll n;
int k;
vector < pair < ll, int > > fct;
int ans = 0;
int calc[60][60][(int)1e4 + 100];
void solve(ll x) {
    int coef = 1;
    ll cop = x;
    for (int j = 0; j < fct.size(); j++) {
        int exp = 0;
        while (x % fct[j].first == 0) {
            x /= fct[j].first;
            exp++;
        }
        coef = mult(coef, calc[j][exp][k]);
    }
    ans = sum(ans, mult(coef, cop % mod));
}
int ways[65][(int)1e4 + 100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n >> k;
    fct = factorize(n);
    for (int i = 0; i < fct.size(); i++) {
        int exp = fct[i].second;
        calc[i][exp][0] = 1;
        for (int j = 0; j + 1 <= k; j++) {
            for (int exp2 = exp; exp2 >= 0; exp2--) {
                calc[i][exp2][j + 1] = sum(mult(calc[i][exp2][j], inv[exp2 + 1]), calc[i][exp2 + 1][j + 1]);
            }
        }
    }
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            solve(i);
            if (i != (n / i)) solve(n / i);
        }
    }
    cout << ans;
    return 0;
}