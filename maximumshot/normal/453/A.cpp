#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.precision(20);
    cout << fixed;

    ld m, n;

    cin >> m >> n;

    ld res = m;

    for (ld k = 0; k < m; k++) {
        ld x = n * (logl(k) - logl(m));
        res -= expl(x);
    }

    cout << res << "\n";

    return 0;
}