#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;

const int N = 2e5 + 5;

int kol[30], a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j <= 20; j++) {
            if (x % 2)
                kol[j]++;
            x /= 2;
        }
    }
    for (int j = 20; j >= 0; j--)
        for (int i = 1; i <= kol[j]; i++)
            a[i] += (1 << j);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] * a[i];
    cout << ans;
    return 0;
}