#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, a[N], pref[N], r[N], mn[N];
map<int, int> q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pref[i] = a[i] + pref[i - 1], r[i] = n + 1;
    for (int i = 1; i <= n; i++) {
        q[pref[i - 1]] = i;
        r[q[pref[i]]] = i;
        //cout << i << ' ' << q[pref[i]] << endl;
    }
    mn[n + 1] = n + 1;
    for (int i = n; i > 0; i--)
        mn[i] = min(mn[i + 1], r[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += mn[i] - i;
    }
    cout << ans;
    return 0;
}