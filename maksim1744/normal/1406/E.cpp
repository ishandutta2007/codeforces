/*
    author:  Maksim1744
    created: 12.09.2020 17:23:02
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
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<bool> isp(n + 1, true); isp[0] = isp[1] = false;
    for (int i = 2; i * i < n + 1; ++i) {
        if (isp[i]) {
            for (int j = i * i; j < n + 1; j += i) {
                isp[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 0; i < n + 1; ++i) {
        if (isp[i]) {
            primes.pb(i);
        }
    }

    int cnt = 0;
    auto ask = [&](int d) {
        if (d > n) {
            return 0;
        }
        ++cnt;
        assert(cnt <= 9999);
        if (d == 1) {
            cout << "A 1" << endl;
            // cerr << "A 1" << endl;
        } else {
            cout << "B " << d << endl;
            // cerr << "B " << d << endl;
        }
        int x;
        cin >> x;
        return x;
    };
    auto say = [&](int d) {
        cout << "C " << d << endl;
        // cerr << "C " << d << endl;
        exit(0);
    };

    int x = 1;

    for (int p : primes) {
        if (p * p > n) break;
        ask(p);
        int cur = p;
        while (ask(cur) != 0) {
            cur *= p;
            x *= p;
        }
    }
    // show(x);
    if (x == 1) {
        int l = 0;
        while (l < primes.size() && primes[l] * primes[l] <= n) ++l;
        int r = (int)primes.size() - 1;
        while (l <= r) {
            int have = r - l + 1 + 1;
            int m = (l + r) / 2;
            // show(l, r, m);
            for (int i = l; i <= m; ++i) {
                ask(primes[i]);
            }
            if (ask(1) == r - m + 1) {
                l = m + 1;
                continue;
            }
            for (int i = l; i <= m; ++i) {
                if (ask(primes[i])) {
                    x *= primes[i];
                }
            }
            break;
        }
        say(x);
    } else {
        for (int p : primes) {
            if ((ll)p * p <= n) continue;
            if (ask(p) == 2) {
                x *= p;
            }
        }
        say(x);
    }

    return 0;
}