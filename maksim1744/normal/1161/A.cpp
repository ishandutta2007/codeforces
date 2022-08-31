/*
    author:  Maksim1744
    created: 05.05.2019 22:47:32
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
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
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
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    cin >> x;
    ll ans = 0;
    set<int> s(x.begin(), x.end());
    ans += (ll)(n - s.size());
    show(ans);
    vector<int> lt(n, -1), ft(n, 1e9);
    for (int i = 0; i < k; ++i) {
        lt[x[i] - 1] = i;
    }
    for (int i = k - 1; i >= 0; --i) {
        ft[x[i] - 1] = i;
    }
    // show(lt, ft);
    for (int i = 0; i < n - 1; ++i) {
        if (lt[i + 1] < ft[i]) {
            ++ans;
            // show(i+1, i);
        }
        if (lt[i] < ft[i + 1]) {
            ++ans;
            // show(i, i+1);
        }
    }
    cout << ans << '\n';
    return 0;
}