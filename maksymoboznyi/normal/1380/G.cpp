#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 5;
const int M = 998244353;

int n, a[N], pref[N], bn;

int gp(int a, int b) {
    int res = 1;
    while (b)
        if (b % 2)
            b--, res *= a, res %= M;
        else
            b /= 2, a *= a, a %= M;
    return res;
}

signed main()
{
    cin >> n;
    bn = gp(n, M - 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];
    for (int k = 1; k <= n; k++) {
        int cur = n - k;
        int ans = 0;
        for (int j = 1; j <= (n - k) / k; j++) {
            int x = (pref[cur] - pref[cur - k]) * j % M;
            ans += x;
            ans %= M;
            cur -= k;
        }
        ans += pref[cur] * ((n - k) / k + 1);
        ans %= M;
        cout << ans * bn % M << ' ';
    }
    return 0;
}