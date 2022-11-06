#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], ans = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        ans = 0;
        int cur = 1, cmx = 0, cl = 0;
        while (cur != n + 1) {
            cl = 1;
            cmx = a[cur];
            cur++;
            while (cur != n + 1 && cl < cmx)
                cmx = max(cmx, a[cur]), cl++, cur++;
            if (cl >= cmx) {
                ans++;
            } else
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}