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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pii> a(3);

    int lx = inf;
    int rx = -inf;
    int ly = inf;
    int ry = -inf;

    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        lx = min(lx, x);
        rx = max(rx, x);
        ly = min(ly, y);
        ry = max(ry, y);
    }

    cout << rx - lx + ry - ly + 1 << "\n";

    sort(a.begin(), a.end());

    for (int y = ly; y <= ry; y++) {
        cout << a[1].first << " " << y << "\n";
    }

    for (int x = lx; x < a[1].first; x++) {
        cout << x << " " << a[0].second << "\n";
    }

    for (int x = rx; x > a[1].first; x--) {
        cout << x << " " << a[2].second << "\n";
    }

    return 0;
}