#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        int res = 0;
        for (int x = 0; x < 5; x++) {
            for (int y = x + 1; y < 5; y++) {
                int c1 = 0, c2 = 0, c3 = 0, ok = 1;
                for (int i = 0; i < n; i++) {
                    if (a[i][x] && a[i][y]) {
                        c3++;
                    } else if (a[i][x]) c1++;
                    else if (a[i][y]) c2++;
                    else {
                        ok = 0;
                        break;
                    }
                }
                if (ok && c1 <= n / 2 && c2 <= n / 2)
                    res = 1;
            }
        }
        cout << (res ? "YES" : "NO") << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}