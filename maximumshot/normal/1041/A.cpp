#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    int mx = -inf;
    int mn = +inf;

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        if(x > mx) mx = x;
        if(x < mn) mn = x;
    }

    cout << mx - mn + 1 - n << "\n";

    return 0;
}