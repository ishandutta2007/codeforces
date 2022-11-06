#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5 + 5;

map<pair<int, int>, int> q;
int t, n;
int a[N], b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;
        q.clear();
        for (int i = 1; i <= n; i++) {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            a[i] = u - x;
            b[i] = v - y;

            int tt = __gcd(abs(a[i]), abs(b[i]));
            a[i] /= tt;
            b[i] /= tt;

            q[{a[i], b[i]}]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += q[{-a[i], -b[i]}];
        cout << ans  / 2 << "\n";
    }
    return 0;
}