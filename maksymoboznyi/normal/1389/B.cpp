#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e5 + 5;

int n, k, z, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> z;
        int sum = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for (int j = 0; j <= z; j++) {
            int s = k - j;
            if (s < j)
                break;
            int sum = 0;
            int mx = 0;
            for (int i = 1; i <= s - j + 1; i++)
                sum += a[i], mx = max(a[i] + a[i + 1], mx);
            ans = max(ans, sum + mx * j);
        }
        cout << ans << "\n";

    }
    return 0;
}