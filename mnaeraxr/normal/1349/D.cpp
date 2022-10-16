#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define endl '\n'

using namespace std;

const int mod = 998244353;

int modpow(int a, int n)
{
    int b = 1;

    while (n)
    {
        if (n & 1)
        {
            b = 1LL * a * b % mod;
        }
        n >>= 1;
        a = 1LL * a * a % mod;
    }

    return b;
}

int inverse(int a)
{
    int x = modpow(a, mod - 2);
    assert(1LL * x * a % mod == 1);
    return x;
}

void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

void sub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}

int mul(vector<int> a)
{
    int r = 1;
    for (auto x : a)
    {
        r = 1LL * r * x % mod;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int m = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        m += a[i];
    }

    vector<int> pot(m + 1, 0);

    for (int t = 0; t < m; ++t)
    {
        int x = t ? pot[t - 1] : 0;
        int y = pot[t];

        int r = 0;

        sub(r, mul({m, n, y}));
        add(r, mul({m, n}));
        sub(r, m);
        add(r, mul({n, n, t, x}));
        sub(r, mul({n, n, t, y}));
        sub(r, mul({n, t, x}));
        add(r, mul({2, n, t, y}));

        int den = 1LL * n * (t - m + mod) % mod;
        pot[t + 1] = 1LL * r * inverse(den) % mod;
    }

    int cur_pot = 0;

    for (int i = 0; i < n; ++i)
    {
        add(cur_pot, pot[a[i]]);
    }

    sub(cur_pot, pot[m]);
    cout << cur_pot << endl;

    return 0;
}