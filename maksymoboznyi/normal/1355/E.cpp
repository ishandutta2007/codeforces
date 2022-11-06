#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], x, y, z, pref[N];

int f(int h) {
    int pos = upper_bound(a + 1, a + n + 1, h) - a - 1;
    int p1 = (pref[n] - pref[pos]) -  (n - pos) * h;
    int p2 = pos * h - pref[pos];
    //cout << h << endl;
    //cout << p1 << ' ' << p2 << ' ' << pos << ' ' << pref[n] << ' ' << pref[pos] << ' ' << (n - pos) * h << endl;
    //cout << endl << p1 << ' ' << p2 << endl;
    if (x + y <= z)
        return y * p1 + x * p2;
    int mn = min(p1, p2);
    return z * mn + y * (p1 - mn) + x * (p2 - mn);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y >> z;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];
    int l = 0, r = 1e9;
    while (r - l + 1 >= 100000) {
        int y1 = (2 * l + r) / 3;
        int y2 = (l + 2 * r) / 3;
        //cout << y1 << ' ' << y2 << ' ' << f(y1) << ' ' << f(y2) << endl;
        if (f(y1) > f(y2))
            l = y1;
        else
            r = y2;
    }
    int ans = 1e18;
    for (int i = l; i <= r; i++)
        ans = min(ans, f(i));//, cout << i << ' ' << f(i) << endl;

    cout << ans;
    return 0;
}