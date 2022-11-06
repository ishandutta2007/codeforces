#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 1;
const int M = 998244353;

int n, a[N], p[2 * N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i <= 2 * k; i++)
            p[i] = 0;
        for (int i = 1; i <= n / 2; i++) {
            int sum = a[i] + a[n - i + 1];
            p[0] += 2;
            p[sum - max(a[i], a[n - i + 1]) + 1] += -1;
            p[sum] += -1;
            p[sum + 1] += 1;
            p[sum + k - min(a[i], a[n - i + 1]) + 1] += 1;
        }
        int cur = p[0], mn = 1e9;
        for (int i = 2; i <= 2 * k; i++)
            cur += p[i], mn = min(mn, cur);
        cout << mn << "\n";
    }
    return 0;
}