#include <iostream>
#include <cstdio>
using namespace std;

const int N = 300005;

int n, t, a[N];
long long ans = 0, f[N][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f[i][0] = max(0LL, f[i - 1][0] + a[i]));
        ans = max(ans, f[i][1] = max(0LL, max(f[i - 1][0], f[i - 1][1]) + 1LL * a[i] * t));
        ans = max(ans, f[i][2] = max(0LL, max(f[i - 1][1], f[i - 1][2]) + a[i]));
    }
    cout << ans;
    return 0;
}