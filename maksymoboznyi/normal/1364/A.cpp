#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>
#define int long long
using namespace std;

const int N = 3e5 + 5;

int n, a[N];

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> n >> x;
        int s = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], s += a[i];
        int ans = -1;
        if (s % x != 0) {
            cout << n << "\n";
            continue;
        }
        for (int i = 1; i < n; i++) {
            s -= a[i];
            if (s % x != 0)
                ans = max(ans, n - i);
        }
        s = 0;
        for (int i = 1; i <= n; i++)
            s += a[i];
        for (int i = n; i > 1; i--) {
            s -= a[i];
            if (s % x != 0)
                ans = max(ans, i - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}