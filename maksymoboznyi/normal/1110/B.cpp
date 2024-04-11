#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], d[N], n, m, k;

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        d[i] = a[i + 1] - a[i];
    sort(d + 1, d + n);
    int cur = 1, dd = n, ans = n;
    while (dd > k) {
        ans += d[cur] - 1;
        dd--;
        cur++;
    }
    cout << ans;
    return 0;
}