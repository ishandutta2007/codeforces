#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 66;
int a[maxN][maxN];
map < int, int > mp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n + m; i++) mp[i].clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                int d = min(i + j, n + m - 2 - i - j);
                mp[d][a[i][j]]++;
            }
        }
        int tot = 0;
        for (int i = 0; i <= n + m; i++) {
            if (i == n + m - 2 - i) continue;
            if (mp[i].empty()) continue;
            int mx = 0;
            int all = 0;
            for (auto& it : mp[i]) {
                all += it.second;
                mx = max(mx, it.second);
            }
            tot += all - mx;
        }
        cout << tot << '\n';
    }
    return 0;
}