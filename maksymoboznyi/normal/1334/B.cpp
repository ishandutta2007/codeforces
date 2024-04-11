#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, x, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        int ans = 0, sum = 0;
        for (int i = n; i >= 1; i--) {
            sum += a[i];
            if (sum >= x * (n - i + 1))
                ans = n - i + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}