/*
    author:  Maksim1744
    created: 20.04.2019 21:27:44
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

int main() {
    ll m, a, b;
    cin >> m >> a >> b;
    if (a == b) {
        ll mx = (m + 1) / a;
        ll sm = mx * (mx + 1) / 2 * a;
        sm += ((m + 1) % a) * (mx + 1);
        cout << sm << '\n';
    } else {
        ll sm = 0;
        ll c = a + b + 3;
        ll d = __gcd(a, b);
        ll c1 = c;
        if (c < m) {
            ++c;
            while (c % d != 0) {
                sm += c / d + 1;
                ++c;
            }
            // show(sm, c);
            ll delta = c / d;
            ll m1 = m - c;
            c = 0;
            ll mx = (m1 + 1) / d;
            sm += mx * (mx + 1) / 2 * d;
            sm += ((m1 + 1) % d) * (mx + 1);
            sm += delta * (m1 + 1);
        }
        // show(sm);
        c = min(m, c1);
        vector<ll> need(c + 1);
        ll inf = c + 10;
        for (int i = 0; i <= c; ++i) {
            need[i] = inf;
        }
        need[0] = 0;
        ll p = 0;
        ll mx = 0;
        bool out = false;
        while (!out) {
            while (p < b) {
                p += a;
                if (p > c) {
                    p -= a;
                    out = true;
                    break;
                }
                mx = max(mx, p);
                need[p] = min(need[p], mx);
            }
            while (p >= b) {
                p -= b;
                need[p] = min(need[p], mx);
            }
            if (p == 0) {
                break;
            }
        }
        vector<vector<int>> from(c + 1);
        for (int i = 0; i <= c; ++i) {
            if (need[i] != inf) {
                from[need[i]].pb(i);
            }
        }
        for (int i = 0; i <= c; ++i) {
            for (auto j : from[i]) {
                int was = need[j];
                j += a;
                while (j <= c && need[j] > was && j > was) {
                    need[j] = was;
                    j += a;
                }
            }
        }
        for (int i = 0; i <= c; ++i) {
            need[i] = max(need[i], (ll)i);
        }
        // show(need);
        for (ll k : need) {
            if (k <= c) {
                sm += (c - k + 1);
            }
        }
        cout << sm << '\n';
    }
    return 0;
}