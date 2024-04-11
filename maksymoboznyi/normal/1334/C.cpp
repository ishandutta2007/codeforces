#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, a[N], b[N], hp[N], r[N], used[N];

int nxt(int pos) {
    return (pos + 1) % n;
}

int pr(int pos) {
    return (pos + n - 1) % n;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            used[i] = 0, cin >> a[i] >> b[i];
        int ans = 0, mpos = -1;
        for (int i = 0; i < n; i++)
            if (b[i] < a[nxt(i)]) {
                used[nxt(i)] = 1;
                ans += a[nxt(i)] - b[i];
            }
        int sum = 1e18;
        for (int i = 0; i < n; i++)
            if (used[i])
                sum = min(sum, ans + b[pr(i)]);
            else
                sum = min(sum, ans + a[i]);
        cout << sum << "\n";
    }
    return 0;
}