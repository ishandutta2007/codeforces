#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

ll gcd(ll a, ll b) {
    return !a ? b : gcd(b % a, a);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll l, r, x, y;

    cin >> l >> r >> x >> y;

    vec< ll > arr;

    for(ll a = 1;a * a <= y;a++) {
        if(y % a == 0) arr.push_back(a), arr.push_back(y / a);
    }

    sort(ALL(arr));
    arr.resize(unique(ALL(arr)) - arr.begin());

    set< pll > res;

    for(ll a : arr) {
        ll b = x * y / a;
        if(gcd(a, b) == x && lcm(a, b) == y && l <= a && a <= r && l <= b && b <= r) {
            res.insert({a, b});
        }
    }

    cout << (int)res.size() << "\n";

    return 0;
}