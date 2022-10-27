
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(2 * n);
    for(int i = 0; i < n * 2; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = (a[n - 1] - a[0]) * (a[n * 2 - 1] - a[n]);
    for(int i = 1; i < n; i++)
    {
        ans = min(ans, (a[n * 2 - 1] - a[0]) * (a[n + i -1] - a[i]));
    }
    cout << ans;
    return 0;
}