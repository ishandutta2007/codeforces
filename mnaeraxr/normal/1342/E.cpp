#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

const int mod = 998244353;

const int maxn = 200010;

int fak[maxn], inv[maxn];

int modpow(int a, int n)
{
    int b = 1;
    while (n)
    {
        if (n & 1)
            b = 1LL * a * b % mod;
        n >>= 1;
        a = 1LL * a * a % mod;
    }
    return b;
}

int inverse(int a)
{
    return modpow(a, mod - 2);
}

int comb(int n, int k)
{
    return 1LL * fak[n] * inv[k] % mod * inv[n - k] % mod;
}

int f(int n, int k)
{
    if (k >= n)
    {
        return 0;
    }

    if (k == 0)
    {
        return fak[n];
    }

    int ans = 0;

    k = n - k;

    for (int i = 0; i <= k; ++i)
    {
        int u = 1LL * comb(k, i) * modpow(k - i, n) % mod;
        if (i & 1)
            u = (mod - u) % mod;

        ans += u;
        if (ans >= mod)
            ans -= mod;
    }

    // cout << ans << endl;

    ans = 1LL * ans * inv[k] % mod * fak[n] % mod * inv[n - k] % mod;

    if (k)
        ans = 1LL * ans * 2 % mod;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fak[0] = inv[0] = 1;

    for (int i = 1; i < maxn; ++i)
    {
        fak[i] = 1LL * i * fak[i - 1] % mod;
        inv[i] = inverse(fak[i]);
    }

    int n, k;
    cin >> n >> k;

    cout << f(n, k) << endl;

    return 0;
}