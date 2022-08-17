#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2011, inf = 1000111222;

int n, m, a;
bool is_rain[max_n];
int is_z[max_n];

int dp[max_n][max_n];
bool vis[max_n][max_n];

int f(int pos, int zn) {
    if (vis[pos][zn + 1]) {
        return dp[pos][zn + 1];
    }
    if (pos == a) {
        return 0;
    }

    int ans = inf;
    if (is_rain[pos]) {
        if (zn == -1) ans = inf;
        else ans = is_z[zn] + f(pos + 1, zn);
    } else {
        if (zn == -1) ans = f(pos + 1, -1);
        else ans = min(is_z[zn] + f(pos + 1, zn), f(pos + 1, -1));
    }

    if (is_z[pos]) {
        int ans1 = is_z[pos] + f(pos + 1, pos);
        ans = min(ans, ans1);
    }

    dp[pos][zn + 1] = ans;
    vis[pos][zn + 1] = 1;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> a >> n >> m;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j < r; ++j) {
            is_rain[j] = 1;
        }
    }
    for (int i = 0; i < m; ++i) {
        int pos, x;
        cin >> pos >> x;
        if (is_z[pos] == 0)
            is_z[pos] = x;
        else {
            is_z[pos] = min(is_z[pos], x);
        }
    }

    int ans = f(0, -1);
    if (ans >= inf) {
        cout << -1;
        return 0;
    }
    cout << ans;

    return 0;
}