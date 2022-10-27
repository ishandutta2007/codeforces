#include<bits/stdc++.h>
using namespace std;
const int nax = 128;

int64_t n;


int main() {

    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;

    for (int tt = 1 ; tt <= T ; ++ tt) {
        cin >> n;
        int64_t x = n;
        if (x % 2) {
            cout << "-1\n";
            continue;
        }
        int cx = 0, cy = 0;
        while (x % 6 != 0) x -= 4, cx += 1;
        x = x / 6 + cx;
        int64_t y = n;
        while (y % 4 != 0) y -= 6, cy += 1;
        y  = y / 4 + cy;
        if (min(x, y) <= 0) cout << "-1\n";
        else cout << min(x, y) << ' ' << max(x, y) << '\n';
    }
}
/*
    GCJ
*/