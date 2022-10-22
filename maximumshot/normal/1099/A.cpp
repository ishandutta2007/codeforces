#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

ll get(ll lh, ll rh) { // [lh, rh], lh > rh
    return (lh + rh) * (lh - rh + 1) / 2;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll w, h;

    cin >> w >> h;

    ll u1, d1, u2, d2;

    cin >> u1 >> d1 >> u2 >> d2;

    if(d1 < d2) {
        swap(d1, d2);
        swap(u1, u2);
    }

    w += get(h, d1);
    w = max(0ll, w - u1);

    h = d1 - 1;
    w += get(h, d2);
    w = max(0ll, w - u2);
    h = d2 - 1;

    w += get(h, 0);

    cout << w << "\n";

    return 0;
}