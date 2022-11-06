#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int M = 998244353;
int n, m, a[N], b[N], l[N], sf[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    if (m > n) {
        cout << 0;
        return 0;
    }
    sf[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        sf[i] = min(sf[i + 1], a[i]);
    l[1] = 0;
    for (int i = 2; i <= m; i++) {
        l[i] = l[i - 1];
        while (l[i] <= n && sf[l[i]] < b[i])
            l[i]++;
        if (l[i] == n + 1 || sf[l[i]] > b[i]) {
            cout << 0;
            return 0;
        }
    }
    if (sf[1] != b[1]) {
        cout << 0;
        return 0;
    }
    l[n + 1] = n + 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        int x = l[i];
        while (x <= n && sf[x] == b[i])
            x++;
        ans *= (x - l[i]);
        ans %= M;
    }
    cout << ans;
    return 0;
}