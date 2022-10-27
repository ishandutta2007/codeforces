#include<bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int N = 1 << 20;
using ll = int64_t;
int n;
constexpr ll power(ll a, ll b) {
    ll res = 1;
    for (; b > 0 ; a =  a * a % MOD, b >>= 1)
        if (b & 1) res = res * a % MOD;
    return res;
}

constexpr tuple <array<ll,N>, array<ll,N>, array<ll,N>> prefact() {
    array <ll,N> fac{};
    array <ll, N> pw2{};
    array <ll, N> invf{};
    fac[0] = 1;
    pw2[0] = 1;
    for (int i = 1 ; i < N ; ++ i)
        fac[i] = fac[i - 1] * i % MOD, pw2[i] = pw2[i - 1] * 2 % MOD;
    invf[N - 1] = power(fac[N - 1], MOD - 2);
    for (int i = N - 2 ; i >= 0 ; -- i)
        invf[i] = invf[i + 1] * (i + 1) % MOD;
    return make_tuple(fac, pw2, invf);
}
auto [fac, pw2, invf] = prefact();
constexpr ll C(int N, int R) {
    if (R < 0) return 0;
    if (R > N) return 0;
    return (fac[N] * invf[R] % MOD) * invf[N - R] % MOD;
}

int main() {
    cin >> n;

    ll ans = 0;
    /***
        the real sequence is
        A|B|A|B|A|B|A|B|A|B|
        where you can insert empty there
    */
    for (int i = n / 2 ; i <= n ; i ++) {
        if (i % 2) continue;
        if (i == n) {
            ans += fac[i];
            continue;
        }
        ll x = (C(i, n - i) + C(i - 1, n - i - 1));
        ans += x * fac[i] % MOD;
    }

    cout << ans * 2 % MOD << '\n';
}

/**
    no matter how "stupidly" B move, he always wins.
    The number of optimal games is just number of possible games.
    How to count it?
    Thinking it forward seems hard.
    Consider possible final states of game.
    A -> skip ? or place B
    Well, you can think about "skip" as C.
    Let's say the number of "non-C" in final states is X.
    You can takes those out in any order. X!
    summation of all states * X!
    Little combinatorial exercise.
    A _ B _ B _ B _ B _ B _ A
    Let's say each block of A has length L
    The number of ways to place B ?

    The problem boiled down to... Placing A over the circle.
    Each A has distance 1 or 2 between
    Or the sequence of 1 and 2 (1 1 2 1 2)
    A _ A _ _ A _ A _ _ A
    1 1 1 1 1 1 1 1 1 1 1
    x1 + x2 + ... + xk + k = n
    Each sequences contribute 2^L(where L is the number of twos).
    You can think of it this ways brute force over k
    number of ways to place is some kinds Choose(n-k, k..)
    add them and get answers
*/