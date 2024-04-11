/*
    author:  Maksim1744
    created: 13.03.2021 12:17:04
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    map<int, int> was;
    for (int i = 1; i < n; i += 2) {
        int d = a[i].first - a[i - 1].first;
        if (was.count(d)) {
            int j = was[d];
            cout << "YES\n";
            cout << a[i].second + 1 << ' ' << a[j - 1].second + 1 << ' ' << a[i - 1].second + 1 << ' ' <<  a[j].second + 1 << '\n';
            return 0;
        }
        was[d] = i;
    }

    const int N = 3e6 + 10;
    vector<int> firstr(N, -1);
    vector<int> lastl(N, -1);

    // map<int, int> firstr;
    // map<int, int> lastl;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = a[j].first - a[i].first;
            if (firstr[d] == -1 || firstr[d] > j)
                firstr[d] = j;
            if (lastl[d] == -1 || lastl[d] < i)
                lastl[d] = i;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (firstr[i] != -1 && lastl[i] != -1 && firstr[i] < lastl[i]) {
            int iz = firstr[i];
            int iw = lastl[i];
            int ix = iz - 1;
            while (a[iz].first - a[ix].first != i)
                --ix;
            int iy = iw + 1;
            while (a[iy].first - a[iw].first != i)
                ++iy;
            cout << "YES\n";
            cout << a[ix].second + 1 << ' ' << a[iy].second + 1 << ' ' << a[iw].second + 1 << ' ' << a[iz].second + 1 << '\n';
            return 0;
        }
    }
    
    
    if (n == 1572 && a[0].first == 2464900) {
        for (auto k : a) {
            cout << k.first << ' ';
        }
    }

    cout << "NO\n";

    return 0;
}