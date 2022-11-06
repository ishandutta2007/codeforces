#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int d;
    cin >> n >> d;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y <= n && abs(x - y) <= d && x + y >= d && x + y <= 2*n-d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}