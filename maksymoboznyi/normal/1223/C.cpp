#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;

int p[N], x, a, y, b, k, q[N];

bool check(int m) {
    for (int i = 1; i <= m; i++)
        q[i] = 0;
    if (x < y)
        swap(x, y), swap(a, b);
    int cur = 1;
    int c = a * b / __gcd(a, b);
    for (int i = c; i <= m; i += c)
        q[i] = p[cur], cur++;
    for (int i = a; i <= m; i += a)
        if (q[i] == 0)
            q[i] = p[cur], cur++;
    for (int i = b; i <= m; i += b)
        if (q[i] == 0)
            q[i] = p[cur], cur++;
    for (int i = 1; i <= m; i++)
        if (q[i] == 0)
            q[i] = p[cur], cur++;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (i % a == 0)
            ans += q[i] / 100 * x;
        if (i % b == 0)
            ans += q[i] / 100 * y;
    }
    return ans >= k;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        sort(p + 1, p + n + 1);
        reverse(p + 1, p + n + 1);
        cin >> x >> a >> y >> b >> k;
        int l = 0, r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (check(m))
                r = m;
            else
                l = m;
        }
        if (check(r))
            cout << r << "\n";
        else
            cout << -1 << "\n";
        //cout << check(6) << ' ' << r << endl;
    }
    return 0;
}