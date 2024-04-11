#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int res;
    cin >> res;
    return res;
}

void ans(int x1, int y1, int x2, int y2) {
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int lx = 1;
    while (lx < n && ask(1, 1, lx, n) % 2 == 0) lx++;

    int rx = n;
    while (rx > 1 && rx >= lx && ask(rx, 1, n, n) % 2 == 0) rx--;

    int ly = 1;
    while (ly < n && ask(1, 1, n, ly) % 2 == 0) ly++;

    int ry = n;
    while (ry > 1 && ry >= ly && ask(1, ry, n, n) % 2 == 0) ry--;

    if (lx <= rx && ly <= ry) {
        if (ask(lx, ly, lx, ly) == 1) {
            ans(lx, ly, rx, ry);
        } else {
            ans(lx, ry, rx, ly);
        }
        return 0;
    }

    if (lx <= rx) {
        int bl = 0;
        int br = n;
        int bm;
        while (br - bl > 1) {
            bm = (bl + br) / 2;
            if (ask(rx, 1, n, bm) % 2) {
                br = bm;
            } else {
                bl = bm;
            }
        }
        ans(lx, br, rx, br);
        return 0;
    }

    if (ly <= ry) {
        int bl = 0;
        int br = n;
        int bm;
        while (br - bl > 1) {
            bm = (bl + br) / 2;
            if (ask(1, ry, bm, n) % 2) {
                br = bm;
            } else {
                bl = bm;
            }
        }
        ans(br, ly, br, ry);
        return 0;
    }

    ans(1, 1, n, n);

    return 0;
}