/*
    author:  Maksim1744
    created: 14.08.2020 17:51:48
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
    multiset<int> lights;
    multiset<int> best;
    multiset<int> other;
    ll sum_best = 0;
    ll sum_total = 0;
    auto add = [&](int d) {
        if (other.empty() || *--other.end() < d) {
            best.insert(d);
            sum_best += d;
            int k = *best.begin();
            sum_best -= k;
            best.erase(best.begin());
            other.insert(k);
        } else {
            other.insert(d);
        }
    };
    auto del = [&](int d) {
        if (!other.empty() && d <= *--other.end()) {
            other.erase(other.find(d));
        } else {
            best.erase(best.find(d));
            sum_best -= d;
            if (!other.empty()) {
                best.insert(*--other.end());
                sum_best += *--other.end();
                other.erase(--other.end());
            }
        }
    };
    while (n--) {
        int tp, d;
        cin >> tp >> d;
        sum_total += d;
        if (d > 0) {
            if (tp == 1) {
                lights.insert(d);
                add(d);
                best.insert(*--other.end());
                sum_best += *--other.end();
                other.erase(--other.end());
            } else {
                add(d);
            }
        } else {
            d = -d;
            del(d);
            if (tp == 1) {
                lights.erase(lights.find(d));
                if (best.size() > lights.size()) {
                    other.insert(*best.begin());
                    sum_best -= *best.begin();
                    best.erase(best.begin());
                }
            } else {
            }
        }
        show(other);
        show(best);
        show(lights);
        show(sum_total);
        show(sum_best);
        if (lights.empty()) {
            cout << sum_total << '\n';
        } else {
            if (other.empty() || *--other.end() < *lights.begin()) {
                ll res = sum_total + sum_best - *best.begin();
                if (!other.empty()) res += *--other.end();
                cout << res << '\n';
            } else {
                cout << sum_total + sum_best << '\n';
            }
        }
    }

    return 0;
}