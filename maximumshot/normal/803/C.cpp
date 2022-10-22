#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

inline bool check(ll value, ll cnt) {
    long double a2 = cnt;
    if((1 + a2) * a2 / 2.0 > 1e18) return false;
    return (1 + cnt) * cnt / 2 <= value;
}

int main() {

    ll n, k;

    cin >> n >> k;

    if(!check(n, k)) {
        cout << "-1\n";
        return 0;
    }

    ll best = 1;

    for(ll x = 1;x * x <= n;x++) {
        if(n % x) continue;
        if(check(n / x, k)) best = max(best, x);
        if(check(x, k)) best = max(best, n / x);
    }

    n /= best;

    for(ll i = 1;i < k;i++) {
        cout << best * i << " ";
        n -= i;
    }

    cout << best * n << "\n";

    return 0;
}