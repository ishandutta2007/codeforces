#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n;

    cin >> n;

    vector< ll > d;

    for(ll x = 1;x * x <= n;x++) {
        if(n % x) continue;
        d.push_back(x);
        if(x * x < n) d.push_back(n / x);
    }

    sort(d.rbegin(), d.rend());

    for(ll x : d) {
        ll k = n / x;
        cout << k + x * k * (k - 1) / 2 << " ";
    }
    cout << "\n";

    return 0;
}