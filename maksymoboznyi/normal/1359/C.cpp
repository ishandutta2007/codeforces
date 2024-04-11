#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        double h, c, x, t;
        cin >> h >> c >> t;
        double bt = (h + c) / 2;
        int ans = 2;
        x = 1.0;
        if (h + c != 2 * t)
            x = max(x, (c - t) / (h + c - 2 * t));
        x = trunc(x);
        for (int i = max(1.0, x - 20); i <= max(0.0, x + 20); i++) {
            double tt = (h * i + c * (i - 1)) / (2 * i - 1);
            if (abs(tt - t) - abs(bt - t) < -1e-12 || (i + i - 1 < ans && abs(abs(tt - t) - abs(bt - t)) < 1e-12))
                ans = i + i - 1, bt = tt;
        }
        cout << ans << "\n";

    }
    return 0;
}