#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 1.2e6 + 5;

int d[N];

void solve() {
    ll p, q;
    cin >> p >> q;
    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (d[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * 2; j < N; j += i) {
            d[j] = i;
        }
    }
    vector<int> palindromes;
    vector<int> digits;
    for (int i = 1; i < N; i++) {
        digits.clear();
        int n = i;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int ok = 1;
        for (int i = 0; i < digits.size() / 2; i++) {
            ok &= digits[i] == digits[digits.size() - 1 - i];
        }
        if (ok) {
            palindromes.push_back(i);
        }
    }
    int last = -1;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 1; i < N; i++) {
        while (cnt1 < primes.size() && primes[cnt1] <= i) {
            cnt1++;
        }
        while (cnt2 < palindromes.size() && palindromes[cnt2] <= i) {
            cnt2++;
        }
        if (cnt1 * q <= cnt2 * p) {
            last = i;
        }
    }
    cout << last << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}