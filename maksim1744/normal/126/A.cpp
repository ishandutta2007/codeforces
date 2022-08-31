/*
    author:  Maksim1744
    created: 22.08.2020 14:26:48
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

    ll t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    t0 = max(t0, min(t1, t2));
    t0 = min(t0, max(t1, t2));

    if (t0 == min(t1, t2)) {
        if (t1 == t2) {
            cout << x1 << ' ' << x2 << '\n';
        } else if (t1 < t2) {
            cout << x1 << ' ' << 0 << '\n';
        } else {
            cout << 0 << ' ' << x2 << '\n';
        }
    } else if (t0 == max(t1, t2)) {
        if (t1 == t2) {
            cout << x1 << ' ' << x2 << '\n';
        } else if (t1 > t2) {
            cout << x1 << ' ' << 0 << '\n';
        } else {
            cout << 0 << ' ' << x2 << '\n';
        }
    } else {
        // ld best = 1e9;
        pair<ll, ll> ans = {-1, -1};
        pair<ll, ll> best_rat = {1e9, 1};
        for (int iii = 0; iii < 2; ++iii) {
            for (ll y1 = 0; y1 <= x1; ++y1) {
                ll y2;
                if (t0 > t2) {
                    y2 = y1 * (t1 - t0) / (t0 - t2);
                } else {
                    y2 = ((y1 * (t0 - t1) + t2 - t0 - 1)) / (t2 - t0);
                }
                y2 = min(y2, x2);
                auto rat = mp(t1 * y1 + t2 * y2, y1 + y2);
                ll d = __gcd(rat.first, rat.second);
                if (d == 0) continue;
                rat.first /= d;
                rat.second /= d;
                if (rat.first < rat.second * t0) {
                    show(rat, t0);
                    continue;
                }
                if (rat.first * best_rat.second <= best_rat.first * rat.second) {
                    best_rat = rat;
                    // best = cur;
                    if (iii == 0)
                        ans = mp(y1, y2);
                    else
                        ans = mp(y2, y1);
                }
            }
            swap(x1, x2);
            swap(t1, t2);
        }
        auto [y1, y2] = ans;
        cout << y1 << ' ' << y2 << endl;
    }

    return 0;
}