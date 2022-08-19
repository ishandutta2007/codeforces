/*
    author:  Maksim1744
    created: 07.07.2021 18:08:27
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

int K;
vector<int> operator + (const vector<int> &a, const vector<int> &b) {
    vector<int> res(max(a.size(), b.size()), 0);
    for (int i = 0; i < a.size(); ++i) {
        res[i] = (res[i] + a[i]) % K;
    }
    for (int i = 0; i < b.size(); ++i) {
        res[i] = (res[i] + b[i]) % K;
    }
    return res;
}
vector<int> operator - (const vector<int> &a, const vector<int> &b) {
    vector<int> res(max(a.size(), b.size()), 0);
    for (int i = 0; i < a.size(); ++i) {
        res[i] = (res[i] + a[i]) % K;
    }
    for (int i = 0; i < b.size(); ++i) {
        res[i] = (res[i] + K - b[i]) % K;
    }
    return res;
}

void test_case(int test) {
    int n, k;
    cin >> n >> k;
    K = k;
    vector<int> tot;

    auto ton = [&](vector<int> v) {
        reverse(v.begin(), v.end());
        int ans = 0;
        for (int x : v)
            ans = ans * K + x;
        return ans;
    };
    auto tov = [&](int n) {
        vector<int> res;
        while (n) {
            res.pb(n % K);
            n /= K;
        }
        return res;
    };

    for (int i = 0; i < n; ++i) {
        vector<int> y;
        auto x = tov(i);
        if (i % 2 == 0) {
            y = tot + x;
        } else {
            y = tot - x;
        }
        cout << ton(y) << endl;
        int r;
        cin >> r;
        if (r == 1) return;
        tot = (y - tot);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}