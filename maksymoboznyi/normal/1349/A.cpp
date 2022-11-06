#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5 + 5;

int n, a[N], p[N], s[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], p[i] = __gcd(p[i - 1], a[i]);
    for (int i = n; i > 0; i--)
        s[i] = __gcd(s[i + 1], a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = __gcd(ans, a[i] * __gcd(p[i - 1], s[i + 1]) / __gcd(a[i], __gcd(p[i - 1], s[i + 1])));//, cout << ans << endl;
    cout << ans;
    return 0;
}