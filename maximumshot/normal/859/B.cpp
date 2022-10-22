#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    int res = inf;

    for(int x = 1;x <= n;x++) {
        int y = (n + x - 1) / x;
        res = min(res, 2 * (x + y));
    }

    cout << res << "\n";

    return 0;
}