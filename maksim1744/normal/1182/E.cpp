/*
    author:  Maksim1744
    created: 11.06.2019 17:03:43
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

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
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

const ll mod = 1e9 + 7;
const int S = 5;

struct Matrix {
    array<array<ll, S>, S> v;

    Matrix() {
        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < S; ++j) {
                v[i][j] = 0;
            }
        }
    }

    array<ll, 5>& operator[](int i) {
        return v[i];
    }
};

Matrix operator*(Matrix a, Matrix b) {
    Matrix c;
    // show(a.v, b.v);
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            for (int k = 0; k < S; ++k) {
                c[i][j] += a[i][k] * b[k][j] % (mod - 1);
            }
        }
    }
    // show(c.v);
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            c[i][j] %= mod - 1;
        }
    }
    return c;
}

Matrix mpowm(Matrix a, long long p) {
    Matrix res;
    for (int i = 0; i < S; ++i) {
        res[i][i] = 1;
    }
    while (p) {
        // show(p);
        if (p & 1) res = res * a;
        p >>= 1;
        a = a * a;
    }
    return res;
}

long long mpow(long long a, long long p, long long mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    Matrix m;
    m[0][0] = m[0][1] = m[0][2] = 1; m[0][3] = 2; m[0][4] = mod - 1-4;
    m[1][0] = m[2][1] = m[3][3] = m[3][4] = 1;
    // m[0][3] = (x * 2 - 6 + mod - 1) % (mod - 1);
    m[4][4] = 1;
    m = mpowm(m, n - 3);
    f3 = mpow(f3, m[0][0], mod);
    f2 = mpow(f2, m[0][1], mod);
    f1 = mpow(f1, m[0][2], mod);
    ll fc = mpow(c, m[0][4] + m[0][3] * 3, mod);
    cout << f1 * f2 % mod * f3 % mod * fc % mod << '\n';
    return 0;
}