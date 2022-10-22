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
        int n, k;
        cin >> n >> k;
        vector<pii> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int d = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
                if (d <= k)
                    g[i].push_back(j), g[j].push_back(i);
            }
        }
        int any = 0;
        for (int v = 0; v < n; v++) {
            if ((int) g[v].size() == n - 1)
                any = 1;
        }
        if (any)
            cout << 1 << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}