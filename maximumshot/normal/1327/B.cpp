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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        g[i].resize(sz);
        for (int j = 0; j < sz; j++) {
            cin >> g[i][j];
        }
    }
    vector<int> used(n + 1);
    int d = -1;
    for (int i = 1; i <= n; i++) {
        int any = 0;
        for (int j = 0; j < (int) g[i].size(); j++) {
            int x = g[i][j];
            if (!used[x]) {
                used[x] = 1;
                any = 1;
                break;
            }
        }
        if (!any)
            d = i;
    }
    if (d == -1) {
        cout << "OPTIMAL\n";
    } else {
        cout << "IMPROVE\n";
        int x = 1;
        while (used[x])
            x++;
        cout << d << " " << x << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    for (int ti = 0; ti < tt; ti++) {
        solve();
    }

    return 0;
}