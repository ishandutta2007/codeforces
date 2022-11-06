#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 5e5 + 5;
const long long M = 1e9 + 7;
const double eps = 1e-8;

int n, k, a[N], cur[N], num[N], used[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k > n)
        k = n;
    for (int i = 1; i <= k; i++)
        cur[i] = i, num[i] = 0;
    int c = k + 1, ans = 0, ok = 0;
    while (1) {
        bool r = 0;
        for (int i = 1; i <= k; i++)
        if (cur[i] != -1)
        {
            r = 1;
            num[i]++;
            if (!used[cur[i]] && trunc(100.0 * ok * 1.0 / n + 0.5) == num[i])
                ans++, used[cur[i]] = 1;

        }
        for (int i = 1; i <= k; i++)
        if (num[i] == a[cur[i]]) {
            ok++;
            if (c != n + 1)
                cur[i] = c, num[i] = 0, c++;
            else
                cur[i] = -1;
        }
        if (!r)
            break;
    }
    cout << ans;
    return 0;
}