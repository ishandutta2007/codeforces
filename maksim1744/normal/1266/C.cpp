/*
    author:  Maksim1744
    created: 17.12.2019 18:13:15
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

const int N = 100000;

int main() {
    int r, c;
    cin >> r >> c;
    // vector<bool> isp(N, true);
    // isp[0] = isp[1] = false;
    // for (int i = 2; i * i < N; ++i) {
    //     if (isp[i]) {
    //         for (int j = i * i; j < N; j += i) {
    //             isp[j] = false;
    //         }
    //     }
    // }
    // vector<int> primes = {1};
    // for (int i = 0; i < N; ++i) {
    //     if (isp[i]) {
    //         primes.pb(i);
    //     }
    // }
    if (r == 1 && c == 1) {
        cout << 0 << endl;
    } else if (r == 1) {
        for (int i = 0; i < c; ++i) {
            cout << i + 2 << ' ';
        }
        cout << '\n';
    } else if (c == 1) {
        for (int i = 0; i < r; ++i) {
            cout << i + 2 << '\n';
        }
    } else {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int a = i + 1, b = j + 1 + r;
                cout << a * b / __gcd(a, b) << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}