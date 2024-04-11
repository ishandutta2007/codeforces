#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

set<pii> was, vec;
int last_x = -1, last_y = -1;

void check(int x, int y) {
    assert(!was.count({x, y}));
    assert(x >= 1);
    assert(y >= 1);
    was.insert({x, y});
    if (last_x != -1) {
        int dx = x - last_x;
        int dy = y - last_y;
        assert(!vec.count({dx, dy}));
//        cout << "d = " << dx << " " << dy << " pt = " << x << " " << y << "\n";
        vec.insert({dx, dy});
    }
    last_x = x;
    last_y = y;
}

void solve_one(int col, int n) {
    int x = 1;
    for (int sh = n - 1, i = 0; i < n; i++, sh--) {
        cout << x << " " << col << "\n";
//        check(x, col);
        if (i & 1) {
            x -= sh;
        } else {
            x += sh;
        }
    }
}

void solve(int l, int r, int n) {
    if (l > r) return;
    if (l == r) {
        solve_one(l, n);
        return;
    }
    for (int i = 0; i < n / 2; i++) {
        cout << 1 + i << " " << l << "\n";
        cout << n - i << " " << r << "\n";
//        check(1 + i, l);
//        check(n - i, r);
    }
    for (int i = n / 2; i < n; i++) {
        cout << 1 + i << " " << l << "\n";
        cout << n / 2 + (n % 2) - (i - n / 2) << " " << r << "\n";
//        check(1 + i, l);
//        check(n / 2 + n % 2 - (i - n / 2), r);
    }
    solve(l + 1, r - 1, n);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    solve(1, m, n);

    return 0;
}