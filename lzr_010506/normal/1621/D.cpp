#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define mp make_pair
#define X first
#define Y second
#define pii pair<int, int>
#define ll long long
using namespace std;
ll a[510][510];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) 
    {
        int n;
        cin >> n;
        rep0(i, 2 * n)
            rep0(j, 2 * n)
                cin >> a[i][j];
        ll ans = 0;
        rep0(i, n)
            rep0(j, n)
            {
                ans += a[i][j];
                a[i][j] = 0;
            }
        rep(i, n, 2 * n - 1)
            rep(j, n, 2 * n - 1)
            {
                ans += a[i][j];
                a[i][j] = 0;
            }

        ll mi = 1e18;
        mi = min(mi, a[n][0]);
        mi = min(mi, a[2 * n - 1][0]);
        mi = min(mi, a[n][n - 1]);
        mi = min(mi, a[2 * n - 1][n - 1]);

        mi = min(mi, a[0][n]);
        mi = min(mi, a[0][2 * n - 1]);
        mi = min(mi, a[n - 1][n]);
        mi = min(mi, a[n - 1][2 * n - 1]);
        cout << ans + mi << "\n";
    }
}