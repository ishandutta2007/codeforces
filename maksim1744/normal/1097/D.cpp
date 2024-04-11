/*
    author:  Maksim1744
    created: 01.05.2019 21:51:33
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
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
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
const int N = 55;
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
const int N = 55;
#endif

const ll mod = 1e9 + 7;
const int M = 1e7 * 4;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

using T = long long;

int main() {
    ll n;
    int k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    vector<pair<ll, int>> p;
    if (n % 2 == 0) {
        p.eb(2, 0);
        while (n % 2 == 0) {
            n /= 2;
            p.back().second++;
        }
    }
    vector<bool> v(M, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i < M; ++i) {
        if ((ll)i * (ll)i < M) {
            for (int j = i * i; j < M; j += i)
                v[j] = false;
        }
    }
    vector<ll> primes;
    for (int i = 0; i < M; ++i) {
        if (v[i])
            primes.pb(i);
    }
    for (ll pr : primes) {
        if (pr * pr > n)
            break;
        if (n % pr == 0) {
            p.eb(pr, 0);
            while (n % pr == 0) {
                n /= pr;
                p.back().second++;
            }
        }
    }
    if (n != 1) {
        p.eb(n, 1);
    }
    vector<vector<T>> f(N, vector<T>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            f[i][j] = 0;
        }
        f[i][i] = 1;
    }
    vector<ll> inv(N + 1);
    for (int i = 1; i <= N; ++i) {
        inv[i] = mpow(i, mod - 2);
    }
    for (int u = 1; u <= k; ++u) {
        for (int j = 0; j < N; ++j) {
            vector<T> s(N);
            s[0] = f[0][j];
            for (int i = 1; i < N; ++i) {
                s[i] = s[i - 1] + f[i][j];
                s[i] %= mod;
            }
            for (int i = 0; i < N; ++i) {
                f[i][j] = s[i] * inv[i + 1] % mod;// / (i + 1);// % mod;
            }
        }
    }
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         cout << fixed << setprecision(4) << f[i][j][k] << '\t';
    //     }
    //     cout << '\n';
    // }
    // show(f);
    ll cnt = 1;
    ll s = 0;
    for (auto pr : p) {
        cnt *= pr.second + 1;
    }
    show(p, cnt);
    vector<ll> to(p.size());
    vector<ll> pw(p.size());
    for (int i = 0; i < p.size(); ++i) {
        pw[i] = 1;
        for (int j = 0; j < p[i].second; ++j) {
            pw[i] *= p[i].first;
        }
    }
    show(pw, cnt);
    ll num = 1;
    for (int i = 0; i < cnt; ++i) {
        if (i != 0) {
            int ind = (int)to.size() - 1;
            while (true) {
                ++to[ind];
                if (to[ind] < p[ind].second + 1) {
                    num *= p[ind].first;
                    break;
                } else {
                    num /= pw[ind];
                    to[ind] = 0;
                }
                --ind;
            }
        }
        // show(to, num);
        ll prob = 1;
        for (int j = 0; j < p.size(); ++j) {
            prob = prob * f[p[j].second][to[j]] % mod;
        }
        s += num % mod * prob % mod;
    }
    cout << s % mod << '\n';
    return 0;
}