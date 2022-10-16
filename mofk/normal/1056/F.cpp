#include <bits/stdc++.h>

using namespace std;

const double r = 10.0 / 9;
int n;
double c, x;
pair <int, int> a[105];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(3);
    cout << fixed;
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> c >> x;
        int s = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second, s += a[i].second;
        sort(a + 1, a + n + 1);
        int ans = 0;
        vector <vector <double> > g(n + 1, vector <double> (s + 1, 1e16));
        g[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int k = i - 1; k >= 0; --k) for (int j = 0; j + a[i].second <= s; ++j)
                g[k+1][j + a[i].second] = min(g[k+1][j + a[i].second], r * (g[k][j] + a[i].first));
        }
        for (int k = 1; k <= n; ++k) {
            x -= 10;
            if (x < 0) break;
            double tt = max(0.0, (x * c - 1) / 2 / c);
            double tl = (x - tt) * (1 + c * tt);
            for (int j = s - 1; j >= 0; --j) g[k][j] = min(g[k][j], g[k][j+1]);
            //cout << tl << endl; for (auto m: g[k]) cout << m << ' '; cout << endl;
            ans = max(ans, upper_bound(g[k].begin(), g[k].end(), tl) - g[k].begin() - 1);
        }
        cout << ans << endl;
    }
    return 0;
}