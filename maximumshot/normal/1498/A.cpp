#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

ll sum(ll x) {
    ll res = 0;
    while (x > 0)
        res += x % 10, x /= 10;
    return res;
}

ll gcd_sum(ll x) {
    return gcd(x, sum(x));
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        while (gcd_sum(n) == 1)
            n++;
        cout << n << "\n";
    }

    return 0;
}