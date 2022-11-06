#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 5;

int na, nb, nc, a[N], b[N], c[N];

int f(int x, int y, int z) {
    return (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> na >> nb >> nc;
        for (int i = 1; i <= na; i++)
            cin >> a[i];
        for (int i = 1; i <= nb; i++)
            cin >> b[i];
        for (int i = 1; i <= nc; i++)
            cin >> c[i];
        sort(a + 1, a + na + 1);
        sort(b + 1, b + nb + 1);
        sort(c + 1, c + nc + 1);
        int ans = 5e18;
        /// min x
        for (int i = 1; i <= na; i++) {
            int x = a[i];
            ///max y
            int pos = lower_bound(b + 1, b + nb + 1, x) - b;
            if (pos == nb + 1)
                continue;
            for (int p1 = max(1ll, pos - 5); p1 <= min(nb, pos + 5); p1++) {
                int y = b[p1];
                int pos2 = lower_bound(c + 1, c + nc + 1, (x + y) / 2) - c;
                for (int p2 = max(1ll, pos2 - 5); p2 <= min(nc, pos2 + 5); p2++) {
                    int z = c[p2];
                    ans = min(ans, f(x, y, z));
                }
            }

            ///max z
            pos = lower_bound(c + 1, c + nc + 1, x) - c;
            if (pos == nc + 1)
                continue;
            for (int p1 = max(1ll, pos - 5); p1 <= min(nc, pos + 5); p1++) {
                int y = c[p1];
                int pos2 = lower_bound(b + 1, b + nb + 1, (x + y) / 2) - b;
                for (int p2 = max(1ll, pos2 - 5); p2 <= min(nb, pos2 + 5); p2++) {
                    int z = b[p2];
                    ans = min(ans, f(x, y, z));
                }
            }
        }
        //cout << 1 << endl;
        /// min y
        for (int i = 1; i <= nb; i++) {
            //cout << i << endl;
            int x = b[i];
            ///max x
            int pos = lower_bound(a + 1, a + na + 1, x) - a;
            if (pos == na + 1)
                continue;
            for (int p1 = max(1ll, pos - 5); p1 <= min(na, pos + 5); p1++) {
                //cout << p1 << endl;
                int y = a[p1];
                int pos2 = lower_bound(c + 1, c + nc + 1, (x + y) / 2) - c;
                for (int p2 = max(1ll, pos2 - 5); p2 <= min(nc, pos2 + 5); p2++) {
                    //cout << p2 << endl;
                    int z = c[p2];
                    ans = min(ans, f(x, y, z));
                }
            }

            ///max z
            pos = lower_bound(c + 1, c + nc + 1, x) - c;
            if (pos == nc + 1)
                continue;
            for (int p1 = max(1ll, pos - 5); p1 <= min(nc, pos + 5); p1++) {
                int y = c[p1];
                int pos2 = lower_bound(a + 1, a + na + 1, (x + y) / 2) - a;
                for (int p2 = max(1ll, pos2 - 5); p2 <= min(na, pos2 + 5); p2++) {
                    int z = a[p2];
                    ans = min(ans, f(x, y, z));
                }
            }
        }
        //cout << 2 << endl;
        /// min z
        for (int i = 1; i <= nc; i++) {
            int x = c[i];
            ///max y
            int pos = lower_bound(b + 1, b + nb + 1, x) - b;
            if (pos == nb + 1)
                continue;
            for (int p1 = max(1ll, pos - 5); p1 <= min(nb, pos + 5); p1++) {
                int y = b[p1];
                int pos2 = lower_bound(a + 1, a + na + 1, (x + y) / 2) - a;
                for (int p2 = max(1ll, pos2 - 5); p2 <= min(na, pos2 + 5); p2++) {
                    int z = a[p2];
                    ans = min(ans, f(x, y, z));
                }
            }

            ///max x
            pos = lower_bound(a + 1, a + na + 1, x) - a;
            if (pos == na + 1)
                continue;
            for (int p1 = max(1ll, pos - 5); p1 <= min(na, pos + 5); p1++) {
                int y = a[p1];
                int pos2 = lower_bound(b + 1, b + nb + 1, (x + y) / 2) - b;
                for (int p2 = max(1ll, pos2 - 5); p2 <= min(nb, pos2 + 5); p2++) {
                    int z = b[p2];
                    ans = min(ans, f(x, y, z));
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}