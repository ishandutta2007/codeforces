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
        int m, d, w;
        cin >> m >> d >> w;
        if (d == 1) {
            cout << "0\n";
            continue;
        }
        int t = min(m, d);
        int x = w / __gcd(w, d - 1);
        int a = t / x, b = t % x;
        int ans = (x - b) * a * (a - 1) / 2 + b * a * (a + 1) / 2;
        cout << ans << "\n";
    }
    return 0;
}