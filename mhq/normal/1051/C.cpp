#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
vector < int > all[maxN];
char ans[maxN];
int n;
bool no() {
    cout << "NO";
    exit(0);
}
bool dp[maxN][maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        all[x].push_back(i);
    }
    dp[0][0][0] = true;
    for (int i = 0; i + 1 <= 100; i++) {
        int p = all[i + 1].size();
        for (int f1 = 0; f1 <= 100; f1++) {
            for (int f2 = 0; f2 <= 100; f2++) {
                if (p == 0 || p >= 2) dp[i + 1][f1][f2] |= dp[i][f1][f2];
                if (p == 1 || p >= 3) {
                    dp[i + 1][f1 + 1][f2] |= dp[i][f1][f2];
                    dp[i + 1][f1][f2 + 1] |= dp[i][f1][f2];
                }
                if (p == 2) {
                    dp[i + 1][f1 + 1][f2 + 1] |= dp[i][f1][f2];
                }
            }
        }
    }
    int f1 = -1;
    int f2 = -1;
    for (int i = 0; i <= 100; i++) {
        if (dp[100][i][i]) {
            f1 = i;
            f2 = i;
            break;
        }
    }
    if (f1 == -1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    for (int i = 100; i >= 1; i--) {
        if (dp[i - 1][f1][f2] && all[i].size() != 1) {
            if (all[i].size() == 0) continue;
            else {
                for (int v : all[i]) ans[v] = 'A';
            }
            continue;
        }
        if (dp[i - 1][f1 - 1][f2] && all[i].size() >= 1 && all[i].size() != 2) {
            ans[all[i][0]] = 'A';
            for (int j = 1; j < all[i].size(); j++) ans[all[i][j]] = 'B';
            f1 -= 1;
            continue;
        }
        if (dp[i - 1][f1][f2 - 1] && all[i].size() >= 1 && all[i].size() != 2) {
            ans[all[i][0]] = 'B';
            for (int j = 1; j < all[i].size(); j++) ans[all[i][j]] = 'A';
            f2 -= 1;
            continue;
        }
        if (dp[i - 1][f1 - 1][f2 - 1] && all[i].size() == 2) {
            ans[all[i][0]] = 'A';
            ans[all[i][1]] = 'B';
            f1 -= 1;
            f2 -= 1;
            continue;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    return 0;
}