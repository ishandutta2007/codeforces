#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxN = 2 * 1e5;
long long fact[maxN];
long long invfact[maxN];
long long inv[maxN];
long long f, w, h;
void calc() {
    fact[0] = 1;
    for ( int i = 1; i <= maxN - 1; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv[1] = 1;
    for ( int i = 2; i <= maxN - 1; i++) {
        inv[i] = ((((-(mod / i)) * inv[mod % i]) % mod) + mod) % mod;
    }
    invfact[0] = 1;
    for ( int i = 1; i <= maxN - 1; i++) {
        invfact[i] = (invfact[i - 1] * inv[i]) % mod;
    }
}
long long cnk(long long k, long long n) {
    if ( n < 0 || n < k || k < 0) return 0;
    return (((fact[n] * invfact[k]) % mod) * invfact[n - k]) % mod;
}
long long binpow(long long x, int y) {
    if (y == 0) return 1;
    if (y & 1) {
        y = y >> 1;
        return (((binpow(x, y) * binpow(x, y)) % mod) * x) % mod;
    }
    else {
        y = y >> 1;
        return (binpow(x, y) * binpow(x, y)) % mod;
    }
}
int main() {
    //freopen("jellous.in", "r", stdin);
    //freopen("jellous.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    calc();
    cin >> f >> w >> h; swap(f, w);
    // f - wino, h - eda;
    if (f == 0) {
        cout << 1;
        return 0;
    }
    if (w == 0) {
        if (f > h) {
            cout << 1;
        }
        else cout << 0;
        return 0;
    }
    long long ansq = 0;
    for ( int i = 1; i <= maxN - 3; i++) {
        ansq = (ansq + ((2 * cnk(i - 1, f - 1) * cnk(i - 1, w - 1)) % mod)) % mod;
        ansq = (ansq + ((cnk(i - 1, f - 1) * cnk(i, w - 1)) % mod)) % mod;
        ansq = (ansq + ((cnk(i, f - 1) * cnk(i - 1, w - 1)) % mod)) % mod;
    }
    long long ansp = 0;
    for ( int i = 1; i <= maxN - 3; i++) {
        ansp = (ansp + ((2 * cnk(i - 1, f - 1 - i * h) * cnk(i - 1, w - 1)) % mod)) % mod;
        ansp = (ansp + ((cnk(i - 1, f - 1 - i * h) * cnk(i, w - 1)) % mod)) % mod;
        ansp = (ansp + ((cnk(i, f - (i + 1) * h - 1) * cnk(i - 1, w - 1)) % mod)) % mod;
    }
    cout << (ansp * binpow(ansq, mod - 2)) % mod;
    return 0;
}