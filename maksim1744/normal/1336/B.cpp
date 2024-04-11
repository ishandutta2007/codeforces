/*
    author:  Maksim1744
    created: 15.04.2020 17:53:26
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

void solve() {
    vector<int> n(3);
    cin >> n;
    vector<vector<ll>> v(3);
    for (int i = 0; i < 3; ++i) {
        v[i].resize(n[i]);
        cin >> v[i];
        sort(v[i].begin(), v[i].end());
    }
    ll ans = 1e18 * 4;
    vector<int> p = {0, 1, 2};
    auto calc = [&](ll a, ll b, ll c) {
        return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
    };
    do {
        int n0 = n[p[0]];
        int n1 = n[p[1]];
        int n2 = n[p[2]];
        vector<ll> &v0 = v[p[0]];
        vector<ll> &v1 = v[p[1]];
        vector<ll> &v2 = v[p[2]];
        for (int i = 0; i < n0; ++i) {
            ll x = v0[i];
            ll iy = lowb(v1, x);
            if (iy >= n1)
                break;
            ll y = v1[iy];
            ll iz = lowb(v2, y);
            if (iz >= n2)
                break;
                
            ll z = v2[iz];
            ll besty = (x + z) / 2;
            int i1 = lowb(v1, besty);
            int i2 = i1 - 1;
            if (i1 < n1 && i1 >= 0) ans = min(ans, calc(x, v1[i1], z));
            if (i2 < n1 && i2 >= 0) ans = min(ans, calc(x, v1[i2], z));
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}