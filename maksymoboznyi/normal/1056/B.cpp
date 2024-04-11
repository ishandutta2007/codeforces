#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

int kol[N], n, m, k[N], p[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        k[i] = n / m;
    while (n % m != 0)
    {
        k[n % m]++;
        n--;
    }
    for (int i = 0; i < m; i++)
        kol[(i * i) % m] += k[i];
    long long ans = 0;
    for (int i = 0; i < m; i++)
        ans += kol[i] * kol[(m - i)%m];
    cout << ans;
    return 0;
}