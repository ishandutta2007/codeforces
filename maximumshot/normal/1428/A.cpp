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

    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2 || y1 == y2) {
            int len = abs(x1 - x2) + abs(y1 - y2);
            cout << len << "\n";
        } else {
            int w = abs(x1 - x2);
            int h = abs(y1 - y2);
            cout << w + h + 2 << "\n";
        }
    }

    return 0;
}