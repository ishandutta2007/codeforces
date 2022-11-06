#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 3e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        int a = 1, ans = n - 1;
        for (int d = 2; d * d <= n; d++) {
            int x1 = d, x2 = n - d;
            if (x1 * x2 / __gcd(x1, x2) < ans)
                ans = x1 * x2 / __gcd(x1, x2), a = x1;
            x1 = n / d, x2 = n - x1;
            if (x1 * x2 / __gcd(x1, x2) < ans)
                ans = x1 * x2 / __gcd(x1, x2), a = x1;

        }
        cout << a << ' ' << n - a << "\n";
    }
    return 0;
}