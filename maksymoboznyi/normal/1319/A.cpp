#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n, a[N], b[N];
int good[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= n; j++)
        cin >> b[j];
    int k1 = 0, k2 = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] && !b[i])
            k1++;
        else
            if (!a[i] && b[i])
                k2++;
    if (k1 == 0) {
        cout << -1;
        return 0;
    }
    if (k2 == 0) {
        cout << 1;
        return 0;
    }
    k2++;
    int ans = k2 / k1;
    if (k2 % k1 != 0)
        ans++;
    cout << ans;


    return 0;
}