/*
    author:  Maksim1744
    created: 07.06.2021 16:29:14
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

void test_case(int test) {
    ll x = 1;
    int que = 0;
    auto ask = [&](ll m) {
        ++que;
        cout << "? " << m << endl;
        string s;
        cin >> s;
        if (s == "Fired!") exit(0);
        else if (s == "Lucky!") {
            x += m;
            return 1;
        }
        else if (s == "Fraudster!") {
            x -= m;
            assert(x >= 0);
            return 0;
        }
        assert(false);
        return 2;
    };
    ll l = 0, r = 1e14;
    // for (ll t = 1; t <= 1e14; t *= 2)
    //     if (!ask(t)) {
    //         r = t - 1;
    //         break;
    //     }
    const int Q = 100;
    while (l != r) {
        ld p = (ld)min(Q, que) / Q * 0.50 + (1 - (ld)min(que, Q) / Q) * 0.75;
        p = (sqrt(5) - 1) / 2 + 0.01;

        if ((ld)x / r > 6.5)
            p = 0.53;
        // if ((ld)x / r > 8)
        //     p = 0.5;
        if (que > 101)
            p = 0.5;

        // if (l > 1e14 - 1e13)
        //     p = min(p, 0.52l);
        // if (l > 1e14 - 1.5e13)
        //     p = min(p, 0.60l);

        ll m = (l * p + r * (1 - p));
        m = max(m, l + 1);
        m = min(m, max(max(l, 1ll), (ll)(x * 0.92)));

        if (que + r - l <= 105 && x >= l + 1)
            m = l + 1;

        // show(m, l, r, x, p);
        // if (r - l <= 1)
        //     m = r;
        // if (l >= r - 2)
        //     m = r;
        if (ask(m))
            l = m;
        else
            r = m - 1;
    }
    cout << "! " << l << endl;
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