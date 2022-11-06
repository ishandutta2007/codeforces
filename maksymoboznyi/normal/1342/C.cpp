#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

using namespace std;

const int N = 1e5 + 5;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int o;
    cin >> o;
    while (o--) {
        int a, b, q;
        cin >> a >> b >> q;
        if (a > b)
            swap(a, b);
        for (int i = 1; i <= q; i++) {
            long long l, r;
            cin >> l >> r;
            int ans = 0;
            for (int ost = 0; ost < min(b, r + 1); ost++) {
                int g = a * b / __gcd(a, b);
                ans += (r - ost) / g + 1;
                if (l - ost - 1 >= 0)
                    ans -= ((l - ost - 1) / g + 1);
                //cout << ost << ' ' << ans << endl;
            }
            cout << r - l + 1 - ans << ' ';
        }
        cout << "\n";
    }
    return 0;
}