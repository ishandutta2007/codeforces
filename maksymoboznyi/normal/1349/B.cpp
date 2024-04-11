#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5 + 5;

int n, k, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> p;
        int was = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == k)
                was = 1;
            if (a[i] >= k)
                p.pb(i);
        }
        if (!was) {
            cout << "no\n";
            continue;
        }
        if (n == 1) {
            cout << "yes\n";
            continue;
        }
        bool can = 0;
        for (int i = 0; i + 1 < p.size(); i++)
            if (p[i + 1] - p[i] <= 2) {
                can = 1;
                break;
            }
        cout << (can ? "yes\n" : "no\n");
    }
    return 0;
}