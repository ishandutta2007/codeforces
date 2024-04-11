#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ll n, t, k, d;

    cin >> n >> t >> k >> d;

    ll time1 = ((n + k - 1) / k) * t;
    ll time2 = inf64;

    for(ll x1 = 0;x1 <= n;x1++) {
        ll x2 = n - x1;
        time2 = min(time2, max(d + ((x1 + k - 1) / k) * t, ((x2 + k - 1) / k) * t));
    }

    if(time1 <= time2) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }

    return 0;
}