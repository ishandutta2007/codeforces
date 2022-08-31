/*
    author:  Maksim1744
    created: 16.04.2021 17:49:33
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
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

const ll inf = 4e18;

void test_case(int test) {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> cnt(n + 1);
    cnt[0] = 1;
    cnt[1] = 1;
    for (int i = 2; i < cnt.size(); ++i) {
        cnt[i] = cnt[i - 1] * 2;
        if (cnt[i] >= inf)
            cnt[i] = inf;
    }
    if (cnt[n] < k) {
        cout << -1 << '\n';
        return;
    }
    vector<int> p;
    function<void(int, ll, int)> buildp = [&](int n, ll k, int s) {
        show(n, k, s);
        if (k == 1) {
            for (int i = 0; i < n; ++i) {
                p.pb(s + i);
            }
            return;
        }
        assert(cnt[n] >= k);
        int pre = 1;
        while (pre <= n) {
            if (cnt[n - pre] >= k) {
                for (int i = 0; i < pre; ++i) {
                    p.pb(s + pre - 1 - i);
                }
                buildp(n - pre, k, s + pre);
                return;
            } else {
                k -= cnt[n - pre];
                ++pre;
            }
        }
        assert(false);
    };
    buildp(n, k, 1);
    cout << p << '\n';
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