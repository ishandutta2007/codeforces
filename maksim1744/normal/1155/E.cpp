/*
    author:  Maksim1744
    created: 23.04.2019 17:11:12
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int K = 11;
const ll mod = 1000003;
vector<vector<ll>> minv = {
{ 39916800, -199584000,   598752000, -1197504000,  1676505600, -1676505600,  1197504000,  -598752000,  199584000,  -39916800,   3628800},
{-80627040,  502927200, -1608573600,  3316939200, -4727540160,  4783423680, -3445243200,  1733313600, -580543200,  116552160, -10628640},
{ 70290936, -503126280,  1727578440, -3698304480,  5393046960, -5541317712,  4035361680, -2047105440,  690085080, -139262760,  12753576},
{-34967140,  274727240, -1003011660,  2233166160, -3342229800,  3497286240, -2581262040,  1322982960, -449614260,   91331800,  -8409500},
{ 11028590,  -92615030,   355598730,  -821580360,  1263374700, -1348939620,  1011120180,  -524563080,  180021510,  -36862550,   3416930},
{ -2310945,   20390160,   -81560115,   194790960,  -307585530,   335437200,  -255740310,   134522640,  -46695285,    9653280,   -902055},
{   326613,   -2992710,    12376665,   -30429000,    49260330,   -54871236,    42592410,   -22748040,    7999425,   -1672230,    157773},
{   -30810,     290760,    -1235790,     3115440,    -5159700,     5866560,    -4638060,     2517840,    -898290,     190200,    -18150},
{     1860,     -17970,       78120,     -201240,      340200,     -394380,      317520,     -175320,      63540,     -13650,      1320},
{      -65,        640,       -2835,        7440,      -12810,       15120,      -12390,        6960,      -2565,        560,       -55},
{        1,        -10,          45,        -120,         210,        -252,         210,        -120,         45,        -10,         1}};
ll dv = 3628800;

int ask(int x) {
    cout << "? " << x << endl;
    int k;
    cin >> k;
    if (k == -1)
        exit(0);
    return k;
}

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

long long inv(long long x) {
    return mpow(x, mod - 2);
}

int main() {
    dv = inv(dv);
    vector<vector<ll>> v(K, vector<ll>(K + 1));
    // for (int i = 0; i < K; ++i) {
    //     v[i][0] = 1;
    //     for (int j = 1; j < K; ++j) {
    //         v[i][j] = v[i][j - 1] * i;
    //     }
    // }
    vector<ll> aa(K);
    for (int i = 0; i < K; ++i) {
        // v[i][K] = ask(i);
        aa[i] = ask(i + 1);
    }
    vector<ll> a(K, 0);
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            a[i] += minv[i][j] * aa[j];
        }
        a[i] = (a[i] % mod + mod) % mod;
        a[i] = a[i] * dv % mod;
    }
    for (ll x = 0; x < mod; ++x) {
        ll sm = 0;
        ll p = 1;
        for (int i = 0; i < K; ++i) {
            sm += a[i] * p;
            p = p * x % mod;
        }
        if (sm % mod == 0) {
            cout << "! " << x << endl;
            return 0;
        }
    }
    cout << "! " << -1 << endl;
    // for (int i = 0; i < K; ++i) {
    //     int ind = i;
    //     while (ind < K && v[ind][i] == 0)
    //         ++ind;
    //     if (ind == K)
    //         continue;
    //     swap(v[i], v[ind]);
    //     for (int j = i; j < K; ++j) {
    //         if (v[j][i] != 0) {
    //             ll k = inv(v[j][i]);
    //             for (int u = i; u <= K; ++u) {
    //                 v[j][u] = v[j][u] * k % mod;
    //             }
    //         }
    //     }
    //     for (int j = i + 1; j < K; ++j) {
    //         for (int u = i; u <= K; ++u) {
    //             v[j][u] = (v[j][i] - v[i][i] + mod) % mod;
    //         }
    //     }
    // }
    // printMatrix(v);
    // for (int i = K - 1; i >= 0; --i) {
    //     for (int j = i - 1; j >= 0; --j) {
    //         for (int u = K; u >= i; --u) {
    //             v[j][u] -= v[i][u] * v[j][i];
    //         }
    //     }
    // }
    // printMatrix(v);
    // for (int i = 0; i < K; ++i) {
    //     a[i] = v[i][K];
    // }
    // show(a);
    return 0;
}