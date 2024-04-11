#include <bits/stdc++.h>
using namespace std;

int n, d, e;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d >> e;
    e *= 5;
    int ans = n;
    for (int i = 0; i <= n; i += e)
        ans = min(ans, (n - i) % d);
    cout << ans;
}