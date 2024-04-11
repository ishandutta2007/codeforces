#include <bits/stdc++.h>

using namespace std;

const int MAXN = 600000;

int CNT = 0;

const double pi = 3.141592653589793;
const double eps = 1e-9;

typedef long long ll;

ll a[101][101];

void solve() {
    int n, m, x, y;
    ll k;
    cin >> n >> m >> k >> x >> y;
    --x;
    --y;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            a[i][j] = 0;
    for(int i = 0; i < m; ++i)
        a[0][i] = a[n - 1][i] = k/(n * m + max(0, (n - 2)) * m);
    for(int i = 1; i < n - 1; ++i)
        for(int j = 0; j < m; ++j)
            a[i][j] = a[0][0] * 2;
    k %= (n * m + max(0, (n - 2)) * m);
    if(k >= n * m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ++a[i][j];
        k -= n * m;
        for(int i = n - 2; i >= 1; --i)
            for(int j = 0; j < m; ++j, --k)
                a[i][j] += (k > 0);
    } else {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j, --k)
                a[i][j] += (k > 0);
    }
    ll mx = 0, mn = 2e18;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            mx = max(mx, a[i][j]), mn = min(mn, a[i][j]);
    cout << mx << ' ' << mn << ' ' << a[x][y];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/home/step/CLionProjects/codeforces/input", "r", stdin);
    freopen("/home/step/CLionProjects/codeforces/output", "w", stdout);
#endif
    solve();
    return 0;
}