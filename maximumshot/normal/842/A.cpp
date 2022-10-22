#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int l, r, x, y, k;

    cin >> l >> r >> x >> y >> k;

    for(int b = x;b <= y;b++) {
        if(1ll * b * k >= l && 1ll * b * k <= r) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}