//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

const int N = 100100;
const int M = 1e9 + 7;

int kek[N];

ll binpow(ll a, int p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= M;
        }
        (a *= a) %= M;
        p >>= 1;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++kek[a];
    }
    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        int m = i;
        int r = 0;
        for (int j = 2; j * j <= i; ++j) {
            if (m % (j * j) == 0) {
                r = -5;
                break;
            }
            if (m % j == 0) {
                m /= j;
                ++r;
            }
        }
        r += (m > 1);
        int p = 0;
        for (int j = i; j < N; j += i) {
            p += kek[j];
        }
        if (r >= 0) {
            (ans = ans + M + (r % 2 ? -1 : 1) * (binpow(2, p) - 1)) %= M;
        }
    }
    cout << ans;
    return 0;
}