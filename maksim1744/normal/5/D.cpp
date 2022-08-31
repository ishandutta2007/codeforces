/*
    author:  Maksim1744
    created: 20.08.2020 23:11:30
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

    ld a, v;
    cin >> a >> v;
    ld s, d, w;
    cin >> s >> d >> w;
    ld to_sign = d;

    ld can = sqrt(to_sign * a * 2);
    show(can);
    if (v <= w || can <= w) {
        ld acc_t = v / a;
        ld acc_s = v * v / a / 2;
        if (acc_s <= s) {
            cout << fixed << setprecision(20) << acc_t + (s - acc_s) / v << endl;
        } else {
            cout << fixed << setprecision(20) << sqrt(s * 2 / a) << endl;
        }
        return 0;
    }

    ld t = 0;
    ld l = 0, r = to_sign;
    ld maxv;
    for (int i = 0; i < 200; ++i) {
        ld s_stop = (l + r) / 2;
        maxv = min(v, sqrt(s_stop * a * 2));
        if (maxv <= w) {
            l = s_stop;
            continue;
        }
        ld need = (maxv * maxv - w * w) / a / 2;
        if (s_stop + need <= to_sign) {
            l = s_stop;
        } else {
            r = s_stop;
        }
        // ld s0 = 0;
        // ld maxv = v;
        // if (c * a < v) {
        //     s0 = a * c * c / 2;
        //     maxv = c * a;
        // } else {
        //     ld tt = v / a;
        //     s0 = v * v / a / 2 + (c - tt) * v;
        // }
        // if (s0 > to_sign) {
        //     r = c;
        //     continue;
        // }
        // ld need_t = abs(maxv - w) / a;
        // ld need_s = (maxv * maxv - w * w) / a / 2;
        // if (s0 + need_s <= to_sign) {
        //     l = c;
        // } else {
        //     r = c;
        // }
    }
    ld tos = v * v / a / 2;
    show(tos);
    if (tos < l) {
        t += v / a + (l - tos) / v;
    } else {
        t += sqrt(l * 2 / a);
    }
    show(t);
    t += (maxv - w) / a;

    show(t);
    show(maxv);

    s -= to_sign;
    ld to_speed = (v * v - w * w) / a / 2;
    if (to_speed <= s) {
        t += (v - w) / a + (s - to_speed) / v;
    } else {
        ld l = 0, r = 1e9;
        for (int i = 0; i < 200; ++i) {
            ld c = (l + r) / 2;
            ld s0 = w * c + a * c * c / 2;
            if (s0 < s) l = c;
            else r = c;
        }
        t += l;
    }
    cout << fixed << setprecision(20) << t << endl;

    return 0;
}