#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e3 + 1;
const int M = 998244353;

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
        if ((n / 2) % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int sum = 0;
        for (int i = 1; i <= n / 2; i++)
            cout << i * 2 << ' ', sum += (i * 2);
        for (int i = 1; i < n / 2; i++)
            cout << i * 2 - 1 << ' ', sum -= (i * 2 - 1);
        cout << sum << "\n";
    }
    return 0;
}