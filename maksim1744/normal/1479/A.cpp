/*
    author:  Maksim1744
    created: 07.02.2021 17:37:24
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

    vector<int> v(n, -1);

    auto ask = [&](int i) {
        if (v[i] != -1) return v[i];
        cout << "? " << i + 1 << endl;
        int k;
        cin >> k;
        v[i] = k;
        return k;
    };

    if (n < 4) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = ask(i);
        }
        int ind = mini(v);
        cout << "! " << ind + 1 << endl;
        return 0;
    }

    int a0 = ask(0);
    int a1 = ask(1);
    int an = ask(n - 1);
    int an1 = ask(n - 2);
    if (a0 < a1) {
        cout << "! " << 1 << endl;
        return 0;
    }
    if (an < an1) {
        cout << "! " << n << endl;
        return 0;
    }
    int L, M, R;
    if (a1 < an1) {
        L = 0;
        M = 1;
        R = n - 2;
    } else {
        L = 1;
        R = n - 1;
        M = n - 2;
    }

    while (R - L > 2) {
        if (R - M > M - L) {
            int C = (M + R) / 2;
            if (ask(C) < ask(M)) {
                L = M;
                M = C;
            } else {
                R = C;
            }
        } else {
            int C = (L + M) / 2;
            if (ask(C) < ask(M)) {
                R = M;
                M = C;
            } else {
                L = C;
            }
        }
    }

    cout << "! " << M + 1 << endl;

    return 0;
}