#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

bool check(ld k, ld d, ld t, ld T) {
    ld res = 0.0;
    ld cnt = ll(T) / ll(d);
    res = cnt * (2 * k + (d - k));
    ld md = T - cnt * d;
    ld y = min(md, k);
    res += 2 * y + (md - y);
    return res >= t * 2;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll k, d, t;

    cin >> k >> d >> t;

    ll x = (k + d - 1) / d;

    d *= x;

    ld bl = 0.0;
    ld br = 4e18;
    ld bm;

    check(k, d, t, 6.5);

    for(int i = 0;i < 1000;i++) {
        bm = (bl + br) * 0.5;
        if(check(k, d, t, bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    cout.precision(20);
    cout << fixed;
    cout << bl << "\n";

    return 0;
}