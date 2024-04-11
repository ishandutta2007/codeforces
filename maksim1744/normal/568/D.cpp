/*
    author:  Maksim1744
    created: 07.04.2021 18:40:03
*/

#include "bits/stdc++.h"

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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
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

struct line {
    ll a, b, c;
    int i;
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

using i128 = __int128;
pair<pair<i128, i128>, pair<i128, i128>> inter(line l1, line l2) {
    pair<i128, i128> x = {l2.c * l1.b - l1.c * l2.b, l1.a * l2.b - l2.a * l1.b};
    pair<i128, i128> y = {l2.c * l1.a - l1.c * l2.a, l1.b * l2.a - l2.b * l1.a};
    return {x, y};
};

array<vector<line>, 10> preall;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<pair<int, int>> ans;

    int n, k;
    cin >> n >> k;
    vector<line> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].i = i + 1;
    }

    function<void(const vector<line>&, int)> calc = [&](const vector<line> &v, int k) {
        if (v.size() <= k) {
            for (int i = 0; i < v.size(); ++i) {
                ans.eb(v[i].i, -1);
            }
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (auto p : ans) {
                cout << p << '\n';
            }
            exit(0);
        }
        if (k == 0) return;
        vector<line> &nx = preall[k];
        for (int it = 0; it < 30; ++it) {
            int i = rnd(v.size());
            int j = rnd(v.size());
            if (v[i].a * v[j].b == v[j].a * v[i].b) continue;
            auto [x, y] = inter(v[i], v[j]);
            nx.clear();
            for (auto &l : v) {
                if (l.a * x.first * y.second + l.b * y.first * x.second + l.c * x.second * y.second == 0) continue;
                nx.pb(l);
                if ((v.size() - nx.size()) * k < v.size()) break;
            }
            if ((v.size() - nx.size()) * k < v.size()) continue;
            ans.eb(v[i].i, v[j].i);
            calc(nx, k - 1);
            ans.pop_back();
        }
    };
    calc(v, k);
    cout << "NO\n";

    return 0;
}