#include <bits/stdc++.h>
using namespace std;
 
const int N = 400005;
 
int n, sz, cnt = 1, ans = N, a[N];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> sz;
    sz = min(sz * 8 / n, 30);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    a[0] = a[1]; a[n + 1] = a[n];
    for (int i = 1, pt = 1; i <= n; i++)
    {
        cnt -= (a[i] != a[i - 1]);
        while (pt <= n && (1 << sz) >= cnt)
        {
            ++pt;
            cnt += (a[pt] != a[pt - 1]);
        }
        ans = min(ans, i + n - pt);
    }
    cout << ans;
}