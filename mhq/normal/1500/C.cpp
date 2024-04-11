#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1505;
int a[maxN][maxN];
int b[maxN][maxN];
int f[maxN];
bool used[maxN];
bool cut[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i < n; i++) {
            if (b[i][j] > b[i + 1][j]) f[j]++;
        }
    }
    vector<int> ans;
    while (true) {
        int z = -1;
        for (int j = 1; j <= m; j++) {
            if (f[j] == 0 && !used[j])  {
                z = j;
                break;
            }
        }
        if (z == -1) break;
        ans.emplace_back(z);
        used[z] = true;
        for (int j = 1; j < n; j++) {
            if (!cut[j] && b[j][z] < b[j + 1][z]) {
                cut[j] = true;
                for (int p = 1; p <= m; p++) {
                    if (b[j][p] > b[j + 1][p]) f[p]--;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    vector<int> row(n);
    iota(row.begin(), row.end(), 1);
    for (int id : ans) {
        stable_sort(row.begin(), row.end(), [&](int x, int y) {
           return a[x][id] < a[y][id];
        });
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[row[i]][j] != b[i + 1][j]) {
                ok = false;
                break;
            }
        }
    }
    if (ok) {
        cout << ans.size() << '\n';
        for (int v : ans) cout << v << " ";
    }
    else {
        cout << -1;
    }
    return 0;
}