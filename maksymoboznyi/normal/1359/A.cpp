#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (m <= n / k) {
            cout << m << "\n";
            continue;
        }
        if (k == n) {
            cout << "0\n";
            continue;
        }
        m -= n / k;
        int x = (m - 1) / (k - 1) + 1;
        cout << n / k - x << "\n";
    }
    return 0;
}