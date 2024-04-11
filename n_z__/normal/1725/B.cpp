#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, d, p[1000005];
signed main () {
    ios :: sync_with_stdio (0);
    cin.tie (nullptr);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) 
        cin >> p[i];
    sort (p+1, p+n+1);
    int l = 0, ans = 0;
    for (int i = n; i >= 1; i--) {
        int a = (d+p[i]-1)/p[i] - (d%p[i] > 0);
        if (l + a < i) ans ++, l += a;
        else break;
    }
    cout << ans << endl;
    return 0;
}