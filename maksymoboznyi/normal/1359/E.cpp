#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 5e5 + 5;
const int M = 998244353;

int gp(int a, int b) {
    int res = 1;
    while (b > 0)
        if (b & 1)
            b--, res *= a, res %= M;
        else
            b /= 2, a *= a, a %= M;
    return res;
}

int f[N], bf[N];

int gc(int n, int k) {
    return f[n] * bf[k] % M * bf[n - k] % M;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    f[0] = 1;
    bf[0] = 1;
    for (int i = 1; i <= 5e5; i++)
        f[i] = f[i - 1] * i % M, bf[i] = gp(f[i], M - 2);
    int ans = 0;
    for (int g = 1; g <= n; g++) {
        int kol = n / g - 1;
        if (kol < k - 1)
            continue;
        ans += gc(kol, k - 1);
        ans %= M;
    }
    cout << ans;
    return 0;
}