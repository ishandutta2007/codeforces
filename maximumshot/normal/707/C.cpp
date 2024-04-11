#include <bits/stdc++.h>

#include <time.h>
#include <random>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool check(ll a, ll b, ll c) {
    return a > 0 && b > 0 && c > 0 &&
            (a * a + b * b == c * c ||
             (a * a + c * c == b * b) ||
             (b * b + c * c == a * a));
}

bool solve() {

    ll a;
    cin >> a;

    if(a <= 2) {
        cout << "-1\n";
        return true;
    }

    if(a % 2) {
        ll m = a / 2;
        ll b, c;
        b = 2 * m * m + 2 * m;
        c = 2 * m * m + 2 * m + 1;
        if(check(a, b, c)) {
            cout << b << " " << c << "\n";
            return true;
        }
    }else {
        ll m = a / 2;
        ll n = 1;
        ll b, c;
        b = m * m - n * n;
        c = m * m + n * n;
        if(check(a, b, c)) {
            cout << b << ' ' << c << '\n';
            return true;
        }
    }

    cout << "-1\n";

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}