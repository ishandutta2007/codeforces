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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        y = min(y, x + x);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int kol = 0;
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                if (c == '.')
                    kol++;
                else
                    ans += (kol / 2) * y + (kol % 2) * x, kol = 0;
            }

            ans += (kol / 2) * y + (kol % 2) * x, kol = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}