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

int f(int ax, int ay, int bx, int by) {
    return ((ax < bx) << 1) | ((ay < by) << 2);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    int ax, ay;
    int bx, by;
    int cx, cy;

    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    cout << (f(ax, ay, bx, by) == f(ax, ay, cx, cy) ? "YES" : "NO") << "\n";

    return 0;
}