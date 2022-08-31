/*
    author:  Maksim1744
    created: 03.05.2019 15:39:52
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
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int N = 15000005;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<bool> sieve(N, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i < N; ++i)
        if (sieve[i])
            if ((ll)i * (ll)i < N)
                for (int j = i * i; j < N; j += i)
                    sieve[j] = false;
    vector<int> primes;
    for (int i = 0; i < N; ++i) {
        if (sieve[i])
            primes.pb(i);
    }
    vector<int> cnt(N, 0);
    int g = a[0];
    for (auto t : a) {
        g = __gcd(g, t);
    }
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        a[i] /= g;
        if (a[i] != 1)
            ok = true;
    }
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }
    for (auto t : a) {
        if (t == 1)
            continue;
        if (sieve[t])
            ++cnt[t];
        else {
            for (auto p : primes) {
                if ((ll)p * p > t)
                    break;
                if (t % p == 0) {
                    ++cnt[p];
                    while (t % p == 0)
                        t /= p;
                }
            }
            if (t != 1)
                ++cnt[t];
        }
    }
    int mx = 0;
    for (int i = 2; i < N; ++i)
        mx = max(mx, cnt[i]);
    if (mx == 0)
        cout << -1 << '\n';
    else
        cout << n - mx << '\n';
    return 0;
}