#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

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

    unordered_map< int, int > mx;

    for(int i = 0;i < 2;i++) {
        int n;
        scanf("%d", &n);
        for(int j = 0;j < n;j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            mx[x] = max(mx[x], y);
        }
    }

    ll res = 0;

    for(pii it : mx) {
        res += it.second;
    }

    cout << res << "\n";

    return 0;
}