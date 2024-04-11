#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, a[nax], x;
bool vis[nax];

void solve() {
    scanf("%d %d", &n, &x);
    vector <int> f[x];
    f[0].push_back(0);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        a[i] += a[i - 1];
        a[i] %= x;
        f[a[i]].push_back(i);
    }


    int ans = -1;
    for (int i = 0 ; i < x ; ++ i) {
        if (f[i].empty()) continue;
        for (int j : f[i])
            vis[j] = true;
        int p = f[i][0];
        if (!vis[n]) {
            ans = max(ans, n - p);
        }
        for (int j = f[i].size() - 1 ; j > 0 ; -- j) {
            if (f[i][j] > 0 && !vis[f[i][j] - 1]) {
                ans = max(ans, f[i][j] - p - 1);
            }
            if (!vis[f[i][j] + 1] && f[i][j] + 1 <= n) {
                ans = max(ans, f[i][j] - p + 1);
            }
        }
        for (int j : f[i])
            vis[j] = false;
    }

    printf("%d\n", ans);

}

int main () {
    int T;
    for (cin >> T ; T -- ; solve());

}