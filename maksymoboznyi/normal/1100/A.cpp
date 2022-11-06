#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 1e9 + 7;

int n, k, a[N], ans = -1, kol = -1;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int b = 1; b <= n; b++) {
        int k1 = 0, k2 = 0;
        for (int i = 1; i <= n; i++)
            if (abs(b - i) % k != 0)
                if (a[i] == 1)
                    k1++;
                else
                    k2++;
        kol = max(abs(k1 - k2), kol);
    }
    cout << kol;
    return 0;
}