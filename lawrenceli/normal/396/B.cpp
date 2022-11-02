#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (abs(a) > abs(b)) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b % a);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

struct fract {
    ll p, q; // p/q
    fract() {}
    fract(ll _p, ll _q) {
        ll g = gcd(_p, _q);
        if (g < 0) p = abs(_p) / g, q = -abs(_q) / g;
        else p = _p / g, q = _q / g;
    }

    fract operator+(fract f) {
        ll d = lcm(q, f.q);
        return fract(d/q*p + d/f.q*f.p, d);
    }
    friend ostream& operator<<(ostream& os, fract f) { //no idea why I'm doing this
        return os << f.p << '/' << f.q;
    }
};

bool prime(int x) {
    int k = 2;
    while (k*k <= x)
        if (x % k == 0) return 0;
        else k++;
    return 1;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int t; cin >> t;
    for (int i=0; i<t; i++) {
        int n; cin >> n;
        int p1 = n+1, p2 = n+1;
        while (!prime(p1)) p1--;
        while (!prime(p2)) p2++;
        cout << fract(1, 2) + fract(-1, p1) + fract(n - p1 + 1, ll(p1)*p2) << '\n';
    }

    return 0;
}