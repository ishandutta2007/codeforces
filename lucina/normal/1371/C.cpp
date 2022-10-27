#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long;

bool solve () {
    ll v, c, n, m;

    cin >> v >> c >> n >> m;

    if (v > c) {
        ll dif = v - c;
        if (n >= dif) {
            n -= dif;
            v = c;
        } else {
            n = 0;
            return c >= m;
        }
    } else if (c > v) {
        ll dif = c - v;
        if (n >= dif) {
            n -= dif;
            c = v;
        } else {
            n = 0;
            return v >= m;
        }
    }


    assert(v == c);
    ll has = min(n, m);

    n -= has;
    m -= has;

    v -= has;
    c -= has;
    if (v < 0) return false;

    if (n > 0) {
        return v + c >= n;
    } else if (m > 0) {
        return v >= m;
    }

    return true;
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        cout << (solve() ? "Yes" : "No") << '\n';
    }
}
/*
    Song of leaving home.
*/