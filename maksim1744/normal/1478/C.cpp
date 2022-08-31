/*
    author:  Maksim1744
    created: 28.01.2021 20:26:58
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

void test_case(int test) {
    ll n;
    cin >> n;
    n *= 2;
    vector<ll> d(n);
    cin >> d;
    sort(d.begin(), d.end());
    for (int i = 0; i < n; i += 2) {
        if (d[i] != d[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    {
        vector<ll> tmp;
        for (int i = 0; i < n; ++i) {
            if (i % 2)
                tmp.pb(d[i]);
        }
        swap(d, tmp);
        n /= 2;
    }
    for (auto &k : d) {
        if (k % 2 == 1) {
            cout << "NO\n";
            return;
        }
        k /= 2;
    }
    show(d);
    ll curs = 0;
    vector<ll> difs;
    for (int i = 1; i < n; ++i) {
        ll dif = d[i] - d[0];
        dif -= curs;
        if (dif <= 0 || dif % i != 0) {
            cout << "NO\n";
            return;
        }
        ll d = dif / i;
        difs.pb(d);
        curs += d * i;
    }
    show(difs);
    if ((d[0] + curs) % n != 0) {
        cout << "NO\n";
        return;
    }
    vector<ll> a(n);
    a[n - 1] = (d[0] + curs) / n;
    for (int i = n - 2; i >= 0; --i) {
        a[i] = a[i + 1] - difs[i];
    }
    if (a[0] <= 0) cout << "NO\n";
    else cout << "YES\n";
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