/*
    author:  Maksim1744
    created: 29.10.2020 01:13:45
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

pair<ll, ll> go(ll a, ll b) {
    assert(a > b && b > 0);
    ll d = __gcd(a, b);
    a /= d;
    b /= d;
    return {a, b};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k);
    cin >> a;
    vector<pair<ll, int>> eq(k, {0ll, 0});
    vector<int> tp(n);
    vector<vector<pair<ll, int>>> ad(k);
    vector<pair<ll, int>> mul;
    for (int i = 1; i <= n; ++i) {
        int t, ind;
        ll b;
        cin >> t >> ind >> b;
        tp[i - 1] = t;
        --ind;
        if (t == 1) {
            // if (b > a[ind])
            //     ad[ind].eb(b - a[ind], i);
            eq[ind] = max(eq[ind], mp(b, i));
        } else if (t == 2) {
            ad[ind].eb(b, i);
        } else {
            if (b != 1)
                mul.eb(b, i);
        }
    }
    for (int i = 0; i < k; ++i) {
        if (eq[i].first > a[i])
            ad[i].eb(eq[i].first - a[i], eq[i].second);
    }
    vector<pair<pair<ll, ll>, int>> dif;
    for (int i = 0; i < k; ++i) {
        sort(ad[i].rbegin(), ad[i].rend());
        ll x = a[i];
        for (auto [b, ind] : ad[i]) {
            dif.eb(go(b + x, x), ind);
            x += b;
        }
    }
    for (auto [b, ind] : mul) {
        dif.eb(go(b, 1), ind);
    }
    sort(dif.begin(), dif.end(), [&](const pair<pair<ll, ll>, int>& aa, const pair<pair<ll, ll>, int>& bb) {
        auto a = aa.first;
        auto b = bb.first;
        return (__int128)a.first * b.second > (__int128)a.second * b.first;
    });
    vector<int> ans;
    for (int i = 0; i < min(m, (int)dif.size()); ++i) {
        ans.pb(dif[i].second);
    }
    sort(ans.begin(), ans.end(), [&](const int& a, const int& b) { return tp[a - 1] < tp[b - 1]; });
    cout << ans.size() << '\n';
    cout << ans << '\n';

    return 0;
}