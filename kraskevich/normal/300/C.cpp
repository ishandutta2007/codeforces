#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>


const long long mod = 1000 * 1000 * 1000 + 7;
const int N = 1000 * 1000 + 10;
long long f[N];
long long r[N];

bool good(long long x, long long a, long long b)
{
    while (x)
    {
        if (x % 10 != a && x % 10 != b)
            return false;
        x /= 10;
    }
    return true;
}

long long binPow(long long base, long long n)
{
    long long res = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            res *= base;
            res %= mod;
        }
        base *= base;
        base %= mod;
        n /= 2;
    }
    return res;
}

long long cnk(int n, int k)
{
    long long res = f[n];
    res *= r[k];
    res %= mod;
    res *= r[n - k];
    res %= mod;
    return res;
}

void solve()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % mod;
    for (int i = 0; i < N; ++i)
        r[i] = binPow(f[i], mod - 2);

    long long n, a, b;
    cin >> a >> b >> n;

    long long res = 0;
    for (int k = 0; k <= n; ++k)
    {
        long long sum = k * a + (n - k) * b;
        if (!good(sum, a, b))
            continue;
        res += cnk(n, k);
        res %= mod;
    }

    cout << res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}