#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], is[3], n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        is[0] = is[1] = is[2] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], is[a[i] + 1]++;
        bool can = 1;
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = n; i > 0; i--) {
            is[a[i] + 1]--;
            if (a[i] == b[i])
                continue;
            if (a[i] < b[i] && !is[2])
                can = 0;
            if (a[i] > b[i] && !is[0])
                can = 0;
        }
        cout << (can ? "YES\n" : "NO\n");
    }
    return 0;
}