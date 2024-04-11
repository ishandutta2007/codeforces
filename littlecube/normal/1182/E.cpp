//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct Matrix3
{
    ll val[3][3] = {{0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}};
    Matrix3 operator*(Matrix3 m)
    {
        Matrix3 r;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    r.val[i][j] = (r.val[i][j] + this->val[i][k] * m.val[k][j]) % (MOD - 1);
        return r;
    }
};

struct Matrix5
{
    ll val[5][5] = {{0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}};
    Matrix5 operator*(Matrix5 m)
    {
        Matrix5 r;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                for (int k = 0; k < 5; k++)
                    r.val[i][j] = (r.val[i][j] + this->val[i][k] * m.val[k][j]) % (MOD - 1);
        return r;
    }
};

Matrix3 A = {{{1, 1, 1},
              {1, 0, 0},
              {0, 1, 0}}};
Matrix5 B = {{{1, 1, 1, 1, 1},
              {1, 0, 0, 0, 0},
              {0, 1, 0, 0, 0},
              {0, 0, 0, 1, 1},
              {0, 0, 0, 0, 1}}};
Matrix3 I3 = {{{1, 0, 0},
               {0, 1, 0},
               {0, 0, 1}}};
Matrix5 I5 = {{{1, 0, 0, 0, 0},
               {0, 1, 0, 0, 0},
               {0, 0, 1, 0, 0},
               {0, 0, 0, 1, 0},
               {0, 0, 0, 0, 1}}};

ll f1, f2, f3, c, n, pf1, pf2, pf3, pc;

Matrix3 fast_pow3(ll n)
{
    if (n == 0)
        return I3;
    if (n == 1)
        return A;
    if (n % 2)
        return A * fast_pow3(n - 1);

    Matrix3 HA = fast_pow3(n / 2);
    return HA * HA;
}

Matrix5 fast_pow5(ll n)
{
    if (n == 0)
        return I5;
    if (n == 1)
        return B;
    if (n % 2)
        return B * fast_pow5(n - 1);

    Matrix5 HB = fast_pow5(n / 2);
    return HB * HB;
}

ll lfast_pow(ll base, ll n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return base;

    if (n % 2)
        return (base * lfast_pow(base, n - 1) % (MOD));

    ll half = lfast_pow(base, n / 2);
    return (half * half) % (MOD);
}

int main()
{
    cin >> n >> f1 >> f2 >> f3 >> c;
    Matrix3 M = fast_pow3(n - 3);
    Matrix5 N = fast_pow5(n - 3);
    pf1 = (M.val[0][2]);
    pf2 = (M.val[0][1]);
    pf3 = (M.val[0][0]);
    pc = (2 * N.val[0][4]) % (MOD - 1);
    cout << (((lfast_pow(f1, pf1) * lfast_pow(f2, pf2)) % (MOD)) * (lfast_pow(f3, pf3) * lfast_pow(c, pc) % (MOD))) % (MOD);
}