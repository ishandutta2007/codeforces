/*
    author:  Maksim1744
    created: 08.03.2022 17:46:49
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

void test_case(int test) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    cin >> a;
    --a;
    int mn = a[0];
    int mni = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] - 1 < mn) {
            mn = a[i] - a[i - 1] - 1;
            mni = i;
        }
    }

    vector<int> ch = {mni};
    if (mni) ch.pb(mni - 1);

    auto calc = [&](const vector<int>& v) {
        int ans = v[0];
        for (int i = 1; i < v.size(); ++i)
            ans = min(ans, v[i] - v[i - 1] - 1);
        return ans;
    };

    show(a);
    show(ch);

    int ans = mn;
    show(ans);
    for (int rm : ch) {
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (i != rm)
                b.pb(a[i]);
        }
        if (b.back() != d - 1) {
            b.pb(d - 1);
            show(b, calc(b));
            ans = max(ans, calc(b));
            b.pop_back();
        }

        int mxi = 0;
        int mx = b[0];
        for (int i = 1; i < b.size(); ++i) {
            if (b[i] - b[i - 1] - 1 > mx) {
                mx = b[i] - b[i - 1] - 1;
                mxi = i;
            }
        }
        show(b, mx);
        if (mx != 0) {
            int r = b[mxi];
            int l = (mxi == 0 ? -1 : b[mxi - 1]);
            b.insert(b.begin() + mxi, (l + r) / 2);
            show(b, calc(b));
            if (is_sorted(b.begin(), b.end()) && set<int>(b.begin(), b.end()).size() == b.size())
                ans = max(ans, calc(b));
        }
    }
    cout << ans << '\n';
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