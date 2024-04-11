#include <bits/stdc++.h>
using namespace std;
#define left neleft
#define right neright
const int maxN = 1005;
int n, m;
char a[maxN][maxN];
int left[maxN][maxN], right[maxN][maxN], down[maxN][maxN], up[maxN][maxN];
int ans[maxN][maxN];
bool ok[maxN][maxN];
int bal[maxN];
vector < pair < int, int >> all;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') continue;
            left[i][j] = left[i][j - 1] + (a[i][j - 1] == '*');
        }
        for (int j = m; j >= 1; j--) {
            if (a[i][j] == '.') continue;
            right[i][j] = right[i][j + 1] + (a[i][j + 1] == '*');
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == '.') continue;
            up[i][j] = up[i - 1][j] + (a[i - 1][j] == '*');
        }
        for (int i = n; i >= 1; i--) {
            if (a[i][j] == '.') continue;
            down[i][j] = down[i + 1][j] + (a[i + 1][j] == '*');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] = min({left[i][j], right[i][j], up[i][j], down[i][j]});
            if (ans[i][j] != 0) all.push_back(make_pair(i, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(bal, 0, sizeof bal);
        for (int j = 1; j <= m; j++) {
            if (ans[i][j] == 0) continue;
            bal[j - ans[i][j]]++;
            bal[j + ans[i][j] + 1]--;
        }
        int cur = 0;
        for (int j = 1; j <= m; j++) {
            cur += bal[j];
            if (cur > 0) ok[i][j] = true;
        }
    }
    for (int j = 1; j <= m; j++) {
        memset(bal, 0, sizeof bal);
        for (int i = 1; i <= n; i++) {
            if (ans[i][j] == 0) continue;
            bal[i - ans[i][j]]++;
            bal[i + ans[i][j] + 1]--;
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += bal[i];
            if (cur > 0) ok[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((a[i][j] == '*') && (!ok[i][j])) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << all.size() << '\n';
    for (int i = 0; i < all.size(); i++) {
        cout << all[i].first << " " << all[i].second << " " << ans[all[i].first][all[i].second] << '\n';
    }
    return 0;
}