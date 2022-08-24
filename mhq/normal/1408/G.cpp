#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1505;
int a[maxN][maxN];
const int maxP = maxN * maxN / 2;
vector<pair<int,int>> when[maxP];
int ans[maxN];
vector<int> g[2 * maxN];
int p[2 * maxN];
int cnt_bad[2 * maxN];
int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}
bool good[2 * maxN];
int dp[2 * maxN][2 * maxN];
int sz[2 * maxN];
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int ndp[2 * maxN];
void dfs(int v) {
    sz[v] = 0;
    if (g[v].empty()) sz[v]++;
    dp[v][0] = 1;
    for (int to : g[v]) {
        dfs(to);
        for (int i = 0; i <= sz[v] + sz[to]; i++) ndp[i] = 0;
        for (int j = sz[v]; j >= 0; j--) {
            for (int t = 1; t <= sz[to]; t++) {
                ndp[j + t] = sum(ndp[j + t], mult(dp[v][j], dp[to][t]));
            }
        }
        sz[v] += sz[to];
        for (int j = 0; j <= sz[v]; j++) {
            dp[v][j] = ndp[j];
            ndp[j] = 0;
        }
        dp[v][0] = 0;
    }
    if (good[v]) {
        dp[v][1] = sum(dp[v][1], 1);
    }
    dp[v][0] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            when[a[i][j]].emplace_back(i, j);
        }
    }
    for (int i = 0; i <= 2 * n; i++) {
        p[i] = i;
        good[i] = false;
    }
    for (int i = 0; i < n; i++) good[i] = true;
    int cur = n;
    for (int i = 1; i <= (n * (n - 1)) / 2; i++) {
        for (auto& it : when[i]) {
            if (find(it.first) != find(it.second)) {
                g[cur].emplace_back(find(it.first));
                g[cur].emplace_back(find(it.second));
                cnt_bad[cur] = cnt_bad[find(it.first)] + cnt_bad[find(it.second)];
                vector<int> f1, f2;
                for (int r = 0; r < n; r++) {
                    if (find(r) == find(it.first)) f1.emplace_back(r);
                    else if (find(r) == find(it.second)) f2.emplace_back(r);
                }
                for (int x : f1) {
                    for (int y : f2) {
                        if (a[x][y] > i) {
                            cnt_bad[cur]++;
                        }
                    }
                }
              /*  cout << " UNITE " << endl;
                for (int x : f1) cout << x << " ";
                cout << endl;
                for (int y : f2) cout << y << " ";
                cout << endl;
                cout << "------" << endl;
                cout << " GOT " << cnt_bad[cur] << endl;*/
                if (cnt_bad[cur] == 0) good[cur] = true;
                p[find(it.first)] = cur;
                p[find(it.second)] = cur;
                cur++;
            }
            else {
                cnt_bad[find(it.first)]--;
                if (cnt_bad[find(it.first)] == 0) {
                    good[find(it.first)] = true;
                }
            }
        }
    }
    cur--;
    dfs(cur);
    for (int i = 1; i <= n; i++) {
        cout << dp[cur][i] << " ";
    }
    return 0;
}