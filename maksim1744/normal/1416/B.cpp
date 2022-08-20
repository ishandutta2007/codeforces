/*
    author:  Maksim1744
    created: 27.09.2020 18:11:29
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

void test_case(int test) {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }
    if (s % n != 0) {
        cout << -1 << '\n';
        return;
    }
    vector<pair<pair<int, int>, ll>> ans;
    auto mv = [&](int i, int j, ll x) {
        if (x == 0) return;
        a[i] -= x * (i + 1);
        a[j] += x * (i + 1);
        assert(a[i] >= 0);
        assert(x >= 0);
        ans.eb(mp(i + 1, j + 1), x);
    };
    for (int j = 1; j < n; ++j) {
        // show(j, a);
        ll k = j + 1;
        ll rem = a[j] % k;
        // show(j, a);
        if (rem == 0) rem = k;
        ll need = k - rem;
        assert(a[0] >= need);
        // show(j, a);
        // show(need);
        if (need != 0) {
            mv(0, j, need);
        }
        // show(j, a);
        mv(j, 0, a[j] / k);
        // show(j, a);
    }
    s /= n;
    for (int j = 1; j < n; ++j) {
        mv(0, j, s);
    }
    show(a);
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a.first << ' ' << a.second << ' ' << b << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}