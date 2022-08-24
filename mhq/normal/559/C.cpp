#include <bits/stdc++.h>
using namespace std;
int h, w, n;
const int maxN = 2 * (1e5 + 10);
const int mod = 1e9  + 7;
long long fact[maxN];
long long invfact[maxN];
long long inv[maxN];
pair < int, int > t[2005];
bool mem[2005][2005];
long long dp[2005][2005];
void fac() {
    fact[0] = 1;
    for (int i = 1; i <= maxN - 2; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
/*long long binpow (long long a, long long b) {
    if ( b == 0) return 1;
    if (b & 1) {
        b = b >> 1;
        return (((binpow(a, b) * binpow(a, b)) % mod) * a) % mod;
    }
    else {
        b = b >> 1;
        return (binpow(a, b) * binpow(a, b)) % mod;
    }
}
*/
void inv1() {
    inv[1] = 1;
    for ( int i = 2; i <= maxN - 2; i++) {
        inv[i] = (((( -(mod / i)) * inv[ mod % i]) % mod) + mod) % mod;
    }
}
void invfac() {
    invfact[0] = 1;
    for ( int i = 1; i <= maxN - 2; i++) {
        invfact[i] = (invfact[i - 1] * inv[i]) % mod;
    }
}
long long cnk(int k, int n) {
    if (n < k || k < 0) return 0;
    return (((fact[n] * invfact[k]) % mod) * invfact[n - k]) % mod;
}
inline long long rec(int i, int j) {
    if (mem[i][j] == true) return dp[i][j];
    mem[i][j] = true;
    if (j == 0) {
        dp[i][j] = cnk(h - t[i].first, w + h - t[i].second - t[i].first);
        return dp[i][j];
    }
    long long x = (rec(j - 1, j - 1) * cnk(t[j - 1].first - t[i].first, t[j - 1].first - t[i].first + t[j - 1].second - t[i].second)) % mod;
    dp[i][j] = (((rec(i, j - 1) - x) % mod) + mod) % mod;
    return dp[i][j];
}
int main() {
    //freopen("jellous.in", "r", stdin);
    //freopen("jellous.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    fac(); inv1(); invfac();
    cin >> h >> w >> n;
    //for ( int i = 0; i <= 50; i++) cout << invfact[i] << '\n';
    for (int i = 1; i <= n; i++) {
        cin >> t[i].first >> t[i].second;
    }
    t[0].first  = 1;
    t[0].second = 1;
    sort(t, t + n + 1);
    reverse(t, t + n + 1);
    cout  << rec(n, n);
    return 0;
}