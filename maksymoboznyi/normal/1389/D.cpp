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
        int n, k, l1, r1, l2, r2;
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2 || (l1 == l2 && r1 > r2))
            swap(l1, l2), swap(r1, r2);
        if (l2 <= r1 && r2 >= r1) {
            int kol = r2 - l1 - (r1 - l2);
            k -= (r1 - l2) * n;
            if (k <= 0)
                cout << "0\n";
            else if (kol * n >= k)
                cout << k << "\n";
            else
                cout << kol * n + (k - kol * n) * 2 << "\n";
        } else if (l2 <= r1 && r2 <= r1) {
            k -= (r2 - l2) * n;
            int kol = r1 - l1 - (r2 - l2);
            if (k <= 0)
                cout << "0\n";
            else if (kol * n >= k)
                cout << k << "\n";
            else
                cout << kol * n + (k - kol * n) * 2 << "\n";
        } else {
            int ans = 1e18;
            for (int kol = 1; kol <= n; kol++) {
                int t = (l2 - r1) * kol;
                if ((r2 - l1) * kol >= k)
                    ans = min(ans, t + k);
                else {
                    int add = (r2 - l1) * kol;
                    //k -= add;
                    ans = min(ans, t + add + 2 * (k - add));
                }
               // cout << kol << ' ' << t << ' ' << ans << ' ' << k << endl;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}