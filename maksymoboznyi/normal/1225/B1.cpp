#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 1e6 + 6;

int a[N], kol[N], del, k, d, n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int u = 0; u < t; u++) {
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= 1000000; i++)
        kol[i] = 0;
    del = 0;
    int ans = n;
    for (int i = 1; i <= d; i++) {
        kol[a[i]]++;
        if (kol[a[i]] == 1)
            del++;
    }
    ans = del;
    for (int i = d + 1; i <= n; i++) {
        kol[a[i - d]]--;
        if (kol[a[i - d]] == 0)
            del--;
        kol[a[i]]++;
        if (kol[a[i]] == 1)
            del++;
        ans = min(ans, del);
    }
    cout << ans << "\n";
    }
    return 0;
}