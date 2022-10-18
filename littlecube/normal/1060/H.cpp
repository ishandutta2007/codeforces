/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int d, mod, debug[5005];

void add(int a, int b, int c)
{
    cout << "+ " << a << ' ' << b << ' ' << c << '\n';
}

void power(int a, int b)
{
    cout << "^ " << a << ' ' << b << '\n';
}

int inv(ll b)
{
    int t = mod - 2;
    ll a = 1;
    b %= mod;
    while (t)
    {
        if (t & 1)
            a = a * b % mod;
        b = b * b % mod;
        t >>= 1;
    }
    return a;
}

void mul(int pos1, ll scale)
{
    // using 25
    scale = (scale - 1) * inv(2) % mod + mod;
    add(pos1, pos1, 25);
    for (int i = 0; scale; i++)
    {
        if (scale & 1)
            add(25, pos1, pos1);
        add(25, 25, 25);
        scale >>= 1;
    }
}

signed main()
{
    fast;
    cin >> d >> mod;
    for (int i = 1; i <= 5000; i++)
        debug[i] = 1;
    // 1 ~ d: regular, 30 ~ 30 + 1024: subset, 20+, 21-, 22 ans
    int off = 30;
    mul(off, mod);
    for (int mask = 1; mask < (1 << d); mask++)
        for (int i = 0; i < d; i++)
            if (mask & (1 << i))
            {
                add(off + mask - (1 << i), i + 1, off + mask);
                break;
            }
    add(30, 30, 20);
    add(30, 30, 21);
    for (int mask = 0; mask < (1 << d); mask++)
    {
        power(off + mask, off + mask);
        if ((d ^ __builtin_popcount(mask)) & 1)
            add(off + mask, 21, 21);
        else
            add(off + mask, 20, 20);
    }
    mul(21, mod - 1);
    add(20, 21, 22);
    int fac = 1;
    for (int i = 1; i <= d; i++)
        fac = fac * i % mod;
    mul(22, inv(fac));
    cout << "f 22\n";
}