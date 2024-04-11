
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, p, k;
        cin >> n >> p >> k;
        vector <int> a(n);
        string s;
        cin >> s;
        for(int i = 0; i < n; i++)
        {
            a[i] = s[i] - '0';
        }
        int x, y;
        cin >> x >> y;
        vector <int> dp(n);
        for(int i = n - 1; i >= 0; i--)
        {
            dp[i] = 1 - a[i];
            if(i + k < n)
            {
                dp[i] += dp[i + k];
            }
        }
        int ans = 1e18;
        p--;
        for(int i = p; i < n; i++)
        {
            ans = min(ans, (i - p) * y + x * dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}