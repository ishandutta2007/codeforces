#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 5e5 + 5;
const long long inf = 2e18;

int n, b[N], a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    n /= 2;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] = (i == 0 ? 0 : a[i - 1]);
        a[n + n - i - 1] = b[i] - a[i];
        if (i == 0)
            continue;
        int x = (a[n + n - i] - a[n + n - i - 1]);
        if (x >= 0)
            continue;
        else
        {
            x = -x;
            a[i] += x;
            a[n + n - i - 1] -= x;
        }
    }
    for (int i = 0; i < n + n; i++)
        cout << a[i] << ' ';
    return 0;
}