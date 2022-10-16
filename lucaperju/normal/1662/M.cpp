/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int mx[] = {0, 0};
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            mx[0] = max(mx[0], x);
            mx[1] = max(mx[1], y);
        }
        if (mx[0] + mx[1] > n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i = 1; i <= mx[0]; i++) {
                cout << "R";
            }
            for (int i = 1; i <= max(mx[1], n - mx[0]); i++) {
                cout << "W";
            }
            cout << "\n";
        }
    }

    return 0;
}