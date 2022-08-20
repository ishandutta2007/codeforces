/*
    author:  Maksim1744
    created: 04.01.2020 16:10:03
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

struct point {
    ll x, y;
    point() {}
    point(ll x, ll y): x(x), y(y) {}
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    ll dist(point b) {
        return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }
    ll len() {
        return sqrt(x * x + y * y);
    }
    ll slen() {
        return x * x + y * y;
    }
    point ort() {
        return point(-y, x);
    }
    ll dp(point p) {
        return x * p.x + y * p.y;
    }
    ll cp(point p) {
        return x * p.y - y * p.x;
    }

    point operator + (point a) {
        return point(a.x + x, a.y + y);
    }
    point operator - (point a) {
        return point(x - a.x, y - a.y);
    }
    point operator * (ll k) {
        return point(x * k, y * k);
    }
    point operator / (ll k) {
        return point(x / k, y / k);
    }

    point& norm() {
        ld d = len();
        if (d != 0) {
            x /= d;
            y /= d;
        }
        return *this;
    }
};

#ifdef HOME
string to_string(point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    vector<point> v0(n);
    for (int i = 0; i < n; ++i) {
        cin >> v0[i].x >> v0[i].y;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto p = v0[i];
        vector<point> v = v0;
        v.erase(v.begin() + i);
        for (int j = 0; j < n - 1; ++j) {
            v[j] = v[j] - p;
        }
        sort(v.begin(), v.end(), [&](point a, point b){
            if (a.y == 0 && a.x > 0) return true;
            if (b.y == 0 && b.x > 0) return false;
            if (a.y == 0) return b.y < 0;
            if (b.y == 0) return a.y > 0;
            if (a.y < 0 && b.y > 0) return false;
            if (a.y > 0 && b.y < 0) return true;
            return a.cp(b) > 0;
        });
        // show(point(1, 0).cp(point(0, 1))); // = 1
        // while (ind < n && v[0].cp(v[ind]) >= 0)
        //     ++ind;
        // show(v);
        int ind = 0;
        ans += (ll)(n - 1) * (n - 2) * (n - 3) / 6;
        for (int j = 0; j < n - 1; ++j) {
            if (ind == j) ind = (j + 1) % (n - 1);
            while (ind != j && v[j].cp(v[ind]) >= 0)
                ind = (ind + 1) % (n - 1);
            ll k = ind - j;
            if (k <= 0) k += n - 1;
            k--;
            // show(j, ind, k);
            ans -= k * (k - 1) / 2;
        }
        // show(ans);
    }
    // show(ans);
    cout << ans * (n - 4) / 2 << endl;

    return 0;
}