/*
    author:  Maksim1744
    created: 18.12.2021 20:01:44
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    {
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - '0';
        }
    }
    {
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            b[i] = s[i] - '0';
        }
    }
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    vector<int> dif(n);
    for (int i = 0; i < n; ++i) {
        dif[i] = (a[i] ^ b[i]);
    }

    int ans = 1e9;
    for (int b = 0; b < 2; ++b) {
        show(b);
        vector<int> use;
        for (int i = 0; i < n; ++i) {
            if (dif[i] == b) use.pb(i);
        }
        if (use.empty()) continue;
        int flip_use = (use.size() + 1) % 2;
        show(b, flip_use);
        if (flip_use != dif[use[0]]) continue;
        int flip_other = use.size() % 2;
        if (use.size() != n) {
            if (flip_other != (b ^ 1)) {
                continue;
            }
        }
        {
            int c0 = 0, c1 = 0;
            for (int k : use) {
                if (a[k] == 0) ++c0;
                else ++c1;
            }
            if (c0 == c1 || c0 + 1 == c1)
                ans = min(ans, (int)use.size());
        }
    }
    if (ans == 1e9) ans = -1;
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