/*
    author:  Maksim1744
    created: 15.04.2020 19:12:54
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
    vector<int> v = {1, 2, 3, 1};
    for (int i = 0; i < n - 4; ++i) {
        v.pb(v.size());
    }
    vector<int> ans1(n + 1), ans2(n + 1);
    cin >> ans1[0] >> ans2[0];
    for (int i = 0; i < n; ++i) {
        cout << "+ " << v[i] << endl;
        cin >> ans1[i + 1] >> ans2[i + 1];
    }
    vector<int> c(n + 1, 0);
    if (ans2[2] != ans2[1]) {
        // c3 != 0
        if (ans1[2] == ans1[3]) {
            c[3] = 2;
        } else {
            while (c[3] * (c[3] - 1) / 2 != ans1[3] - ans1[2])
                ++c[3];
            ++c[3];
        }
    } else {
        c[3] = 1;
    }
    c[2] = (ans2[4] - ans2[3]) / c[3];
    c[1] = 1;
    while (c[1] * (c[1] - 1) / 2 != ans1[4] - ans1[3])
        ++c[1];
    ++c[1];

    if (n == 4) {
        c[4] = ((ans2[3] - ans2[2]) - (c[1] - 1) * c[2]) / c[2];
    } else {
        if (ans2[3] == ans2[2] + c[2] * (c[1] - 1)) {
            c[4] = 1;
        } else {
            if (ans1[5] == ans1[4])
                c[4] = 2;
            else {
                c[4] = 0;
                while (c[4] * (c[4] - 1) / 2 != ans1[5] - ans1[4])
                    ++c[4];
                ++c[4];
            }
        }
    }
    for (int i = 5; i <= n; ++i) {
        if (i == n) {
            c[i] = ((ans2[i] - ans2[i - 1]) - c[i - 2] * c[i - 3]) / c[i - 2];
            break;
        }
        if (ans2[i] == ans2[i - 1] + c[i - 2] * c[i - 3]) {
            c[i] = 1;
        } else {
            if (ans1[i + 1] == ans1[i])
                c[i] = 2;
            else {
                c[i] = 0;
                while (c[i] * (c[i] - 1) / 2 != ans1[i + 1] - ans1[i])
                    ++c[i];
                ++c[i];
            }
        }
    }


    c[1]--;
    c[n]++;
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << ' ' << c[i + 1] - 1;
    }
    cout << endl;

    return 0;
}