#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int n[4], dp[4][150000], m, x, y, temp;
pair<int, set<int>> a[4][150000];
set<pair<int, int>> dpt[4];

int dfs(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j]=INT_MAX;
    for (auto p : dpt[i-1]) {
        if (a[i][j].S.find(p.S)==a[i][j].S.end()) {
            dp[i][j] = min(dp[i][j], p.F);
            break;
        }
    }
    if (dp[i][j]<INT_MAX) dp[i][j] += a[i][j].F;
    dpt[i].insert(mp(dp[i][j], j));
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 4; i++) cin >> n[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j].F;
            dp[i][j]=-1;
        }
    }
    for (int j = 0; j < n[0]; j++) {
        dp[0][j] = a[0][j].F;
        dpt[0].insert(mp(dp[0][j], j));
    }
    for (int i = 1; i < 4; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> x >> y;
            a[i][y-1].S.insert(x-1);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++) {
            dfs(i, j);
        }
    }
    for (int i = 0; i < n[3]; i++) {
        ans = min(ans, dfs(3, i));
    }
    if (ans==INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
}