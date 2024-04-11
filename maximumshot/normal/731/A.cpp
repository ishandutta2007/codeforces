#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int res = 0;
    string s;
    cin >> s;

    int last = 0;

    for(auto t : s) {
        int x = t - 'a';
        int d = abs(x - last);
        d = min(d, 26 - d);
        res += d;
        last = x;
    }

    cout << res << "\n";

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