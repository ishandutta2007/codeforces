/*
    author:  Maksim1744
    created: 18.08.2020 23:23:05
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

int count(vector<int> a, vector<int> b) {
    int ans = 0;
    while (!b.empty()) {
        show(a, b);
        while (a.size() >= b.size()) {
            if (a.back() == -1) {
                for (int i = 0; i < a.size(); ++i) {
                    a[i] *= -1;
                }
            }
            if (b.back() == -1) {
                for (int i = 0; i < b.size(); ++i) {
                    b[i] *= -1;
                }
            }
            for (int i = 0; i < b.size(); ++i) {
                a[a.size() - i - 1] -= b[b.size() - i - 1];
            }
            while (!a.empty() && a.back() == 0) a.pop_back();
        }
        swap(a, b);
        ++ans;
    }
    return ans;
}

pair<vector<int>, vector<int>> calc(int n) {
    if (n == 1) {
        vector<int> a = {0, 1};
        vector<int> b = {1};
        return {a, b};
    }
    auto [b, a] = calc(n - 1);
    a.pb(0); a.pb(0);
    bool canadd = true;
    for (int i = 0; i < b.size(); ++i) {
        if (abs(a[a.size() - i - 1] + b[b.size() - i - 1]) > 1) {
            canadd = false;
            break;
        }
    }
    if (!canadd) {
        for (int i = 0; i < b.size(); ++i) {
            b[i] *= -1;
        }
    }
    for (int i = 0; i < b.size(); ++i) {
        a[a.size() - i - 1] += b[b.size() - i - 1];
    }
    if (a.back() < 0) {
        for (int i = 0; i < a.size(); ++i) {
            a[i] *= -1;
        }
    }
    if (b.back() < 0) {
        for (int i = 0; i < b.size(); ++i) {
            b[i] *= -1;
        }
    }
    return {a, b};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    // bool odd = (n % 2 == 1);
    // if (odd) ++n;
    // vector<int> a(n + 1, 0);
    // int s = 1;
    // for (int i = n; i >= 0; i -= 2) {
    //     a[i] = s;
    //     s *= -1;
    // }
    // vector<int> b(a.size() - 1, 0);
    // b.back() = 1;
    // if (odd) {
    //     a.pop_back();
    //     a.pop_back();
    //     for (int i = 0; i < a.size(); ++i) {
    //         a[i] = -a[i];
    //     }
    //     swap(a, b);
    // }
    auto [a, b] = calc(n);
    // show(count(a, b));
    cout << a.size() - 1 << '\n';
    cout << a << '\n';
    cout << b.size() - 1 << '\n';
    cout << b << '\n';

    return 0;
}