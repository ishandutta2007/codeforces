#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005, M = 200005;

int n, m, k, ta, tb, a[N], b[M];
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    if (k >= n)
        return cout << -1, 0;
    for (int i = 0, pt = 1; i <= min(n - 1, k); i++)
    {
        for (; pt <= m && a[i + 1] + ta > b[pt]; pt++);
        if (pt + k - i <= m)
            ans = max(ans, b[pt + k - i]);
        else
            return cout << -1, 0;
    }
    cout << ans + tb;
}