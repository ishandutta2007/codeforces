#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 2e18;

long long n, k;

long long white(long long x, long long y) {
    if (x == 0 ||y == 0)
        return 0;
    if (x*y % 2 == 0)
        return x * y / 2;
    return x * y / 2 + 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int o = 0; o < t; o++) {
        long long n, m, x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        long long kb = white(n, m);
        long long w1 = white(x2, y2) + white(x1 - 1, y1 - 1) - white(x2, y1 - 1) - white(x1 - 1, y2);
        kb += (x2 - x1 + 1) * (y2 - y1 + 1) - w1;
        long long w2 = white(x4, y4) + white(x3 - 1, y3 - 1) - white(x4, y3 - 1) - white(x3 - 1, y4);
        kb -= w2;
        long long x5, y5, x6, y6;
        x5 = max(x1, x3);
        y5 = max(y1, y3);
        x6 = min(x2, x4);
        y6 = min(y2, y4);
        x3 = x5, y3 = y5, x2 = x6, y2 = y6;
        if (x3 <= x2 && y3 <= y2) {
            long long w3 = white(x2, y2) + white(x3 - 1, y3 - 1) - white(x2, y3 - 1) - white(x3 - 1, y2);
            kb -= (x2 - x3 + 1) * (y2 - y3 + 1) - w3;
        }
        cout << kb << ' ' << n * m - kb << "\n";
    }
    return 0;
}