/*
    author:  Maksim1744
    created: 05.01.2021 18:00:54
*/

#include "bits/stdc++.h"

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

    // int n = 4;
    // int k = 1e9;
    // vector<int> v(n, k);
    // int p = 0;
    // for (int i = 0; i < 30; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         string s = to_string(v[j]);
    //         while (s.size() < 3) s.insert(s.begin(), ' ');
    //         cout << s << ' ';
    //     }
    //     cout << '\n';
    //     vector<int> w(n, 0);
    //     for (int i = 0; i < n; ++i) {
    //         if (i == p) {
    //             w[(i + 1) % n] += v[i];
    //         } else {
    //             int x = v[i];
    //             w[(i + 1) % n] += (x + 1) / 2;
    //             w[(i - 1 + n) % n] += (x) / 2;
    //         }
    //     }
    //     swap(v, w);
    // }

    int n;
    ll k;
    cin >> n >> k;

    auto ask = [&](int i) {
        i += 1;
        cout << "? " << i << endl;
        ll k;
        cin >> k;
        return k;
    };

    for (int i = 0; i < 350; ++i) {
        ask(0);
    }
    int ibigger = -1;
    int ismaller = -1;
    int step = max(1, n / 350);
    for (int i = 0; i < n; i += step) {
        ll v = ask(i);
        if (v > k) {
            ibigger = i;
        } else if (v < k) {
            ismaller = i;
        }
    }
    assert(ibigger != -1);
    assert(ismaller != -1);
    while (true) {
        int c;
        if (ismaller < ibigger) {
            c = (ismaller + ibigger) / 2;
        } else {
            c = (ismaller + ibigger + n) / 2 % n;
        }
        // cerr << ismaller << ' ' << ibigger << ' ' << c << endl;
        ll v = ask(c);
        if (v == k) {
            cout << "! " << c + 1 << endl;
            return 0;
        }
        if (v > k)
            ibigger = c;
        else
            ismaller = c;
    }

    return 0;
}