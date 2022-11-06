#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

using namespace std;

const int N = 2e5 + 5;
const int M = 998244353;

int n, k, f[N], bf[N];

int gp(int a, int b) {
    int res = 1;
    while (b > 0)
        if (b % 2 == 0)
            a *= a, b /= 2, a %= M;
        else
            res *= a, res %= M, b--;
    return res;
}

int c(int n, int k) {
    return f[n] * bf[k] % M * bf[n - k] % M;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if (k >= n) {
        cout << 0;
        return 0;
    }
    int ans = 2;
    f[0] = 1;
    bf[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % M, bf[i] = gp(f[i], M - 2);
    int F = 0;
    for (int i = n - k; i >= 1; i--) {
        int val = c(n - k, i) * gp(i, n) % M;
        if ((i - (n - k)) % 2 == 0)
            F += val;
        else
            F -= val;
        F = (F + M) % M;
    }

    if (k == 0)
        ans = 1;

    cout << ans * F % M * c(n, n - k) % M << endl;
    return 0;
}