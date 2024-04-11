#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

const int MOD = (int)998244353;

int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        int q = A / M;
        int t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int zero = 0;
        F0R(i, n)
        {
            cin >> a[i];
            if (!a[i])
                zero++;
        }
        int step = 0;
        F0R(i, zero)
        {
            if (a[i])
                step++;
        }
        ll ans = 0;
        while (step)
        {
            ll tmp = 1;
            tmp = tmp * modInverse(step, MOD) % MOD;
            tmp = tmp * modInverse(step, MOD) % MOD;
            ans = (ans + tmp) % MOD;
            step--;
        }
        ans = ans * (((ll)n * (n - 1) / 2) % MOD) % MOD;
        cout << ans << '\n';
    }
}