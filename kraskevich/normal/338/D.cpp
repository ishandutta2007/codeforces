#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return g;
}

long long gcd(long long a, long long b)
{
    if (a < b)
        swap(a, b);
    return b ? gcd(b, a % b) : a;
}

long long mulmod(long long a, long long b, long long mod)
{
    a %= mod;
    b %= mod;
    if (!a || !b)
        return 0;
    if (b % 2)
        return (a + mulmod(a, b - 1, mod)) % mod;
    else
        return 2 * mulmod(a, b / 2, mod) % mod;
}

long long crt(long long r1, long long m1, long long r2, long long m2)
{
    if (r1 > r2)
        return crt(r2, m2, r1, m1);
    long long x, y;
    long long g = gcd(m1, m2, x, y);
    long long c = r2 - r1;
    long long k = m2 / g;
    long long l = k * m1;
    if (c % g)
        return -1;
    x = (x % k + k) % k;
    x = mulmod(x, c / g, l);
    x = mulmod(x, m1, l);
    x += r1;
    return x % l;
}

const int N = 10000 + 10;

long long n, m, k;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    long long row = a[0], col = 0;
    for (int i = 1; i < k; i++)
    {
        long long g = gcd(row, a[i]);
        if (1.0 * row / g * a[i] > 1e13)
        {
            cout << "NO";
            return 0;
        }
        col = crt(col, row, (a[i] - i % a[i]) % a[i], a[i]);
        if (col < 0)
        {
            cout << "NO";
            return 0;
        }
        row = row / g * a[i];
    }
    if (col == 0)
        col += row;
    for (int i = 0; i < k; i++)
        if (gcd(col + i, row) != a[i])
        {
            cout << "NO";
            return 0;
        }
    if (col + k - 1 <= m && row <= n)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}