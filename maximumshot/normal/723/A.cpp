#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int res = inf;

    for(int x = 1;x <= 100;x++)
        res = min(res, abs(x - x1) + abs(x - x2) + abs(x - x3));

    cout << res << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}