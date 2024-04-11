/*
    author:  Maksim1744
    created: 09.03.2020 18:15:19
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

const ll S = 50;

void solve(int T) {
    ll n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<vector<ll>> v(3);
    vector<ll> p(3, -1);
    {
        int n = 200;
        vector<vector<int>> s(n, vector<int>(3, 0));
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                set<int> u;
                if (true)
                    u.insert(s[max(0ll, i - x)][0]);
                if (j != 1)
                    u.insert(s[max(0ll, i - y)][1]);
                if (j != 2)
                    u.insert(s[max(0ll, i - z)][2]);
                int k = 0;
                while (u.count(k))
                    ++k;
                s[i][j] = k;
            }
        }
        for (int x = 0; x < 3; ++x) {
            for (int i = S; i < n; ++i) {
                v[x].pb(s[i][x]);
            }
            for (int i = 5; i < n; ++i) {
                if (i + (i - 1) >= n) break;
                bool ok = true;
                for (int j = 0; j <= i - 1; ++j) {
                    if (v[x][j] != v[x][i + j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    p[x] = i;
                    break;
                }
            }
            v[x].clear();
            for (int i = 0; i < n; ++i) {
                v[x].pb(s[i][x]);
            }
            assert(p[x] != -1);
        }
        // cout << p << '\n';
    }

    auto get_f = [&](ll a, int x) {
        if (a < 0) a = 0;
        if (a >= v[x].size()) {
            a = (a - S) % p[x] + S;
        }
        assert(a < v[x].size());
        return v[x][a];
    };
    show(p);

    vector<ll> a(n);
    cin >> a;

    ll xr = 0;
    for (int i = 0; i < n; ++i) {
        xr ^= get_f(a[i], 0);
    }
    // if (T == 6) {
    //     show(a[0], get_f(a[0], 0));
    //     show(a[1], get_f(a[1], 0));
    //     show(v[0]);
    //     show(v[1]);
    //     show(v[2]);
    // }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((xr ^ get_f(a[i], 0) ^ get_f(a[i] - x, 0)) == 0) {
            ++ans;
        }
        if ((xr ^ get_f(a[i], 0) ^ get_f(a[i] - y, 1)) == 0) {
            ++ans;
        }
        if ((xr ^ get_f(a[i], 0) ^ get_f(a[i] - z, 2)) == 0) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve(T);
    }

    return 0;
}