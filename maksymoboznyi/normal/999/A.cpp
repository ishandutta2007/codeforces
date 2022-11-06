#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define x first
#define y second

using namespace std;
const int N = 4e5+5;
const long long inf = 2e18;

int n, k, a[N], l = 1, r;

signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    r = n;
    while (l <= n && a[l] <= k)
        l++;
    while (r >= l && a[r] <= k)
        r--;
    cout << l-1 + n - r;
    return 0;
}