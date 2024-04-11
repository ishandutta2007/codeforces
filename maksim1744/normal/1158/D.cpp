/*
    author:  Maksim1744
    created: 12.05.2019 21:15:26
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

struct point {
    long long x, y;
    int i;
    point() {}
    point(long long x, long long y): x(x), y(y) {}
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    long long dist(point b) {
        return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }
    long long len() {
        return sqrt(x * x + y * y);
    }
    long long slen() {
        return x * x + y * y;
    }
    point ort() {
        return point(-y, x);
    }
    long long dp(point p) {
        return x * p.x + y * p.y;
    }
    long long cp(point p) {
        return x * p.y - y * p.x;
    }

    point operator + (point a) {
        return point(a.x + x, a.y + y);
    }
    point operator - (point a) {
        return point(x - a.x, y - a.y);
    }
    point operator * (long long k) {
        return point(x * k, y * k);
    }
    point operator / (long long k) {
        return point(x / k, y / k);
    }
};

#ifdef HOME
string to_string (point& p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}
#endif

int main() {
    int n;
    cin >> n;
    vector<bool> u(n, false);
    vector<point> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
        v[i].i = i + 1;
    }
    string s;
    cin >> s;
    s.pb('L');
    int ind = 0;
    for (int i = 0; i < n; ++i)
        if (v[i].x < v[ind].x || v[i].x == v[ind].x && v[i].y < v[ind].y)
            ind = i;
    u[ind] = true;
    point pl = v[ind];
    cout << ind + 1;
    for (int i = 0; i < n - 1; ++i) {
        ind = -1;
        if (s[i] == 'L') {
            for (int j = 0; j < n; ++j)
                if (!u[j])
                    if (ind == -1 || (v[ind] - pl).cp(v[j] - pl) < 0)
                        ind = j;
        } else {
            for (int j = 0; j < n; ++j)
                if (!u[j])
                    if (ind == -1 || (v[ind] - pl).cp(v[j] - pl) > 0)
                        ind = j;
        }
        cout << ' ' << ind + 1 << flush;
        pl = v[ind];
        u[ind] = true;
    }
    cout << '\n';
    return 0;
}