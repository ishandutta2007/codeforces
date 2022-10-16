#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n, m;
int s[5005];
vector <int> pos[5005];
int a[5005], x[5005], y[5005];
int moo[5005];
int f[5005][3];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) pos[s[i]].push_back(i);
    for (int i = 1; i <= m; ++i) {
        int go;
        cin >> a[i] >> go;
        if (go > pos[a[i]].size()) {
            x[i] = y[i] = -1;
            continue;
        }
        x[i] = pos[a[i]][go - 1];
        y[i] = pos[a[i]][pos[a[i]].size() - go];
        moo[x[i]] = i;
    }
    int ans = 0, ways = 1;
    ///special case
    {
        int cnt = 0, ways2 = 1;
        for (int i = 1; i <= m; ++i) {
            if (x[i] == -1) continue;
            ++f[a[i]][0];
        }
        for (int i = 1; i <= n; ++i) {
            if (f[i][0]) {
                cnt += 1;
                ways2 = 1ll * ways2 * f[i][0] % mod;
            }
        }
        if (cnt > ans) {
            ans = cnt;
            ways = ways2;
        }
        else if (cnt == ans) {
            ways = (ways + ways2) % mod;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!moo[i]) continue;
        memset(f, 0, sizeof f);
        for (int j = 1; j <= m; ++j) {
            if (x[j] == -1 || x[j] == i) continue;
            int id = (y[j] > i);
            if (a[j] != s[i]) id += (x[j] < i) * 2;
            if (id) ++f[a[j]][id - 1];
        }
        int cnt = 1, ways2 = 1;
        for (int j = 1; j <= n; ++j) {
            int sa = f[j][0], sb = f[j][1], sab = f[j][2];
            int s2 = sa * (sb + sab) + sab * (sab + sb - 1);
            if (s2) {
                cnt += 2;
                ways2 = 1ll * ways2 * s2 % mod;
                continue;
            }
            int s1 = sa + sb + 2 * sab;
            if (s1) {
                cnt += 1;
                ways2 = 1ll * ways2 * s1 % mod;
            }
        }
        if (cnt > ans) {
            ans = cnt;
            ways = ways2;
        }
        else if (cnt == ans) {
            ways = (ways + ways2) % mod;
        }
    }
    if (ans == 0) ways = 1;
    cout << ans << ' ' << ways << endl;
    return 0;
}