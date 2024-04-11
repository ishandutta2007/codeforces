/*
    author:  Maksim1744
    created: 24.10.2021 13:33:24
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    reverse(a.begin(), a.end());
    vector<ll> pref(a.begin(), a.end());
    for (int i = 1; i < n; ++i)
        pref[i] += pref[i - 1];
    auto gets = [&](int l, int r) {
        return pref[r] - (l == 0 ? 0ll : pref[l - 1]);
    };

    int B = sqrt(n) * 2 + 10;
    vector<vector<ll>> mx(n);
    for (int i = 0; i < n; ++i) {
        mx[i].assign(B, 0);
        if (i) mx[i] = mx[i - 1];
        mx[i][1] = max(mx[i][1], gets(i, i));
        for (int j = 2; j < B; ++j) {
            if (i - j >= 0) {
                ll cur = gets(i - j + 1, i);
                if (cur < mx[i - j][j - 1])
                    mx[i][j] = max(mx[i][j], cur);
            }
        }
        if (i - B >= 0) {
            mx[i - B].clear();
            mx[i - B].shrink_to_fit();
        }
    }
    show(mx);
    int k = -1;
    for (int i = 1; i < B; ++i)
        if (mx.back()[i] > 0)
            k = i;
    cout << k << '\n';
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