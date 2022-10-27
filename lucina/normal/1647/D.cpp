#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

bool is_prime(int64_t x) {
    for (int64_t j = 2 ; j * j <= x ; ++ j) {
        if (x % j == 0) return false;
    }
    return true;
}
int64_t sm_prime(int64_t x) {
    for (int64_t j = 2 ; j * j <= x ; ++ j) {
        if (x % j == 0) return j;
    }
    return x;
}

bool is_single_prime(int64_t x) {
    int64_t y = sm_prime(x);
    while (x % y == 0) x /= y;
    return x == 1;
}
bool WAT;
int f;
bool solve() {
    int64_t x, d;
    int64_t sx;
    cin >> x >> d;
    ++ f;
    sx = x;
    int cnt = 0;
    while (x % d == 0) {
        cnt += 1;
        x /= d;
    }
    if (cnt <= 1) return false;
    bool pr = is_prime(d);
    if (d % x != 0) {
        if (!is_prime(x)) return true;
        if (cnt >= 3 && !pr) return true;
        return false;
    }

    bool px = is_prime(x);
    if (cnt == 2) {
        return !px;
    }

    if (x == 1) {
        return !pr;
    }
    if (cnt == 3) {
        if (!px) return true;
        int64_t foo = sx;
        int c = 0;
        while (foo % x == 0) foo /= x, ++ c;
        if (foo != 1) return true; /// at least two different primes;
        int cd = 0;
        while (d % x == 0) d /= x, ++ cd;
        if (2 * cd <= c && c <= 4 * cd - 2) return true;
        return false;
    }
    assert(!pr);
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    if (T == 100) WAT =true;
    for ( ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}