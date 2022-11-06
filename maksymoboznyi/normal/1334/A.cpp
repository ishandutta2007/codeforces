#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int p[N], c[N], n;

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
        cin >> p[i] >> c[i];
    bool can = 1;
    for (int i = 0; i < n; i++) {
        if (c[i + 1] - c[i] > p[i + 1] - p[i] || p[i + 1] < p[i] || c[i + 1] < c[i]) {
            can = 0;
            break;
        }
    }
    cout << (can ? "YES\n" : "NO\n");
    }
    return 0;
}