#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int dp[5010][5010];
int a[120000];
int b[120000];
vector<int> nxv[120000];
vector<int> nx2v[10];
int nx[120000];
int nx2[10];
int n;
int go[120000];


void upd(int x, int y, int a) {
    dp[x][y] = max(dp[x][y], a);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], b[i] = a[i] % 7;
    for (int i = 0; i < 120000; ++i)
        nx[i] = -1;
    for (int i = 0; i < 7; ++i)
        nx2[i] = -1;
    for (int i = n - 1; i >= 0; --i) {
        go[i] = 1;
        if (nx[a[i] + 1] != -1)
            go[i] = max(go[i], go[nx[a[i] + 1]] + 1);
        if (nx[a[i] - 1] != -1)
            go[i] = max(go[i], go[nx[a[i] - 1]] + 1);
        if (nx2[a[i] % 7] != -1)
            go[i] = max(go[i], go[nx2[a[i] % 7]] + 1);
        nx[a[i]] = i;
        nx2[a[i] % 7] = i;
    }
    int ans = 0;
    for (int i = 0; i < 120000; ++i)
        nx[i] = 0;
    for (int i = 0; i < 7; ++i)
        nx2[i] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            nxv[a[j]].clear(), nx[a[j]] = 0;
        for (int j = 0; j < 7; ++j)
            nx2v[j].clear(), nx2[j] = 0;
        for (int j = i - 1; j >= 0; --j)
            nxv[a[j]].push_back(j), nx2v[b[j]].push_back(j);
        for (int j = 0; j < i; ++j) {
            nxv[a[j]].pop_back();
            nx2v[b[j]].pop_back();
            upd(i, j, 2);
            ans = max(ans, dp[i][j] - 1 + go[i]);
            if (!nxv[a[j] - 1].empty())
                upd(i, nxv[a[j] - 1].back(), dp[i][j] + 1);
            if (!nxv[a[j] + 1].empty())
                upd(i, nxv[a[j] + 1].back(), dp[i][j] + 1);
            if (!nx2v[b[j]].empty())
                upd(i, nx2v[b[j]].back(), dp[i][j] + 1);
            nx[a[j]] = max(nx[a[j]], dp[i][j]);
            nx2[b[j]] = max(nx2[b[j]], dp[i][j]);
        }
        for (int j = i + 1; j < n; ++j) {
            dp[j][i] = max(dp[j][i], nx[a[j] - 1] + 1);
            dp[j][i] = max(dp[j][i], nx[a[j] + 1] + 1);
            dp[j][i] = max(dp[j][i], nx2[b[j]] + 1);
        }
    }
    cout << ans << "\n";
    return 0;
}