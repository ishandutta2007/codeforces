#include<bits/stdc++.h>
using namespace std;
const int nax = 256;
int n[3];
int a[3][nax];
long long dp[nax][nax][nax];
using ll = long long;

ll rec (int x, int y, int z) {
    if (dp[x][y][z] != -1) return dp[x][y][z];
    ll &res = dp[x][y][z];
    res = 0;

    if (x) {
        res = max(res, rec(x - 1, y, z));
    }
    
    if (y) {
        res = max(res, rec(x, y - 1, z));
    }

    if (z) {
        res = max(res, rec(x, y, z - 1));
    }

    if (x && y) {
        ll w = rec(x - 1, y - 1, z);
        res = max(res, a[0][x] * a[1][y] + w);
    }

    if (x && z) {
        ll w = rec(x - 1, y, z - 1);
       res = max(res, a[0][x] * a[2][z] + w);
    }

    if (y && z) {
        ll w = rec(x, y - 1, z - 1);
        res  = max(res, a[1][y] * a[2][z] + w);
    }
    return res;
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 0 ; i < 3 ; ++ i)
        cin >> n[i];

    for (int i = 0 ; i < 3  ; ++ i) {
        for (int j = 1 ; j <= n[i] ; ++ j)
            cin >> a[i][j];
        sort(a[i] + 1, a[i] + n[i] + 1, greater <int>());
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;


    ll ans = 0;
    for (int i = 0 ; i <= n[0] ; ++ i)
    for (int j = 0 ; j <= n[1] ; ++ j)
    for (int k = 0 ; k <= n[2] ; ++ k)
        ans = max(ans, rec(i, j, k));

    cout << ans << '\n';



}