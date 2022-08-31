#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2005;
int a[maxN], b[maxN], c[maxN], d[maxN];
int n, m;
const int maxP = 1e6 + 228;
vector<int> f[maxP];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] <= c[j] && b[i] <= d[j]) {
                f[c[j] - a[i]].emplace_back(d[j] - b[i] + 1);
            }
        }
    }
    int best = 1e9;
    int mx = 0;
    for (int i = maxP - 2; i >= 0; i--) {
        for (auto& it : f[i]) {
            mx = max(mx, it);
        }
        best = min(best, i + mx);
    }
    cout << best;
    return 0;
}