/*
    author:  Maksim1744
    created: 24.09.2020 18:03:26
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
    int n, q;
    cin >> n >> q;
    ll res = 0;
    vector<int> a(n);
    cin >> a;
    auto is_up = [&](int i) {
        if (i != 0 && a[i] < a[i - 1]) return false;
        if (i + 1 < a.size() && a[i] < a[i + 1]) return false;
        return true;
    };
    auto is_down = [&](int i) {
        if (i == 0 || i == n - 1) return false;
        if (a[i] > a[i - 1]) return false;
        if (a[i] > a[i + 1]) return false;
        return true;
    };
    auto val = [&](int i) {
        if (is_up(i)) return a[i];
        if (is_down(i)) return -a[i];
        return 0;
    };
    for (int i = 0; i < n; ++i) {
        res += val(i);
    }
    cout << res << '\n';
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        vector<int> check;
        for (int i = -1; i <= 1; ++i) {
            check.pb(l + i);
            check.pb(r + i);
        }
        sort(check.begin(), check.end());
        check.erase(unique(check.begin(), check.end()), check.end());
        for (auto i : check) {
            if (i >= 0 && i < n)
                res -= val(i);
        }
        swap(a[l], a[r]);
        for (auto i : check) {
            if (i >= 0 && i < n)
                res += val(i);
        }
        show(a);
        debug {
            for (int i = 0; i < n; ++i) {
                if (is_up(i))
                    cout << '+';
                else if (is_down(i))
                    cout << '-';
                else cout << '.';
            }
            cout << endl;
        }
        cout << res << '\n';
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