#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        bool w0 = 0, w1 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0)
                w0 = 1;
            else
                w1 = 1;
            sum += a[i];
        }
        if (sum % 2 == 1) {
            cout << "YES\n";
            continue;
        }
        if (w0 && w1) {
            cout << "YES\n";
        } else
            cout << "NO\n";
    }
    return 0;
}