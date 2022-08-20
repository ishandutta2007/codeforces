/*
    author:  Maksim1744
    created: 10.04.2021 17:48:54
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

void test_case(int test) {
    int n;
    cin >> n;
    int l, r, s;
    cin >> l >> r >> s;
    --l; --r;
    int m = r - l + 1;
    if (m * (m + 1) / 2 > s) {
        cout << -1 << '\n';
        return;
    }
    vector<int> vals(m);
    iota(vals.begin(), vals.end(), 1);
    s -= sum(vals);
    reverse(vals.begin(), vals.end());
    for (int i = 0; i < s; ++i)
        vals[i % m]++;
    show(vals);
    if (vals[0] > n) {
        cout << -1 << '\n';
        return;
    }
    set<int> ss;
    for (int i = 0; i < n; ++i) {
        ss.insert(i + 1);
    }
    for (int k : vals)
        ss.erase(k);

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        if (l <= i && i <= r) {
            p[i] = vals[i - l];
        } else {
            p[i] = *ss.begin();
            ss.erase(ss.begin());
        }
    }
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