#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)
#define mp make_pair

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int t;

    cin >> t;

    while(t--) {
        ll a, b;
        cin >> a >> b;
        if(a - b > 1) {
            cout << "NO\n";
            continue;
        }
        a += b;
        int ok = 1;
        for(ll x = 2;x * x <= a;x++) {
            if(a % x == 0) {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}