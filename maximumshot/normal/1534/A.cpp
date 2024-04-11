#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

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
        int n, m;
        cin >> n >> m;
        vector<string> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int any = 0;
        for (int x = 0; x < 2; x++) {
            b = a;
            int ok = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int c = (i + j + x) % 2;
                    if (c) { // R
                        if (b[i][j] == 'W') {
                            ok = 0;
                        }
                        b[i][j] = 'R';
                    } else { // W
                        if (b[i][j] == 'R') {
                            ok = 0;
                        }
                        b[i][j] = 'W';
                    }
                }
            }
            if (ok) {
                any = 1;
                cout << "YES\n";
                for (auto row : b)
                    cout << row << "\n";
                break;
            }
        }
        if (!any)
            cout << "NO\n";
    }

    return 0;
}