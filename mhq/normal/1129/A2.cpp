#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
const int maxN = 5005;
vector < int > g[maxN];
int opt[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) continue;
        opt[i] = (int)1e9;
        for (int to : g[i]) {
            int d = 0;
            if (to >= i) d = to - i;
            else d = n + to - i;
            // i > to
            opt[i] = min(opt[i], n * ((int)g[i].size() - 1) + d);
        }
    }
    for (int i = 1; i <= n; i++) {
        int best = 0;
        for (int to = 1; to <= n; to++) {
            if (g[to].empty()) continue;
            int d = 0;
            if (to >= i) d = to - i;
            else d = n + to - i;
            best = max(best, opt[to] + d);
        }
        cout << best << " ";
    }
}