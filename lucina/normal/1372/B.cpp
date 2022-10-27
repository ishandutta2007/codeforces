#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

long long _lcm (long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}

void solve () {
    int n;
    cin >> n;

    int x = -1, y = -1;
    long long ans = LLONG_MAX;

    for (long long a = 1; a * a <= n ; ++ a ) {
        if (n % a == 0) {
            if (_lcm(a, n - a) < ans && a > 0 && n - a > 0) {
                ans = _lcm(a, n - a);
                x = a, y = n - a;
            }

            int c = n / a;
            if (_lcm(c, n - c) < ans && c > 0 && n - c > 0) {
                ans = _lcm(c, n - c);
                x = c, y = n - c;
            }
        }
    }

    cout << x << ' ' << y << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int t;

    for (cin >> t ; t -- ;) {
        solve();
    }
}
/*
    Firis is not airhead!
*/